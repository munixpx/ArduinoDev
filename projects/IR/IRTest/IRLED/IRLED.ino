#include <IRremote.h>

int RECV_PIN = 11;
int LED = 13;
bool ledOn = false;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED, OUTPUT);
}

void loop()
{
  if (irrecv.decode(&results))
    {
     Serial.println(results.value, HEX);
    
     if (results.value == 0xA90)
     {
      Serial.println("boom!");
      if(ledOn)
      {
        digitalWrite(LED, LOW);
        ledOn = false;
      }else
      {
        digitalWrite(LED, HIGH);
        ledOn = true;
      }
        
      delay(100);
     }
     
     irrecv.resume(); // Receive the next value
    }
}
