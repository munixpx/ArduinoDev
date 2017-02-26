/*
 * IRrecord: record and play back IR signals as a minimal 
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * An IR LED must be connected to the output PWM pin 3.
 * A button must be connected to the input BUTTON_PIN; this is the
 * send button.
 * A visible LED can be connected to STATUS_PIN to provide status.
 *
 * The logic is:
 * If the button is pressed, send the IR code.
 * If an IR code is received, record it.
 *
 * Version 0.11 September, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 5;
//int SENDER_PIN = 3;
int BUTTON_PIN = 7;
int LED_PIN = 13;

IRrecv irrecv(RECV_PIN);
IRsend irsend;

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  //pinMode(SENDER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(BUTTON_PIN, HIGH);
}

// Storage for the recorded code
unsigned long codeValue; // The code value if not raw
unsigned int codeLen=12; // The length of the code

void sendCode()
{
  codeValue = 0xA32AB931;
  irsend.sendSony(codeValue, codeLen);
  Serial.print("Sent Sony ");
  Serial.println(codeValue, HEX);
} 

bool lastButtonState = 1;
bool buttonState = 0;

void loop() {

  buttonState = digitalRead(BUTTON_PIN);

  // If button pressed, enable reciver.
  if (lastButtonState == LOW && buttonState == HIGH) {
    Serial.println("Released");
    irrecv.enableIRIn(); // Re-enable receiver
  }

  // If button pressed, send the code.
  if (!buttonState) {
    //digitalWrite(SENDER_PIN, HIGH);
    sendCode();
    //digitalWrite(SENDER_PIN, LOW);
    delay(500); // Wait a bit between retransmissions
  } 
  if (irrecv.decode(&results)) {
    Serial.print("Recived: ");
    Serial.println(results.value, HEX);
    digitalWrite(LED_PIN, HIGH);
    irrecv.resume(); // resume receiver
    digitalWrite(LED_PIN, LOW);
  }
  lastButtonState = buttonState;
}
