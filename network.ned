//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package ddos_attack_on_haps;

//
// TODO auto-generated type
//
network HAPSNetwork
{
    @display("bgb=695,433;bgi=background/terrain,t");
    types:
        simple Aerial_HAPS
        {
            parameters:
                //@signal[messageReception](type=int);  // Signal type, can be int, double, etc.
       			//@statistic[messageReception](messageReception; record=scalar);
                int maxMessages = default(10); // Maximum number of messages to handle during the attack
                //double messageRate;
                @signal[messageRate](type=double);  // Declare the signal as a double for message rate
        		@statistic[messageRate](source=messageRate; record=vector);  // Record the signal as a vector over time
            gates:
                input input_gate;
                input input_gate_1;
                input input_gate_2;
                input input_gate_3;
                output output_gate;



        }

        simple Aerial_UAV
        {
            gates:
                input input_gate;
                output out;
        }

        simple Attacker
        {
            parameters:
                double attackRate @unit(s) = default(0.1s);  // Set default attack rate to 10ms
                //int attackTargetId;  // ID of the HAPS target
                //double attackInterval;  // Interval for sending flooding messages
            gates:
                output out;
        }


    submodules:
        HAPS: Aerial_HAPS {
            @display("i=aerials/HAPS;p=302,92");
        }
        BS: Aerial_UAV {
            @display("i=aerials/BS;p=51,337");
        }
        Attacker1: Attacker {
            @display("i=aerials/attacker;p=651,284");
        }
        Attacker2: Attacker {
            @display("i=aerials/attacker;p=644,189");
        }
        Attacker3: Attacker {
            @display("i=aerials/attacker;p=644,105");
        }
    connections:

        Attacker1.out --> HAPS.input_gate_1;
        Attacker2.out --> HAPS.input_gate_2;
        Attacker3.out --> HAPS.input_gate_3;
        HAPS.output_gate --> BS.input_gate;
        BS.out --> HAPS.input_gate;
}
