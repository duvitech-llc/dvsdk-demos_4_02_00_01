/*
 * livestrm.h
 *
 *  Created on: Oct 21, 2015
 *      Author: gvigelet
 */

#ifndef DM365_CAMSTREAMER_LIVESTRM_H_
#define DM365_CAMSTREAMER_LIVESTRM_H_


#include <xdc/std.h>

#include <ti/sdo/dmai/Fifo.h>
#include <ti/sdo/dmai/Pause.h>
#include <ti/sdo/dmai/Rendezvous.h>

/* Environment passed when creating the thread */
typedef struct LiveEnv {
    Rendezvous_Handle hRendezvousInit;
    Rendezvous_Handle hRendezvousCleanup;
    Pause_Handle      hPauseProcess;
    Fifo_Handle       hOutFifo;
    Fifo_Handle       hInFifo;
    Char             *videoFile;
    Int32             outBufSize;
    Bool              streamDisabled;
} LiveEnv;

/* Thread function prototype */
extern Void *livestrmThrFxn(Void *arg);


#endif /* DM365_CAMSTREAMER_LIVESTRM_H_ */
