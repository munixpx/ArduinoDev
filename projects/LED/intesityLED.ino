void setup()
{
  pinMode( 3, OUTPUT );
  pinMode( 5, OUTPUT );
  pinMode( 6, OUTPUT );
  pinMode( 10, OUTPUT );
  pinMode( 11, OUTPUT );
}

int delayTime = 3;
void loop()
{
  for( int i = 0; i < 256; i++ )
  {
    analogWrite( 3, i );
    analogWrite( 5, i );
    analogWrite( 6, i );
    analogWrite( 10, i );
    analogWrite( 11, i );
    delay(delayTime);
  }
  for( int i = 254; i > 0; i-- )
  {
    analogWrite( 3, i );
    analogWrite( 5, i );
    analogWrite( 6, i );
    analogWrite( 10, i );
    analogWrite( 11, i );
    delay(delayTime);
  }
}
