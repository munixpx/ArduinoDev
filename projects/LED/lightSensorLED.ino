
const int LED = 9;
const int SENSOR = 0;

int sensorRead = 0;
float sensorVal = 0.0;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  sensorRead = analogRead(SENSOR);
  sensorRead -= 300;
  sensorVal = sensorRead/724.0;
  sensorVal = 1 - sensorVal;
  sensorVal *= 255;
  Serial.println(sensorVal);
  analogWrite(LED, sensorVal);
}