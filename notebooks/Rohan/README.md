# Sun Tracking Solar Panel

## 2/7/2022
 - Met with group over discord
 - Worked on project proposal to show TA 
    - Created first draft of block diagram
    - Discussed high-level requirements of project
    - Discussed requirements of subsystems

## 2/10/2022
 - Finished proposal with group

## 3/7/2022
 - Assisted with designing PCB and ensuring PCB passed audit

## 3/23/2022
 - Met with machine shop to discuss what they will be building for us
 - Got our PCB and our parts from the lab

## 3/24/2022
 - Tested parts and ensured our code Worked

## 3/30/2022
 - Completed and submitted individual progress report

## 4/18/2022
 - Microcontroller arrived today so we were able to begin testing

## 4/19/2022
 - We began testing programming the microcontroller.  We plugged the programmer of the microcontroller and the power supply for the PCB in at the same time and ended up sending 10 Volts across the microcontroller.  This ended up destroying the microcontroller.  We decided to test the code for the wifi module instead and planned on desoldering another microcontroller off an arduino board we would acquire from the supply center.

# 4/20/2022
 - One of our voltage regulators was not working so I went to the ECE supply center and purchased another voltage regulator.  I also purchased Arduino RedBoard.  This board had the same microcontroller on it so we desoldered the microcontroller off of it to use for our PCB.

# 4/21/2022
 - The programmer for our microcontroller arrived and a new power monitor.  We made sure that the settings in the IDE were correct and that each pad on the PCB was getting the proper voltage but we were still getting errors when trying to program the microcontroller.  Because of these issues programming the microcontroller with the programmer so we decided to use another Arduino RedBoard as our main microcontroller.  

# 4/22/2022
 - We recieved the solar panel from the machine shop today, it included a rotating base with the solar panel on an arm that allowed it to tilt as needed.  When testing the functionality of the motors with the solar panel the rotation motor was able to rotate the entire design but the tilt motor was not able to.  We tested the tilt motor at maximum rated power and it was still unable to move the panel.  We thought it was because the solar panel with the frame built by the machine shop was heavier than expected.

# 4/23/2022
 - Even though we decided to switch to using the RedBoard as our primary microcontroller, we still needed to use the PCB for our motor driver and our power monitor chip.  So we decided to desolder everything on the PCB and resolder the parts onto another copy of our PCB.  To get the signals from where the microcontroller would have been, Tyler soldered wires on the pads where the microcontroller would have been on the PCB.

## 4/24/2022
 - Now that we had everything soldered onto another PCB, we began testing the logic with the motor driver.  When we tried using the motor driver to turn the motors, the motors weren't moving.  When we connected the motors directly to power, they were turning.  We believed the issue was that the power supply wasn't producing the current required to turn the motors.

## 4/25/2022
 - While Tyler was working on the motor driver I realized that the reason the motor driver was working properly was because the power saving pin on the motor driver was shorted to ground.  This causes the motor driver to go into power saving mode, which effectively turns the motor driver off.  What we decided on doing was desoldering the motor driver and then resoldering it with electrical tape isolating the power saving pin from the PCB and then manually giving that pin 5 volts.  However, while we were desoldering the motor driver we damaged it and its functionality.  With limited time before our demo we decided to control only the rotation motor directly from the microcontroller as we had decided to scrap the tilt motor functionality.  We also connected the photoresistors to the flaps and were able to read data from the microcontroller.

## 4/26/2022
 - We finished integration of the sun tracking logic and the mobile app logic to run at the same time.  After finally putting each subsystem together, the solar panel could update its horizontal position and output statistics about the photoresistor values and the voltage and current values produced by the solar panel on a live graph.

## 5/2/2022
 - We recorded a video of our sun tracking solar panel working outside for the final presentation.  We also added the ability to manually move the panel using a button from the mobile app.
