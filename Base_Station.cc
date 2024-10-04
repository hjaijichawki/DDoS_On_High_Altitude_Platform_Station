#include <fstream>
#include "Base_Station.h"

Define_Module(Base_Station);

void Base_Station::initialize() {
    // Additional initialization specific to UAV
    EV << "UAV platform initialized.\n";

    // Schedule a message to be sent every second to HAPS
    messageTimer = new cMessage("sendMessageTimer");
    scheduleAt(simTime(), messageTimer);  // Start sending messages after 1 second
}

void Base_Station::handleMessage(cMessage *msg) {
    if (msg == messageTimer) {
        // Send a normal message to HAPS every second
        cMessage *normalMsg = new cMessage("Control commands");
        send(normalMsg, "out");  // Send the message via the UAV's output gate
        messagesSentList.push_back(1);

        // Schedule the next message to be sent after 1 second
        scheduleAt(simTime()+1, messageTimer);
    } else {
        EV << "Aerial platform received a message.\n";
        delete msg;
        EV << "UAV received a message.\n";
    }
}


void Base_Station::finish() {
    // Open file to write the list data
    std::ofstream file("UAV_record.csv");

    // Write headers
    file << "Time,MessagesSent\n";
    simtime_t currentTime = 0;

    // Write each recorded value along with the simulation time
    for (size_t i = 0; i < messagesSentList.size(); i++) {
        currentTime += 1; // Assuming each entry represents one time unit
        file << currentTime << "," << messagesSentList[i] << "\n";
    }

    file.close();  // Close file
}
