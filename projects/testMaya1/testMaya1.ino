#define analogIn 0

void setup()
{
  Serial.begin(9600);
}

int val = 0;
int degrees = 0;
void loop()
{
  val = analogRead( analogIn );
  degrees = map(val, 550, 750, 0, 90);
  Serial.println( degrees );
  delay(100);
}
