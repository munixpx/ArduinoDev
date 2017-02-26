#include <IRremote.h>

int RECV_PIN = 5;
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
  Serial.println("running");
  if (irrecv.decode(&results))
  {
     Serial.println(results.value, HEX);
    
     if (results.value == 0xA90)
     {
      Serial.println("boom!");
      if(ledOn)
      {
        digitalWrite(LED, LOW);
      }else
        digitalWrite(LED, HIGH);
      delay(1000);
     }
     delay(1000);
     
     irrecv.resume(); // Receive the next value
  }
}
