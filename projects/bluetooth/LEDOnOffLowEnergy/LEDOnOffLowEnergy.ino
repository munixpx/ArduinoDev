#include <avr/power.h>
#include <avr/sleep.h>

int pinLED = 13;
int pinSwitch = 12;
int tx=1;
int rx=0;
char inSerial[15];


void setup(){
  outputSave();
  
  pinMode(pinLED, OUTPUT);
  pinMode(pinSwitch, OUTPUT);
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);

  Serial.begin(9600);
}

void loop()
{
  delay(500);
  
  // compute the serial input
  if (Serial.available()) {
    int i=0;
    while (Serial.available() > 0) {
       inSerial[i]=Serial.read(); 
       i++;      
     }
     inSerial[i]='\0';
     checkSerialData(inSerial);
  }
  
  Serial.println("work!");
  delay(5000);
  // check if it should go asleep because of time
  Serial.println("Timer: Entering Sleep mode");
  delay(100);     // this delay is needed, the sleep, function will provoke a Serial error otherwise!!
  sleepNow();     // sleep function called here
}

void checkSerialData(char inStr[]){   
  int m=0;
  Serial.println(inStr);
  
  if(!strcmp(inStr,"off")){      //OFF
    digitalWrite(pinSwitch, LOW);
    digitalWrite(pinLED, LOW);
    Serial.println("Light OFF!");
  } 
  if(!strcmp(inStr,"on")){      //ON
    digitalWrite(pinSwitch, HIGH);
    digitalWrite(pinLED, HIGH);
    Serial.println("Light ON!");
  }
  for(m=0;m<15;m++)
    inStr[m]=0;
}

void sleepNow()
{
    /* The 5 different modes are:
     *     SLEEP_MODE_IDLE         -the least power savings 
     *     SLEEP_MODE_ADC
     *     SLEEP_MODE_PWR_SAVE
     *     SLEEP_MODE_STANDBY
     *     SLEEP_MODE_PWR_DOWN     -the most power savings
     *
     *  the power reduction management <avr/power.h>  is described in 
     *  http://www.nongnu.org/avr-libc/user-manual/group__avr__power.html
     */  
     
  set_sleep_mode(SLEEP_MODE_IDLE);   // sleep mode is set here

  sleep_enable();          // enables the sleep bit in the mcucr register
                             // so sleep is possible. just a safety pin 
  
  power_adc_disable();
  power_spi_disable();
  power_timer0_disable();
  power_timer1_disable();
  power_timer2_disable();
  power_twi_disable();
  
  
  sleep_mode();            // here the device is actually put to sleep!!
 
                             // THE PROGRAM CONTINUES FROM HERE AFTER WAKING UP
  sleep_disable();         // first thing after waking from sleep:
                            // disable sleep...

  power_all_enable();
   
}


void outputSave(){
  //Save Power by writing all Digital IO LOW - note that pins just need to be tied one way or another, do not damage devices!
  for (int i = 0; i < 20; i++) {
      pinMode(i, OUTPUT);
  }
}


