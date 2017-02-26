
int pinLED = 10;
int pinButton = 8;

bool buttonStatus;

void setup()  {
  pinMode(pinLED, OUTPUT);
  pinMode(pinButton, INPUT);
  digitalWrite(pinButton, HIGH);
  Serial.begin(9600);
}
 
void loop()
{
  buttonStatus = digitalRead(pinButton);
  if(!buttonStatus)
  {  
    Serial.println("Can it be true?! A serial monitor indeed!");
    digitalWrite(pinLED, HIGH);
  }
  else
    digitalWrite(pinLED, LOW);
}
