#ifndef BASE_STATION_H
#define BASE_STATION_H

#include "Aerial.h"

class Base_Station : public cSimpleModule {
  private:
    cMessage *messageTimer;  // Timer for scheduling message sending to HAPS
    std::vector<int> messagesSentList;  // List to store message count over time

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;  // For exporting the list at the end
};

#endif  // AERIAL_UAV_H
