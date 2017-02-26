

const unsigned RELAY_PIN = 8;
const unsigned OUTPUT_PIN = 13;
const unsigned BUTTON_PIN = 7;


bool outputStatus = LOW;
bool buttonStatus = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(buttonStatus, INPUT);
  pinMode(OUTPUT_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(BUTTON_PIN, HIGH);
}

void loop() {
  buttonStatus = digitalRead(BUTTON_PIN);
  if (!buttonStatus)
  {
    Serial.println("pressed!");
    outputStatus = !outputStatus;
    digitalWrite(OUTPUT_PIN, outputStatus);
    digitalWrite(RELAY_PIN, outputStatus);
    delay(200);
  }
}
