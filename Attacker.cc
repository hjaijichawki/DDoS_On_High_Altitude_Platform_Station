#include "Attacker.h"
#include <fstream>

Define_Module(Attacker);

void Attacker::initialize() {
    attackInterval = 0;  // Time interval between flood messages

    // Schedule the first attack 5 seconds after the simulation starts
    sendMsgEvent = new cMessage("sendMsgEvent");
    scheduleAt(simTime() + 5, sendMsgEvent);  // 5 seconds delay for the first attack
}

void Attacker::handleMessage(cMessage *msg) {
    if (msg == sendMsgEvent) {
        // Send a flood of messages through the output gate connected to other modules
        cMessage *attackMsg = new cMessage("DoS Attack");
        send(attackMsg, "out");  // Send via the gate connected to other modules
        messagesSentList.push_back(1);

        // Schedule the next attack after the attackInterval
        scheduleAt(simTime() + attackInterval, sendMsgEvent);
    } else {
        // Handle other types of messages if needed
        delete msg;
    }
}

void Attacker::startAttack() {
    // If sendMsgEvent is not initialized, create it
    if (!sendMsgEvent) {
        sendMsgEvent = new cMessage("sendMsgEvent");
    }

    // Schedule the first attack to happen after 5 seconds if it hasn't started
    if (!sendMsgEvent->isScheduled()) {
        scheduleAt(simTime() + 5, sendMsgEvent);  // 5-second delay for the first attack
    }
}
void Attacker::finish() {
    // Open file to write the list data
    std::ofstream file("Attacker_record.csv");

    // Write headers
    file << "Time,MessagesSent\n";
    simtime_t currentTime = simTime();

    // Write each recorded value along with the simulation time
    for (size_t i = 0; i < messagesSentList.size(); i++) {
        currentTime += 1; // Assuming each entry represents one time unit
        file << currentTime << "," << messagesSentList[i] << "\n";
    }

    file.close();  // Close file
}

