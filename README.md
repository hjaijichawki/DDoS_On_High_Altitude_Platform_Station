# DDoS Attack Simulation on HAPS sytem in OMNeT++

This repository contains a simulation model of a DDoS on High Altitude Platform Station (HAPS). The simulation is built using OMNeT++.

## Project Overview

The project simulates communication between:
- **Aerial HAPS**: A High-Altitude Platform Station.
- **Base Station**: A ground station that sends commands to the HAPS.
- **Attacker**: Simulates a Distributed Denial-of-Service (DDoS) attack on the HAPS network.

The simulation includes modules for:
- Normal communication between Base Station and HAPS.
- Simulating the effect of a DDoS attack from an attacker module.

## Repository Structure

- **Aerial.cc / Aerial.h**: Base aerial class that defines common functionality for aerial entities like HAPS.
- **Aerial_HAPS.cc / Aerial_HAPS.h**: Implementation of the HAPS module.
- **Attacker.cc / Attacker.h**: Implementation of the Attacker module to simulate a DoS attack.
- **Base_Station.cc / Base_Station.h**: Base Station module that interacts with the HAPS from the ground.
- **network.ned**: NED file defining the network structure, including connections between HAPS, Base Station, and Attacker.
- **omnetpp.ini**: Simulation configuration file that controls parameters such as message rates, timing, and attack settings.
- **package.ned**: Defines package-specific settings for the NED files.
- **Simulation**: A folder contains a simulation video of this attack.
- **aerials**: A folder contains the modules images for better simulation on local. 

## Prerequisites

To run this simulation, you'll need:
- [OMNeT++](https://omnetpp.org) (a discrete event simulator).
- Optionally, [INET Framework](https://inet.omnetpp.org) for extended networking functionalities.


## Running the Simulation

1. Open OMNeT++ and import the project.
2. Ensure that OMNeT++ is properly configured, and build the project.

### Running the Simulation

1. Open the project in OMNeT++.
2. Adjust the `omnetpp.ini` file to set your preferred parameters.
3. Run the simulation by choosing the appropriate configuration from `omnetpp.ini`.

### Key Parameters

You can adjust these in `omnetpp.ini`:

- **Message Interval**: Time between messages sent from the Base Station to HAPS.
- **DDoS Attack Timing**: Time when the attacker module initiates the attack.

## Simulation Results

Results are exported to CSV files for post-simulation analysis.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Feel free to fork the repository and submit a pull request for any improvements or bug fixes.

