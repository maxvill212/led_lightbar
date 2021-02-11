/******************************************************************************************
*                                                                                         *
*       ***************ABOUT***************                                               *
*       This is the program that controls the LED bar of the car. It runs on an           *
*       Arduino Nano v3. There is a 1 second delay when the bar comes on to enable        *
*       flashing people that are on their highbeams without blinding them with the bar.   *
*                                                                                         *
*       **************VERSION**************                                               *
*       v2 Patchnotes:                                                                    *
*             - The way the program checks for the delay has changed. Now it is based     *
*               on the millis() function. This allows to the loop to continue operating   *
*               even when it is monitoring the time to delay the relay circuit activation *
*             - The Arduino circuitry has been completely reworked, as the previous       *
*               circuit had major design flaws.                                           *
*                                                                                         *
*       *************VARIABLES*************                                               *
*       Integer                                                                           *
*           highBeamPin   -> The pin that detects if the high beams were turned on        *
*           relayPin      -> The pin that signals the relay to open or close              *
*           highBeamState -> Variable that reads the state of highBeamPin                 *
*           lightBarDelay -> Delay for light bar being powered                            *
*       Boolean                                                                           *
*           cycleCheck    -> Checks if the LED bar is turning on or was already on        *
*                            during another Arduino cycle                                 *
*                                                                                         *
******************************************************************************************/

// Variable Declaration
const int highBeamPin = 5, relayPin = 3, lightBarDelay = 1000;
int highBeamState;
unsigned long prevMillis = 0, currentMillis = 0;
bool cycleCheck = false;

// Inital Arduino setup (only runs once)
void setup(){
  pinMode(relayPin, OUTPUT);   // Set pin as output pin
  pinMode(highBeamPin, INPUT); // Set pin as input pin
}

// Program that runs continuously while the Arduino has power
void loop(){
  highBeamState = digitalRead(highBeamPin);          // Check if high beams are on/off
  currentMillis = millis();                          // Check current time for delay functionality

  if (highBeamState == 1){                           // If high beams are on
    digitalWrite(LED_BUILTIN, HIGH);                 // Troubleshooting LED turns on when high beams are on
    if (currentMillis - prevMillis >= lightBarDelay) // Checks if the delay requirements has been met
    {
      digitalWrite(relayPin, HIGH);                  // Turn on LED relay circuit
    }
  } else {                                           // High beams are off
    digitalWrite(relayPin, LOW);
    digitalWrite(LED_BUILTIN, LOW);                  // Troubleshooting LED turns off then relay is off
    prevMillis = currentMillis;                      // Set reference point for the delay

  }
}