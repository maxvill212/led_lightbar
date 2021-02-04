int relaySwitch = 3;
int highBeamSignal = 5;
int check;

void setup(){
  pinMode(relaySwitch, OUTPUT);
  pinMode(highBeamSignal, INPUT);
}

void loop(){
  check = digitalRead(highBeamSignal);

  if (check == 1){
    //delay(3000);
    digitalWrite(relaySwitch, HIGH);
  } else {
    digitalWrite(relaySwitch, LOW);
  }
}