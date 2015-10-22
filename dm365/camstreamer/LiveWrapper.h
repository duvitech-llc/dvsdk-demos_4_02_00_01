/*
 * LiveWrapper.h
 *
 *  Created on: Oct 21, 2015
 *      Author: gvigelet
 */

#ifndef DM365_CAMSTREAMER_LIVEWRAPPER_H_
#define DM365_CAMSTREAMER_LIVEWRAPPER_H_

#include <liveMedia.hh>
#include <BasicUsageEnvironment.hh>
#include <GroupsockHelper.hh>

class LiveWrapper;

class LiveWrapper {
public:
    static LiveWrapper *createSingleton();

    virtual ~LiveWrapper();
    static LiveWrapper *getInstance(void);
    void play();
    void afterPlaying();
protected:
    LiveWrapper();

private:
    static LiveWrapper *self;
    UsageEnvironment* env;
    H264VideoStreamFramer* videoSource;
    RTPSink* videoSink;
};


#endif /* DM365_CAMSTREAMER_LIVEWRAPPER_H_ */
