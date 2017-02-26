#include <SoftwareSerial.h>

const int rx=3;
const int tx=4;

SoftwareSerial mySerial(rx, tx);

void setup() { 
  mySerial.begin(9600);
} 

void loop() {
  for (int i = 0; i < 10; i++) {
    mySerial.println(i);
  }
}

/* UPLOAD THIS TO THE ARDUINO
char ch;
int i;

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (Serial.available() > 0) {
    ch = Serial.read();
    i = atoi(&ch);

    if (ch != 10 && ch != 13) {
      Serial.println(i);
    }    
  }
}
 */
