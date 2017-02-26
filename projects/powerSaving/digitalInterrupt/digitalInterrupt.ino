#define LED_PIN 13

void setup() {
  outputSave();
  
  enableSleep();

  attachInterrupt(0, digitalInterrupt, FALLING); //interrupt for waking up
}

void loop() {

  digitalWrite(LED_PIN, HIGH);
  delay(5000);
  digitalWrite(LED_PIN, LOW);
  
  sleepCPU();

}


void outputSave(){
  //Save Power by writing all Digital IO LOW - note that pins just need to be tied one way or another, do not damage devices!
  for (int i = 0; i < 20; i++) {
    if(i!=2)
      pinMode(i, OUTPUT);
  }
}


void enableSleep(){
  //ENABLE SLEEP - this enables the sleep mode
  SMCR |= (1 << 2); //power down mode
  SMCR |= 1;//enable sleep
}

void sleepCPU(){
  //BOD DISABLE - this must be called right before the __asm__ sleep instruction
  MCUCR |= (3 << 5); //set both BODS and BODSE at the same time
  MCUCR = (MCUCR & ~(1 << 5)) | (1 << 6); //then set the BODS bit and clear the BODSE bit at the same time
  __asm__  __volatile__("sleep");//in line assembler to go to sleep
}


void digitalInterrupt(){
  //needed for the digital input interrupt
}
