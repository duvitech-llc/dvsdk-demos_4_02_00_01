/*
 * main.c
 *
 * This source file has the main() for the 'encode demo' on DM365 platform
 *
 * Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <strings.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

#include <xdc/std.h>

#include <ti/sdo/ce/trace/gt.h>
#include <ti/sdo/ce/CERuntime.h>

#include <ti/sdo/dmai/Dmai.h>
#include <ti/sdo/dmai/Fifo.h>
#include <ti/sdo/dmai/Pause.h>
#include <ti/sdo/dmai/VideoStd.h>
#include <ti/sdo/dmai/Capture.h>
#include <ti/sdo/dmai/BufferGfx.h>
#include <ti/sdo/dmai/Rendezvous.h>

#include <ti/sdo/fc/rman/rman.h>

#include "video.h"
#include "capture.h"
#include "livestrm.h"
#include "../ctrl.h"
#include "../demo.h"
#include "../ui.h"

/* The levels of initialization */
#define LOGSINITIALIZED         0x1
#define DISPLAYTHREADCREATED    0x20
#define CAPTURETHREADCREATED    0x40
#define LIVETHREADCREATED     	0x80
#define VIDEOTHREADCREATED      0x100

/* Thread priorities */
#define VIDEO_THREAD_PRIORITY   sched_get_priority_max(SCHED_FIFO) - 1

/* Add argument number x of string y */
#define addArg(x, y)                     \
    argv[(x)] = malloc(strlen((y)) + 1); \
    if (argv[(x)] == NULL)               \
        return FAILURE;                  \
    strcpy(argv[(x)++], (y))

typedef struct Args {
    VideoStd_Type  videoStd;
    Char          *videoStdString;
    Capture_Input  videoInput;
    Char          *videoFile;
    Codec         *videoEncoder;
    Int32          imageWidth;
    Int32          imageHeight;
    Int            videoBitRate;
    Char          *videoBitRateString;
    Int            sampleRate;
    Char          *sampleRateString;
    Int            keyboard;
    Int            time;
    Int            osd;
    Bool           previewDisabled;
    Bool           writeDisabled;
} Args;

#define DEFAULT_ARGS \
    { VideoStd_D1_NTSC, "D1 NTSC", Capture_Input_CAMERA, \
      "/tmp/l3cam.264", NULL, 0, 0, -1, NULL, 16000, NULL, \
	  FALSE, FOREVER, FALSE, FALSE, FALSE }

/*
#define DEFAULT_ARGS \
    { VideoStd_SQUARE_NTSC, "VGA", Capture_Input_COMPOSITE, \
      "/tmp/l3cam.264", NULL, 0, 0, -1, NULL, 16000, NULL, \
	  FALSE, FOREVER, FALSE, TRUE, FALSE }
*/
/* Global variable declarations for this application */
GlobalData gbl = GBL_DATA_INIT;

/******************************************************************************
 * getCodec
 ******************************************************************************/
static Codec *getCodec(Char *extension, Codec *codecs)
{
    Codec *codec = NULL;
    Int i, j;

    i = 0;
    while (codecs[i].codecName) {
        j = 0;
        while (codecs[i].fileExtensions[j]) {
            if (strcmp(extension, codecs[i].fileExtensions[j]) == 0) {
                codec = &codecs[i];
            }
            j++;
        }
        i++;
    }

    return codec;
}

/******************************************************************************
 * uiSetup
 ******************************************************************************/
static Void uiSetup(UI_Handle hUI, Args *argsp)
{
    /* Initialize values */
    UI_updateValue(hUI, UI_Value_DemoName, "Encode");
    UI_updateValue(hUI, UI_Value_DisplayType, argsp->videoStdString);

    if (argsp->videoEncoder) {
        UI_updateValue(hUI, UI_Value_VideoCodec, argsp->videoEncoder->uiString);
    }
    else {
        UI_updateValue(hUI, UI_Value_VideoCodec, "N/A");
    }

    UI_updateValue(hUI, UI_Value_SoundCodec, "N/A");


    UI_updateValue(hUI, UI_Value_ImageResolution, "N/A");
    UI_updateValue(hUI, UI_Value_SoundFrequency, "N/A");
}


/******************************************************************************
 * launchInterface
 ******************************************************************************/
