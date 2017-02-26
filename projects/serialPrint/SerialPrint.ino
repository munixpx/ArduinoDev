
int val = 0;
int number = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  number = 0;
  Serial.flush();
  Serial.println( "waiting...");
  while( Serial.available() == 0 )
  {
  }
  Serial.println( "portValue : ");
  Serial.println( Serial.available() );
  Serial.print( "you typed : ");
  while( Serial.available() > 0)
  {
    number *= 10;
    val = Serial.read() - '0';
    number += val;
  }
  Serial.println( number );
}
