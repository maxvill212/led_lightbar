<p align="center"><img src="Pictures/Arduino_Logo.png" width="150"></p>

# LED bar

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

## Setup
* Wiring the circuit. Diagram can be found [here](Pictures/CircuitDiagram.png)
* Uploading the program to the Arduino
* Finding the high beam power wire and connecting the Arduino to it


## TODO
* Improve circuit diagram readability
* List all the parts of the circuit
* **Make program event driven**

## WARNING
If you are not comfortable with circuits and electricity safety (and basic car electronic safety), then do not do this project as things can go very wrong very fast.