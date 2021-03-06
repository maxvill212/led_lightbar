<p align="center"><img src="Pictures/Arduino_Logo.png" width="150"></p>


![Last Commit](https://img.shields.io/github/last-commit/maxvill212/led_lightbar)
![License](https://img.shields.io/github/license/maxvill212/led_lightbar?color=lightgrey)
![Version](https://img.shields.io/github/v/release/maxvill212/led_lightbar)

# LED bar control

## Purpose
Control when the LED light bar on my car turns on and off

## Origin
I added an LED light bar to my car to assist my vision when driving in back country roads at night. The original plan was to simply add the bar to the high beam circuit in parallel, but the car detects a change and prevents the circuit from functioning. Instead of adding a relay and calling it a day, I created a delay with an Arduino nano to prevent the bright light bar from turning on when I am flashing someone.

## Technologies
### Software:
* [Arduino IDE](https://www.arduino.cc/en/software) (Do not get the Windows app version if you plan on using VS Code, as it runs in a sandbox environment that VS Code cannot reach)
* [Visual Studio Code](https://code.visualstudio.com/Download)
* [Arduino Extension](https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.vscode-arduino) for VS Code
### Hardware:
* [Arduino Nano](https://store.arduino.cc/usa/arduino-nano)
* Variety of different electrical components
  * 1 5V relay typically used with Arduino projects
  * 4 1M ohm resistor in series
  * 1 1k ohm resistor
  * 1 transistor typically used with Arduino projects
  * Switch to turn off LED bar even when high beams are on
  * Wires
  * Printed circuit board
## Setup
* Wiring the circuit. Diagram can be found [here](Pictures/Circuit_Diagram.png)
* Uploading the program to the Arduino
* Finding the high beam power wire and connecting the Arduino to it
## WARNING
If you are not comfortable with circuits and electricity safety (and basic car electronic safety), then do not do this project as things can go very wrong very fast. I am not an electrical engineer, just a random dude that bought an LED bar, was bored and decided to challenge myself to add functionality to it.
## TODO
* Make program event driven
## Versions
### v1
* First release of the program
### v1.1
* Introduced a troubleshoot LED to debug when the relay is suppose to be on or not (if the Arduino correctly detected if the high beams are on or off)
### v2
* The way the program checks for the delay has changed. Now it is based on the millis() function. This allows to the loop to continue operating even when it is monitoring the time to delay the relay circuit activation.
* The Arduino circuitry has been completely reworked, as the previous circuit had major design flaws.
### v2.1
* I'm assuming because of the extreme current drop, the Arduino is receiving a slight pulse rather than a constant current when the high beams are on. This means that prevMillis() is often reset before the delay is up, and the light bar never turns on. Other times, the light bar would turn on, but eventually turn off again.
* Pressed for time, this is the version in the car at the moment, there is no delay.
### v3
* The delay between turning on the high beam and the light bar is now working.
