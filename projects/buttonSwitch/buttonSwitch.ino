const int LED = 13;
const int BUTTON = 7;
bool buttonPressed = 0;
bool ledStatus = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  digitalWrite(BUTTON, HIGH);
}

void loop() {
  buttonPressed = digitalRead(BUTTON);
  Serial.println(buttonPressed);
  if (!buttonPressed){
    ledStatus = !ledStatus;
    delay(250);
    }
  if (ledStatus){
    digitalWrite(LED, HIGH);
  }else
    digitalWrite(LED, LOW);
}
