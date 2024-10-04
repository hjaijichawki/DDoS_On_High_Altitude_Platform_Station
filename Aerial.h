#ifndef __AERIAL_H
#define __AERIAL_H

#include <omnetpp.h>

using namespace omnetpp;

class Aerial : public cSimpleModule {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void commonFunction();
};

#endif // __AERIAL_H
