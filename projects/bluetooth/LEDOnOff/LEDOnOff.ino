int pinLED = 13;
int pinSwitch = 12;
int tx=1;
int rx=0;
char inSerial[15];


void setup(){
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
  pinMode(pinSwitch, OUTPUT);
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
    digitalWrite(pinSwitch, LOW);
    Serial.println("Light OFF!");
  } 
  if(!strcmp(inStr,"on")){      //ON
    digitalWrite(pinSwitch, HIGH);
    Serial.println("Light ON!");
  }
  for(m=0;m<11;m++)
    inStr[m]=0;
}