static Int launchInterface(Args * argsp)
{
    Char *argv[1000];
    Int i = 0;
    Int pid;

    addArg(i, "./qtInterface");
    addArg(i, "-qws");
    addArg(i, "-d");
    addArg(i, "Encode");

    if (argsp->videoFile) {
        addArg(i, "-v");
        addArg(i, argsp->videoFile);
    }

    if (argsp->videoBitRateString) {
        addArg(i, "-b");
        addArg(i, argsp->videoBitRateString);
    }

    if (argsp->sampleRateString) {
        addArg(i, "-u");
        addArg(i, argsp->sampleRateString);
    }

    if (argsp->previewDisabled) {
        addArg(i, "-w");
    }

    if (argsp->writeDisabled) {
        addArg(i, "-f");
    }

    if (argsp->videoInput) {
        addArg(i, "-I");
        switch (argsp->videoInput) {
            case Capture_Input_COMPOSITE:
                addArg(i, "1");
                break;
            case Capture_Input_SVIDEO:
                addArg(i, "2");
                break;
            case Capture_Input_COMPONENT:
                addArg(i, "3");
                break;
            case Capture_Input_CAMERA:
                addArg(i, "4");
                break;
            default:
                ERR("Invalid video standard\n");
                return FAILURE;
       } 
    }

    /* 
     * Provide Video Standard and set display output
     * based on it. See qtInterface/main.cpp for semantics of numerical
     * arguments used.
     */
    addArg(i, "-y");
    switch(argsp->videoStd) {
        case VideoStd_D1_NTSC:
            addArg(i, "1");
            addArg(i, "-O");
            addArg(i, "1"); /* Composite */
            break;
        case VideoStd_D1_PAL:
            addArg(i, "2");
            addArg(i, "-O");
            addArg(i, "1"); /* Composite */
            break;
        case VideoStd_720P_60:
            addArg(i, "3");
            addArg(i, "-O");
            addArg(i, "3"); /* Component */
            break;
        case VideoStd_1080I_30:
            addArg(i, "5");
            addArg(i, "-O");
            addArg(i, "3"); /* Component */
            break;
        default:
            ERR("Invalid video standard\n");
            return FAILURE;
    }

    pid = fork();
    if (pid == -1) {
        ERR("Could not fork child process.\n");
        return FAILURE;
    }
    else if (pid == 0) {
        if (execv("./qtInterface", argv) == -1) {
            ERR("Could not execute QT Interface\n");
            return FAILURE;
        }
    }

    return SUCCESS;
}

/******************************************************************************
 * main
 ******************************************************************************/
