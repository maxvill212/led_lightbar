/******************************************************************************************
*                                                                                         *
*       ***************ABOUT***************                                               *
*       This is the program that controls the LED bar mounted to the car. It runs on an   *
*       Arduino Nano v3. There is a 1 second delay when the bar comes on to enable        *
*       flashing people that are on their highbeams without blinding them with the bar.   *
*                                                                                         *
*       **************VERSION**************                                               *
*       v3 Patchnotes:                                                                    *
*             - The delay between turning on the high beam and the light bar is now       *
*               working.                                                                  *
*                                                                                         *
*       *************FUNCTIONS*************                                               *
*       setup   -> Arduino inital setup that only runs once                               *
*       loop    -> Arduino main function that loop contuniously while it has power        *
*       buffer  -> Due to the 4M ohm resistance, the Arduino is receiving pulses from     *
*                   the high beam. This function creates a buffer to ensure the light     *
*                   bar remains on when it needs to be                                    *
*                                                                                         *
*       *************VARIABLES*************                                               *
*       Integer                                                                           *
*           highBeamPin         -> The pin that detects if the high beams were turned on  *
*           relayPin            -> The pin that signals the relay to open or close        *
*           highBeamState       -> Variable that reads the state of highBeamPin           *
*           lightBarDelay       -> Delay for light bar being powered                      *
*           bufferTime          -> Delay for buffer()                                     *
*           bufferHighBeamState -> Same as highBeamState but for buffer()                 *
*       Boolean                                                                           *
*           cycleCheck          -> Checks if the LED bar is turning on or was already     *
*                                   on during another Arduino cycle                       *
*       Long                                                                              *
*           prevTime            -> The reference to calculate time                        *
*           currentTime         -> The current time that will reference prevTime to see   *
*                                   how much time has passed                              *
*           bufferPrevTime      -> Same as prevTime but for buffer()                      *
*           bufferCurrentTime   -> Same as currentTime but for buffer()                   *
*                                                                                         *
******************************************************************************************/

// Variable Declaration for loop
const int highBeamPin = 5, relayPin = 7, lightBarDelay = 1000;
const int stateLED = 9;
int highBeamState;
unsigned long prevTime = 0, currentTime = 0;

//Variable Declaration for buffer
const int bufferTime = 100;
int bufferHighBeamState;
unsigned long bufferCurrentTime = 0, bufferPrevTime = 0;

// Inital Arduino setup function
void setup(){
  pinMode(relayPin, OUTPUT);   // Set pin as output pin
  pinMode(highBeamPin, INPUT); // Set pin as input pin
  pinMode(stateLED, OUTPUT);
}

// Runs continuously while the Arduino has power
void loop(){
  highBeamState = digitalRead(highBeamPin);           // Check if high beams are on/off
  currentTime = millis();                             // Update current time for delay functionality

  if (highBeamState == 1){                            // If high beams are on
    digitalWrite(stateLED, HIGH);                     // Troubleshooting LED turns on when high beams are on
    if ((currentTime - prevTime) >= lightBarDelay){   // Checks if the delay requirements has been met
      digitalWrite(relayPin, HIGH);                   // Turn on LED relay circuit
    }
  } else {
    if (buffer()){                                    // Buffer to ensure the high beams were turned off
      digitalWrite(relayPin, LOW);                    // Turn off high beam
      digitalWrite(stateLED, LOW);                    // Turn off troubleshooting LED
    }
    prevTime = currentTime;                           // Set reference point for the delay
  }
}

// Function to ensure the high beam was turned off before turning off light bar
bool buffer(){
  bufferPrevTime = bufferCurrentTime;                        // Get the reference point for buffer time
  while (bufferCurrentTime - bufferPrevTime < bufferTime){   // While the delay has not been reached
    bufferHighBeamState = digitalRead(highBeamPin);          // Update if the Arduino gets a pulse from the highbeam
    if(bufferHighBeamState == 1){                            // Check if the Arduino gets a pulse from the highbeam
      return false;                                          // If at any point the Arduino gets a pulse, return false
    }
    bufferCurrentTime = millis();                            // Update current time
  } return true;                                             // If the Arduino does not receive a pulse, then the lightbar is off
}