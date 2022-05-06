# Lab Notebook

## 2/7/2022
Met to work on project proposal. Discusses planning for the project and put together a rough draft to show to and discuss with TA on 2/8.

## 2/10/2022
Met on discord to finish project proposal. Created 3D computer model of design rough draft. Made better block diagram. 

##2/15/2022
Worked on PCB design

##2/19/2022
Worked on PCB design

##2/25/2022
Worked on PCB design

##3/7/2022
Worked on PCB design, made sure it passed audit on PCBway, sent to Amr

##3/12/2022
Researched web application

##3/20/2022
Researched web application

##3/23/2022
Talked with machine shop

##3/25/2022
Researched web application, decided to switch to phone application

##/3/26/2022
Researched and tested wifi module

##3/27/2022
Researched and tested wifi module

##3/28/2022
Tested wifi module. Got it set up

##3/30/2022
Finished individual progresss report

##4/5/2022
Worked on phone application. Got Blynk figured out

##4/7/2022
Worked on phone application. Got it working with blinking a light on a breadboard remotely

##4/8/2022
Got phone application to display graphs. Got it working with reading voltage from power supply.

##4/18/2022
Microcontroller arrived, began testing.

##4/19/2022
Began testing programming the microcontroller. We plugged the programmer of the microcontroller and the power supply for the PCB in at the same time and ended up sending 10 Volts across the microcontroller. This ended up destroying the microcontroller. We decided to test the code for the wifi module instead and planned on desoldering another microcontroller off an arduino board we would acquire from the supply center.

##4/20/2022
Voltage regulators broke. Bought new ones from supply center. PCB was busted from regulator burning out and we weren't sure if our circuit was right so we moved it to a breadboard. They didn't have a 3.3 volt regulator so we made a voltage divider. Got it working

##4/21/2022
New power monitor chip arrived and programmer for microcontroller. We tried but couldn't figure out programming the microcontroller, so we decided to switch to an arduino redboard for our final design. 

##4/22/2022
We recieved the solar panel from the machine shop today, it included a rotating base with the solar panel on an arm that allowed it to tilt as needed.  When testing the functionality of the motors with the solar panel the rotation motor was able to rotate the entire design but the tilt motor was not able to.  We tested the tilt motor at maximum rated power and it was still unable to move the panel.  We thought it was because the solar panel with the frame built by the machine shop was heavier than expected.

##4/23/2022
Even though we decided to switch to using the RedBoard as our primary microcontroller, we still needed to use the PCB for our motor driver and our power monitor chip.  So we decided to desolder everything on the PCB and resolder the parts onto another copy of our PCB.  To get the signals from where the microcontroller would have been, Tyler soldered wires on the pads where the microcontroller would have been on the PCB.

##4/24/2022
Now that we had everything soldered onto another PCB, we began testing the logic with the motor driver.  When we tried using the motor driver to turn the motors, the motors weren't moving.  When we connected the motors directly to power, they were turning.  We believed the issue was that the power supply wasn't producing the current required to turn the motors.

##4/25/2022 - 4/26/2022 (all nighter)
We couldn't get the motor driver to work. We found out that one of the pins that we attacehd to ground on our PCB actually needed to be set to high, so we were always getting high signals on the positive and negative to the motor, causing them not to turn despite getting power, because they needed on high and one low to decide which direction to go. However when we tried desoldering it and fixing it with a wire manually setting it to high we ended up frying it. We decided that we would just have to use the redboard to program it. We were working on our project all night before the demo and manage to get it working on the horizontal mostly. The app worked as well.

##5/1/2022
Worked on presentation.

##5/2/2022
We recorded a video to demo our project for our presentation and worked on the presentation.