Int main(Int argc, Char *argv[])
{
    Args                args                = DEFAULT_ARGS;
    Uns                 initMask            = 0;
    Int                 status              = EXIT_SUCCESS;
    Pause_Attrs         pAttrs              = Pause_Attrs_DEFAULT;
    Rendezvous_Attrs    rzvAttrs            = Rendezvous_Attrs_DEFAULT;
    Fifo_Attrs          fAttrs              = Fifo_Attrs_DEFAULT;
    UI_Attrs            uiAttrs;
    Rendezvous_Handle   hRendezvousCapStd   = NULL;
    Rendezvous_Handle   hRendezvousInit     = NULL;
    Rendezvous_Handle   hRendezvousWriter   = NULL;
    Rendezvous_Handle   hRendezvousCleanup  = NULL;
    Pause_Handle        hPauseProcess       = NULL;
    UI_Handle           hUI                 = NULL;
    struct sched_param  schedParam;
    pthread_t           captureThread;
    pthread_t           liveThread;
    pthread_t           videoThread;
    CaptureEnv          captureEnv;
    LiveEnv           	liveEnv;
    VideoEnv            videoEnv;
    CtrlEnv             ctrlEnv;
    Int                 numThreads;
    pthread_attr_t      attr;
    Void               *ret;
    Bool                stopped;

    /* Zero out the thread environments */
    Dmai_clear(captureEnv);
    Dmai_clear(liveEnv);  // turn this into my live555 stream thread
    Dmai_clear(videoEnv);
    Dmai_clear(ctrlEnv);

    /* Parse the arguments given to the app and set the app environment */
    args.videoEncoder = getCodec(".264", engine->videoEncoders);
    //args.videoEncoder = getCodec(".mpeg4", engine->videoEncoders);

    printf("Encode demo started.\n");

    /* Launch interface app */
    if (args.osd) {
        if (launchInterface(&args) == FAILURE) {
            exit(EXIT_FAILURE);
        }
    }

    /* Initialize the mutex which protects the global data */
    pthread_mutex_init(&gbl.mutex, NULL);

    /* Set the priority of this whole process to max (requires root) */
    setpriority(PRIO_PROCESS, 0, -20);

    /* Initialize Codec Engine runtime */
    CERuntime_init();

    /* Initialize Davinci Multimedia Application Interface */
    Dmai_init();

    initMask |= LOGSINITIALIZED;

    /* Create the user interface */
    uiAttrs.osd = args.osd;
    uiAttrs.videoStd = args.videoStd;

    hUI = UI_create(&uiAttrs);

    if (hUI == NULL) {
        cleanup(EXIT_FAILURE);
    }
    
    /* Set up the user interface */
    uiSetup(hUI, &args);
    
    /* Create the Pause object */
    hPauseProcess = Pause_create(&pAttrs);

    if (hPauseProcess == NULL) {
        ERR("Failed to create Pause object\n");
        cleanup(EXIT_FAILURE);
    }

    /* Determine the number of threads needing synchronization */
    numThreads = 1;

    if (args.videoFile) {
        numThreads += 3;
    }

    /* Create the objects which synchronizes the thread init and cleanup */
    hRendezvousCapStd  = Rendezvous_create(2, &rzvAttrs);
    hRendezvousInit = Rendezvous_create(numThreads, &rzvAttrs);
    hRendezvousCleanup = Rendezvous_create(numThreads, &rzvAttrs);
    hRendezvousWriter = Rendezvous_create(2, &rzvAttrs);

    if (hRendezvousCapStd  == NULL || hRendezvousInit == NULL || 
        hRendezvousCleanup == NULL || hRendezvousWriter == NULL) {
        ERR("Failed to create Rendezvous objects\n");
        cleanup(EXIT_FAILURE);
    }

    /* Initialize the thread attributes */
    if (pthread_attr_init(&attr)) {
        ERR("Failed to initialize thread attrs\n");
        cleanup(EXIT_FAILURE);
    }

    /* Force the thread to use custom scheduling attributes */
    if (pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED)) {
        ERR("Failed to set schedule inheritance attribute\n");
        cleanup(EXIT_FAILURE);
    }

    /* Set the thread to be fifo real time scheduled */
    if (pthread_attr_setschedpolicy(&attr, SCHED_FIFO)) {
        ERR("Failed to set FIFO scheduling policy\n");
        cleanup(EXIT_FAILURE);
    }

    /* Create the video threads if a file name is supplied */
    if (args.videoFile) {
        /* Create the capture fifos */
        captureEnv.hInFifo = Fifo_create(&fAttrs);
        captureEnv.hOutFifo = Fifo_create(&fAttrs);

        if (captureEnv.hInFifo == NULL || captureEnv.hOutFifo == NULL) {
            ERR("Failed to open display fifos\n");
            cleanup(EXIT_FAILURE);
        }

        /* Create the capture thread */
        captureEnv.hRendezvousInit    = hRendezvousInit;
        captureEnv.hRendezvousCapStd  = hRendezvousCapStd;
        captureEnv.hRendezvousCleanup = hRendezvousCleanup;
        captureEnv.hPauseProcess      = hPauseProcess;
        captureEnv.videoStd           = args.videoStd;
        captureEnv.videoInput         = args.videoInput;
        captureEnv.imageWidth         = args.imageWidth;
        captureEnv.imageHeight        = args.imageHeight;
        captureEnv.previewDisabled    = args.previewDisabled;

        if (pthread_create(&captureThread, NULL, captureThrFxn, &captureEnv)) {
            ERR("Failed to create capture thread\n");
            cleanup(EXIT_FAILURE);
        }

        initMask |= CAPTURETHREADCREATED;

        /*
         * Once the capture thread has detected the video standard, make it
         * available to other threads. The capture thread will set the
         * resolution of the buffer to encode in the environment (derived
         * from the video standard if the user hasn't passed a resolution).
         */
        Rendezvous_meet(hRendezvousCapStd);

        /* Create the writer fifos */
        liveEnv.hInFifo = Fifo_create(&fAttrs);
        liveEnv.hOutFifo = Fifo_create(&fAttrs);

        if (liveEnv.hInFifo == NULL || liveEnv.hOutFifo == NULL) {
            ERR("Failed to open live stream fifos\n");
            cleanup(EXIT_FAILURE);
        }

        /* Set the video thread priority */
        schedParam.sched_priority = VIDEO_THREAD_PRIORITY;
        if (pthread_attr_setschedparam(&attr, &schedParam)) {
            ERR("Failed to set scheduler parameters\n");
            cleanup(EXIT_FAILURE);
        }

        /* Create the video thread */
        videoEnv.hRendezvousInit    = hRendezvousInit;
        videoEnv.hRendezvousCleanup = hRendezvousCleanup;
        videoEnv.hRendezvousWriter  = hRendezvousWriter;
        videoEnv.hPauseProcess      = hPauseProcess;
        videoEnv.hCaptureOutFifo    = captureEnv.hOutFifo;
        videoEnv.hCaptureInFifo     = captureEnv.hInFifo;
        videoEnv.hWriterOutFifo     = liveEnv.hOutFifo;
        videoEnv.hWriterInFifo      = liveEnv.hInFifo;
        videoEnv.videoEncoder       = args.videoEncoder->codecName;
        videoEnv.params             = args.videoEncoder->params;
        videoEnv.dynParams          = args.videoEncoder->dynParams;
        videoEnv.videoBitRate       = args.videoBitRate;
        videoEnv.imageWidth         = captureEnv.imageWidth;
        videoEnv.imageHeight        = captureEnv.imageHeight;
        videoEnv.engineName         = engine->engineName;
        if (args.videoStd == VideoStd_D1_PAL) {
            videoEnv.videoFrameRate     = 25000;
        } else {
            videoEnv.videoFrameRate     = 30000;
        }

        if (pthread_create(&videoThread, &attr, videoThrFxn, &videoEnv)) {
            ERR("Failed to create video thread\n");
            cleanup(EXIT_FAILURE);
        }

        initMask |= VIDEOTHREADCREATED;

        /*
         * Wait for the codec to be created in the video thread before
         * launching the writer thread (otherwise we don't know which size
         * of buffers to use).
         */
        Rendezvous_meet(hRendezvousWriter);

        /* Create the writer thread */
        liveEnv.hRendezvousInit    = hRendezvousInit;
        liveEnv.hRendezvousCleanup = hRendezvousCleanup;
        liveEnv.hPauseProcess      = hPauseProcess;
        liveEnv.videoFile          = args.videoFile;
        liveEnv.outBufSize         = videoEnv.outBufSize;
        liveEnv.streamDisabled      = args.writeDisabled;

        if (pthread_create(&liveThread, NULL, livestrmThrFxn, &liveEnv)) {
            ERR("Failed to create live thread\n");
            cleanup(EXIT_FAILURE);
        }

        initMask |= LIVETHREADCREATED;

    }


    /* Main thread becomes the control thread */
    ctrlEnv.hRendezvousInit    = hRendezvousInit;
    ctrlEnv.hRendezvousCleanup = hRendezvousCleanup;
    ctrlEnv.hPauseProcess      = hPauseProcess;
    ctrlEnv.keyboard           = args.keyboard;
    ctrlEnv.time               = args.time;
    ctrlEnv.hUI                = hUI;
    ctrlEnv.engineName         = engine->engineName;
    ctrlEnv.osd                = args.osd;

    ret = ctrlThrFxn(&ctrlEnv);

    if (ret == THREAD_FAILURE) {
        status = EXIT_FAILURE;
    }

