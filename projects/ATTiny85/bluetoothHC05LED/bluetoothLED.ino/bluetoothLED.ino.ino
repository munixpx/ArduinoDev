#include <SoftwareSerial.h>  //Software Serial Port
#define RxD 1
#define TxD 2

#define DEBUG_ENABLED  1
 
SoftwareSerial blueToothSerial(RxD,TxD);

int ledRead = 3;
int led = 4;
 
void setup() 
{ 
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  setupBlueToothConnection();
  
  pinMode(led, OUTPUT);
  pinMode(ledRead, OUTPUT);
  digitalWrite(led,LOW);
  digitalWrite(ledRead,LOW);
} 

int count=0;
void loop() 
{ 
  char recvChar;
  if(blueToothSerial.available()> 0){
    recvChar = blueToothSerial.read();
    
    digitalWrite(ledRead,HIGH);
    delay(1000);
    digitalWrite(ledRead,LOW);
    delay(1000);
    
    count++ ;
    if(count%2==0)
      digitalWrite(led,HIGH);     
    else
      digitalWrite(led,LOW); 
  }
} 
 
void setupBlueToothConnection()
{
  blueToothSerial.begin(9600); //Set BluetoothBee BaudRate to default baud rate 38400
  blueToothSerial.println("Online");
  blueToothSerial.flush();
}
