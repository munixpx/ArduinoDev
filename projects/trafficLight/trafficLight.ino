#define ARedLED 12
#define AYellowLED 11
#define AGreenLED 10

#define BRedLED 2
#define BYellowLED 1
#define BGreenLED 0

#define ABUTTON 13
#define BBUTTON 7

#define yellowBlinkTime 500

boolean trafficA = true;
int flowTime = 2000;
int changeDelay = 1000;

void setup()
{
  pinMode( ARedLED, OUTPUT );
  pinMode( AYellowLED, OUTPUT );
  pinMode( AGreenLED, OUTPUT );

  pinMode( BRedLED, OUTPUT );
  pinMode( BYellowLED, OUTPUT );
  pinMode( BGreenLED, OUTPUT );
  
  pinMode( ABUTTON, INPUT );
  pinMode( BBUTTON, INPUT );
  
  //initial status
  digitalWrite( ARedLED, LOW );
  digitalWrite( BYellowLED, LOW );
  digitalWrite( AGreenLED, HIGH);  
  
  digitalWrite( BRedLED, HIGH );
  digitalWrite( BYellowLED, LOW );
  digitalWrite( BGreenLED, LOW);
}

void loop()
{
  if( digitalRead( ABUTTON ) == HIGH )
  {
    if( trafficA != true )
    {
      trafficA = true;
      
      delay( flowTime );
      digitalWrite( BGreenLED, LOW );
      digitalWrite( BYellowLED, HIGH );
      delay( changeDelay );
      digitalWrite( BYellowLED, LOW );
      digitalWrite( BRedLED, HIGH );

      delay( changeDelay );      
      digitalWrite( ARedLED, LOW );
      digitalWrite( AYellowLED, HIGH );
      delay( changeDelay );
      digitalWrite( AYellowLED, LOW );
      digitalWrite( AGreenLED, HIGH );
    }
  }
  if( digitalRead( BBUTTON ) == HIGH )
  {
    if( trafficA == true )
      {
        trafficA = false;
        
        delay( flowTime );
        digitalWrite( AGreenLED, LOW );
        digitalWrite( AYellowLED, HIGH );
        delay( changeDelay );
        digitalWrite( AYellowLED, LOW );
        digitalWrite( ARedLED, HIGH );
  
        delay( changeDelay );      
        digitalWrite( BRedLED, LOW );
        digitalWrite( BYellowLED, HIGH );
        delay( changeDelay );
        digitalWrite( BYellowLED, LOW );
        digitalWrite( BGreenLED, HIGH );
      }
  }    
}
