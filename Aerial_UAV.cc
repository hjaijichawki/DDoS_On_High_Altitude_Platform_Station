#include "Aerial_UAV.h"
#include <fstream>

Define_Module(Aerial_UAV);

void Aerial_UAV::initialize() {
    Aerial::initialize();  // Call base class initialization
    // Additional initialization specific to UAV
    EV << "UAV platform initialized.\n";

    // Schedule a message to be sent every second to HAPS
    messageTimer = new cMessage("sendMessageTimer");
    scheduleAt(simTime(), messageTimer);  // Start sending messages after 1 second
}

void Aerial_UAV::handleMessage(cMessage *msg) {
    if (msg == messageTimer) {
        // Send a normal message to HAPS every second
        cMessage *normalMsg = new cMessage("Control commands");
        send(normalMsg, "out");  // Send the message via the UAV's output gate
        messagesSentList.push_back(1);

        // Schedule the next message to be sent after 1 second
        scheduleAt(simTime()+1, messageTimer);
    } else {
        Aerial::handleMessage(msg);  // Call base class message handler for other types of messages
        EV << "UAV received a message.\n";
    }
}

void Aerial_UAV::finish() {
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
