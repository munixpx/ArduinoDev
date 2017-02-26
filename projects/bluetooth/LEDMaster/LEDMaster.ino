

int pinIN = 8;
int tx=1;
int rx=0;
char inSerial[15];


void setup(){
  Serial.begin(9600);
  pinMode(pinIN, INPUT);
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
}

bool prevState = false;
String stat = "";

void loop(){
  if (digitalRead(pinIN)){
    stat = "on";
    if(prevState){
      stat = "off";
    }
    Serial.println(stat);
  }
}

