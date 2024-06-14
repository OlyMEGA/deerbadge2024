Welcome to the repository for the toorCamp2024 PCB badge!
Here, you can find the code and other files to set up your PCB badge.


![deerbadgePcbPrototype](https://github.com/lithiumbot/deerbadge2024/assets/8286697/1b565763-95b4-42a4-a087-8f97a24f3361)

The artwork on this badge is a take on the 'cyberdeer' theme that toorcamp utilizes. Since we are camping in the woods, I felt it appropriate to create a badge that was reminiscent of a horror movie, the image of the deerskull floating over Doe Bay is meant to look like the poster for a slasher movie set at a campground!


This project is a simple electronic die that lights up the 'eyes' of the deer skull.

![deerbadgeSchematicDiagram](https://github.com/lithiumbot/deerbadge2024/assets/8286697/f6445f0c-e078-480d-93d7-99b06fb24856)

You can see in the schematic that it makes use of the limited outputs on the ATtiny85 by taking advantage of the fact that most of the LEDs light in pairs to create the dice patterns. There are extra pads on the input pin so that other types of normally open switches can be added.




![2024-06-14 16 15 44](https://github.com/lithiumbot/deerbadge2024/assets/8286697/4b8e2378-93ea-48e3-92b4-7773ec31a102)

Come to the Hardware Hacking Stage during the scheduled build times to get the parts for your badge, and to make use of our soldering stations. OlyMEGA camp volunteers will be available to help you with soldering and badge assembly. https://talks.toorcon.net/toorcamp-2024/schedule/

![layoutdeerbadge](https://github.com/lithiumbot/deerbadge2024/assets/8286697/c20d25a4-8395-4a40-9a82-373c69d374ce)

The parts you will need:

R1: 10k ohm 1/4 watt resistor (Brown, Black, Orange, Gold)<br>
R2: 100 ohm 1/4 watt resistor (Brown, Black, Brown, Gold)<br>
U1: 8 pin DIP socket and an ATTINY85 Atmel microcontroller<br>
D1-D7: 7x 3mm LEDs<br>
SW1: a 4-leg tactile switch<br>
SW2: unused (but maybe someone at camp will have something that fits there...)






need to add link to ATtiny85 programming
