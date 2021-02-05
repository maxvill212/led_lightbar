/*****************************************************************************************
*                                                                                        *
*       ***************ABOUT***************                                              *
*       This is the program that controls the LED bar of the car. It runs on an          *
*       Arduino Nano v3. There is a 1 second delay when the bar comes on to enable       *
*       flashing people that are on their highbeams without blinding them with the bar.  *
*                                                                                        *
*                                                                                        *
*       *************VARIABLES*************                                              *
*       Integer                                                                          *
*           highBeamPin   -> The pin that outputs a signal to the relay once the         *
*                              Arduino detects the high beams are on                     *
*           relayPin      -> The pin that signals the relay to open or close             *
*           highBeamState -> Variable that reads the state of highBeamPin                *
*           lightBarDelay -> Delay for light bar being powered                           *
*       Boolean                                                                          *
*           cycleCheck    -> Checks if the LED bar is turning on or was already on       *
*                            during another Arduino cycle                                *
*                                                                                        *
*****************************************************************************************/

// Variable Declaration
int highBeamPin = 3, relayPin = 5, highBeamState, lightBarDelay = 1500;
bool cycleCheck = false;

// Inital Arduino setup (only runs once)
void setup(){
  pinMode(relayPin, OUTPUT);   // Set pin as output pin
  pinMode(highBeamPin, INPUT); // Set pin as input pin
}

// Program that runs continuously while the Arduino has power
void loop(){
  highBeamState = digitalRead(highBeamPin);  // Check if high beams are on/off

  if (highBeamState == 1){                   // If high beams are on
    if (!cycleCheck){                        // If high beams have just been turned on (first cycle)
      delay(lightBarDelay);                  // Delay for flashing oncoming traffic
      digitalWrite(relayPin, HIGH);          // Turn on LED relay
      cycleCheck = true;
    }
  } else {                                   // High beams have been turned off
    digitalWrite(relayPin, LOW);
    cycleCheck = false;                      // Enable delay when high beams are turned on
  }
}