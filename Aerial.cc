#include "Aerial.h"



Define_Module(Aerial);

void Aerial::initialize() {
    EV << "Aerial platform initialized.\n";
}

void Aerial::handleMessage(cMessage *msg) {
    EV << "Aerial platform received a message.\n";
    delete msg;
}

void Aerial::commonFunction() {
    EV << "Common aerial functionality.\n";
}

  // namespace mynamespace
