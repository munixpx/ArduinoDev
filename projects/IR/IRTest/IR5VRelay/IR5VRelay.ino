#include <IRremote.h>

int RECV_PIN = 11;
int LED = 13;
int RELAY = 7;
bool ledOn = false;
unsigned long onValue = 0xA32AB931;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED, OUTPUT);
  pinMode(RELAY, OUTPUT);
}

void loop()
{
  if (irrecv.decode(&results))
    {
     Serial.println(results.value, HEX);
    
     if (results.value == onValue)
     {
      Serial.println("boom!");
      if(ledOn)
      {
        digitalWrite(LED, LOW);
        digitalWrite(RELAY, LOW);
        ledOn = false;
      }else
      {
        digitalWrite(LED, HIGH);
        digitalWrite(RELAY, HIGH);
        ledOn = true;
      }
        
      delay(100);
     }
     
     irrecv.resume(); // Receive the next value
    }
}
