#define redLED 2
#define yellowLED 4
#define greenLED 6

#define analogPlus 0

void setup()
{
  pinMode( redLED, OUTPUT );
  pinMode( yellowLED, OUTPUT );
  pinMode( greenLED, OUTPUT );
}

int analogValue;
float voltage;
void loop()
{
  analogValue = analogRead( analogPlus );
  voltage = analogValue * 0.0048;
  if (voltage >= 1.4)
  {
    digitalWrite( greenLED, HIGH );
    digitalWrite( yellowLED, LOW);
    digitalWrite( redLED, LOW);
  }
  else if(voltage >= 1 )
  {
    digitalWrite( greenLED, LOW );
    digitalWrite( yellowLED, HIGH);
    digitalWrite( redLED, LOW);
  }
  else if(voltage < 1 )
  {
    digitalWrite( greenLED, LOW );
    digitalWrite( yellowLED, LOW);
    digitalWrite( redLED, HIGH);
  }
  
}
