/*
 * LiveWrapper.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: gvigelet
 */

#include <liveMedia.hh>
#include <BasicUsageEnvironment.hh>
#include <GroupsockHelper.hh>
#include "LiveWrapper.h"

#include "live_api.h"

LiveWrapper *LiveWrapper::self;

LiveWrapper *LiveWrapper::createSingleton() {
    if(self != NULL) {
	fprintf(stderr, "LiveWrapper: Singleton already created, returning NULL\n");
	return NULL;
    }
    return new LiveWrapper();
}

LiveWrapper::LiveWrapper(){
	fprintf(stderr, "LiveWrapper Constructor Called\n");

	// Begin by setting up our usage environment:
	TaskScheduler* scheduler = BasicTaskScheduler::createNew();
	env = BasicUsageEnvironment::createNew(*scheduler);

	// Create 'groupsocks' for RTP and RTCP:
	struct in_addr destinationAddress;
	destinationAddress.s_addr = chooseRandomIPv4SSMAddress(*env);
	// Note: This is a multicast address.  If you wish instead to stream
	// using unicast, then you should use the "testOnDemandRTSPServer"
	// test program - not this test program - as a model.

	const unsigned short rtpPortNum = 18888;
	const unsigned short rtcpPortNum = rtpPortNum+1;
	const unsigned char ttl = 255;

	const Port rtpPort(rtpPortNum);
	const Port rtcpPort(rtcpPortNum);

	Groupsock rtpGroupsock(*env, destinationAddress, rtpPort, ttl);
	rtpGroupsock.multicastSendOnly(); // we're a SSM source
	Groupsock rtcpGroupsock(*env, destinationAddress, rtcpPort, ttl);
	rtcpGroupsock.multicastSendOnly(); // we're a SSM source

	// Create a 'H264 Video RTP' sink from the RTP 'groupsock':
	OutPacketBuffer::maxSize = 100000;
	videoSink = H264VideoRTPSink::createNew(*env, &rtpGroupsock, 96);

	// Create (and start) a 'RTCP instance' for this RTP sink:
	const unsigned estimatedSessionBandwidth = 500; // in kbps; for RTCP b/w share
	const unsigned maxCNAMElen = 100;
	unsigned char CNAME[maxCNAMElen+1];
	gethostname((char*)CNAME, maxCNAMElen);
	CNAME[maxCNAMElen] = '\0'; // just in case
	RTCPInstance* rtcp
	= RTCPInstance::createNew(*env, &rtcpGroupsock,
				estimatedSessionBandwidth, CNAME,
				videoSink, NULL /* we're a server */,
				True /* we're a SSM source */);
	// Note: This starts RTCP running automatically

	RTSPServer* rtspServer = RTSPServer::createNew(*env, 8554);
	if (rtspServer == NULL) {
		*env << "Failed to create RTSP server: " << env->getResultMsg() << "\n";
		exit(1);
	}

	ServerMediaSession* sms
	= ServerMediaSession::createNew(*env, "thermCam", inputFileName,
		   "Session streamed by \"camstreamer\"", True /*SSM*/);

	sms->addSubsession(PassiveServerMediaSubsession::createNew(*videoSink, rtcp));
	rtspServer->addServerMediaSession(sms);

	char* url = rtspServer->rtspURL(sms);
	*env << "Play this stream using the URL \"" << url << "\"\n";
	delete[] url;

	// Start the streaming:
	*env << "Beginning streaming...\n";

	return;
}

LiveWrapper::~LiveWrapper() {
    /*
     * Close all the live555 objects that inherit from Medium.
     * This should handle cleanup properly.
     */
}

void *Live_init(void) {
    LiveWrapper *live = LiveWrapper::createSingleton();
    if(live != NULL) {
	//live->play();
	return live;
    }
    else {
	return NULL;
    }
}



