#include <SoftwareSerial.h>
 
const int rx=3;
const int tx=4;
 
SoftwareSerial mySerial(rx, tx);
 
void setup() { 
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);
  mySerial.begin(9600);
} 
 
void loop() {
 
  mySerial.print("T0");// non printl!!!
  delay(1000);
  mySerial.println();// passo alla riga successiva
  mySerial.print("T1");//come sopra!!!
  delay(1000);
  mySerial.println();// passo alla riga successiva
}
