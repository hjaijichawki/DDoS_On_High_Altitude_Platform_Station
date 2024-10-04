#include "Aerial_HAPS.h"
#include <fstream>

Define_Module(Aerial_HAPS);

void Aerial_HAPS::initialize() {
    Aerial::initialize();  // Call base class initialization
    // Additional initialization specific to HAPS
    EV << "HAPS platform initialized.\n";
    // Register the signals
    receivedMessageSignal = registerSignal("receivedMessage");
    droppedMessageSignal = registerSignal("droppedMessage");
    damagedHapsSignal = registerSignal("damagedHaps");
    //messageRateSignal = registerSignal("messageRate");

    // Initialize variables
    attackStarted = false;
    messageCounter = 0; // Initialize message counter
    maxMessages = 10; // Get max messages from parameters
    messageReception = 0;
    //isDamaged = false; // Initialize isDamaged to false

    // Schedule an event after 5 seconds to simulate DoS attack start
    attackTimer = new cMessage("attackTimer");
    scheduleAt(simTime()+5, attackTimer);  // Attack starts at 5 seconds
}

void Aerial_HAPS::handleMessage(cMessage *msg) {
    if (attackStarted) {
        if (messageCounter < maxMessages) {
            // Count accepted messages during attack
            messageCounter++;
            messagesSentList.push_back(1);

            // Calculate the message rate (messages per second)
            double messageRate = messageCount / simTime().dbl();  // simTime().dbl() gives the current simulation time in seconds

            // Emit the signal with the calculated message rate
            //emit(messageRateSignal, messageRate);

            EV << "HAPS is under DoS attack! Commands from Base Station were ignored.\n";
        } else {
            EV << "HAPS resources were damaged! No further messages will be accepted.\n";
            delete msg;
            return;
        }
        delete msg;
    } else {
        // Before the attack starts, handle messages normally
        if (msg == attackTimer) {
            attackStarted = true;
            EV << "HAPS is now under DoS attack!!!.\n";
            delete attackTimer;
        } else {
            messagesSentList.push_back(1);

            // Calculate the message rate (messages per second)
            double messageRate = messageCount / simTime().dbl();

            // Emit the signal with the calculated message rate
            //emit(messageRateSignal, messageRate);

            EV << "HAPS received a control command from BS.\n";
            Aerial::handleMessage(msg);
        }
    }
}




void Aerial_HAPS::finish() {
    // Open file to write the list data
    std::ofstream file("HAPS_record.csv");

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


