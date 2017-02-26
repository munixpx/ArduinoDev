
unsigned int pins[] = {2, 3, 4, 5, 6, 8, 9};

unsigned int zero[] = {1, 1, 1, 1, 1, 1, 0};
unsigned int one[] = {0, 1, 1, 0, 0, 0, 0};
unsigned int two[] = {1, 1, 0, 1, 1, 0, 1};
unsigned int three[] = {1, 1, 1, 1, 0, 0, 1};
unsigned int four[] = {0, 1, 1, 0, 0, 1, 1};
unsigned int five[] = {1, 0, 1, 1, 0, 1, 1};
unsigned int six[] = {1, 0, 1, 1, 1, 1, 1};
unsigned int seven[] = {1, 1, 1, 0, 0, 0, 0};
unsigned int eight[] = {1, 1, 1, 1, 1, 1, 1};
unsigned int nine[] = {1, 1, 1, 1, 0, 1, 1};

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  for(unsigned int i=0; i < 7; i++)
  {
    digitalWrite(pins[i], !zero[i]);  
  }
  delay(1000);
  for(unsigned int i=0; i < 7; i++)
  {
    digitalWrite(pins[i], !one[i]);  
  }
  delay(1000);
  for(unsigned int i=0; i < 7; i++)
  {
    digitalWrite(pins[i], !two[i]);  
  }
  delay(1000);
  for(unsigned int i=0; i < 7; i++)
  {
    digitalWrite(pins[i], !three[i]);  
  }
  delay(1000);
  for(unsigned int i=0; i < 7; i++)
  {
    digitalWrite(pins[i], !four[i]);  
  }
  delay(1000);
  for(unsigned int i=0; i < 7; i++)
  {
    digitalWrite(pins[i], !five[i]);  
  }
  delay(1000);
  for(unsigned int i=0; i < 7; i++)
  {
    digitalWrite(pins[i], !six[i]);  
  }
  delay(1000);
  for(unsigned int i=0; i < 7; i++)
  {
    digitalWrite(pins[i], !seven[i]);  
  }
  delay(1000);
  for(unsigned int i=0; i < 7; i++)
  {
    digitalWrite(pins[i], !eight[i]);  
  }
  delay(1000);
  for(unsigned int i=0; i < 7; i++)
  {
    digitalWrite(pins[i], !nine[i]);  
  }
  delay(1000);
}



