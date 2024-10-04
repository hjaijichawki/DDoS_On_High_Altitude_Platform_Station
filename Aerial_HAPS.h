#ifndef AERIAL_HAPS_H
#define AERIAL_HAPS_H

#include "Aerial.h"


class Aerial_HAPS : public Aerial {
  private:
    simsignal_t receivedMessageSignal;   // Signal for received messages
    simsignal_t droppedMessageSignal;    // Signal for dropped messages
    simsignal_t damagedHapsSignal;       // Signal when HAPS is damaged
    cMessage *attackTimer;      // Timer for scheduling the start of the DoS attack
    bool attackStarted;         // Flag to indicate if the attack has started
    int messageCounter;         // Counter for the number of messages handled
    int maxMessages;            // Maximum number of messages to handle during the attack
    int messageReception;
    int messageCount;  // Count the accepted messages
    int messageRate;
    std::vector<int> messagesSentList;  // List to store message count over time




  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;  // For exporting the list at the end
};

#endif  // AERIAL_HAPS_H