cleanup:
    if (args.osd) {
        int rv;
        if (hUI) {
            /* Stop the UI */
            UI_stop(hUI);
        }
        wait(&rv);      /* Wait for child process to end */
    }

    /* Make sure the other threads aren't waiting for init to complete */
    if (hRendezvousCapStd) Rendezvous_force(hRendezvousCapStd);
    if (hRendezvousWriter) Rendezvous_force(hRendezvousWriter);
    if (hRendezvousInit) Rendezvous_force(hRendezvousInit);
    if (hPauseProcess) Pause_off(hPauseProcess);

    /* Wait until the other threads terminate */

    if (initMask & VIDEOTHREADCREATED) {
        if (pthread_join(videoThread, &ret) == 0) {
            if (ret == THREAD_FAILURE) {
                status = EXIT_FAILURE;
            }
        }
    }

    if (initMask & LIVETHREADCREATED) {
        if (pthread_join(liveThread, &ret) == 0) {
            if (ret == THREAD_FAILURE) {
                status = EXIT_FAILURE;
            }
        }
    }

    if (liveEnv.hOutFifo) {
        Fifo_delete(liveEnv.hOutFifo);
    }

    if (liveEnv.hInFifo) {
        Fifo_delete(liveEnv.hInFifo);
    }

    if (initMask & CAPTURETHREADCREATED) {
        if (pthread_join(captureThread, &ret) == 0) {
            if (ret == THREAD_FAILURE) {
                status = EXIT_FAILURE;
            }
        }
    }

    if (captureEnv.hOutFifo) {
        Fifo_delete(captureEnv.hOutFifo);
    }

    if (captureEnv.hInFifo) {
        Fifo_delete(captureEnv.hInFifo);
    }

    if (hRendezvousCleanup) {
        Rendezvous_delete(hRendezvousCleanup);
    }

    if (hRendezvousInit) {
        Rendezvous_delete(hRendezvousInit);
    }

    if (hPauseProcess) {
        Pause_delete(hPauseProcess);
    }

    if (hUI) {
        UI_delete(hUI);
    }

    /* 
     * In the past, there were instances where we have seen system memory
     * continually reduces by 28 bytes at a time whenever there are file 
     * reads or file writes. This is for the application to recapture that
     * memory (SDOCM00054899)
     */
    system("sync");
    system("echo 3 > /proc/sys/vm/drop_caches");


    pthread_mutex_destroy(&gbl.mutex);

    exit(status);
}
