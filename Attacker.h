#ifndef ATTACKER_H
#define ATTACKER_H

#include <omnetpp.h>

using namespace omnetpp;

class Attacker : public cSimpleModule {
  private:
    cMessage *sendMsgEvent;  // Event for scheduling message sending
    int attackTargetId;      // ID of the target (Aerial_HAPS)
    double attackInterval;    // Time interval between flooding messages
    std::vector<int> messagesSentList;  // List to store message count over time

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void startAttack();  // Function to initiate the DoS attack
    virtual void finish() override;  // For exporting the list at the end
};

#endif  // ATTACKER_H
