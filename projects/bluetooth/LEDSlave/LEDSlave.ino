int pinLED = 13;
int tx=1;
int rx=0;
char inSerial[15];


void setup(){
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
}

void loop(){
    int i=0;
    int m=0;
    delay(500);                                         
    if (Serial.available() > 0) {             
       while (Serial.available() > 0) {
         inSerial[i]=Serial.read(); 
         i++;      
       }
       inSerial[i]='\0';
      Check_Protocol(inSerial);
     }} 
  
void Check_Protocol(char inStr[]){   
  int m=0;
  Serial.println(inStr);
  
  if(!strcmp(inStr,"off")){      //OFF
    digitalWrite(pinLED, LOW);
  } 
  if(!strcmp(inStr,"on")){      //ON
    digitalWrite(pinLED, HIGH);
  }
  for(m=0;m<11;m++)
    inStr[m]=0;
}

