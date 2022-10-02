void setup() {
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int a=analogRead(0);
  int m=map(a,0,1023,0,255);
  
  analogWrite(9,m);
  analogWrite(10,m);
  analogWrite(11,m);
  
  char buf[128];
  sprintf(buf,"%d -> %d",a,m);
  Serial.println(buf);
  delay(100);
}

////////////////////////////////////////////////////

void setup() {
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int a=analogRead(0);
  int m=map(a,0,1023,0,255);

  if(m<85){
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }
  else if(m<170){
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
  }
  else{
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
  }
  
  char buf[128];
  sprintf(buf,"analog value : %d -> %d",a,m);
  Serial.println(buf);
  delay(100);
}

////////////////////////////////////////////////////

void setup() {
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int a=analogRead(0);
  int m=map(a,0,1023,0,255);
  char ledcolor;

  if(m<85){
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    ledcolor='Y';
  }
  else if(m<170){
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    ledcolor='G';
  }
  else{
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    ledcolor='R';
  }

  char buf[128];
  sprintf(buf,"analog value : %d -> %d, color is : %c",a,m,ledcolor);
  Serial.println(buf);
  delay(100);
}

////////////////////////////////////////////////////

void setup() {
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int a=analogRead(0);
  int m=map(a,0,1023,0,255);

  int ma;
  
  char ledcolor;

  if(m<85){
    ma=map(m,0,84,0,255);
    analogWrite(9,ma);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    ledcolor='Y';
  }
  else if(m<170){
    ma=map(m,85,169,0,255);
    digitalWrite(9,HIGH);
    analogWrite(10,ma);
    digitalWrite(11,LOW);
    ledcolor='G';
  }
  else{
    ma=map(m,170,255,0,255);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    analogWrite(11,ma);
    ledcolor='R';
  }

  char buf[128];
  sprintf(buf,"analog value : %d -> %d, color is : %c",a,m,ledcolor);
  Serial.println(buf);
  delay(100);
}

////////////////////////////////////////////////////

void setup() {
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  pinMode(2,OUTPUT);
  pinMode(4,INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(2,1);
  delayMicroseconds(10);
  digitalWrite(2,0);

  int dist=pulseIn(4,1)*17/1000;
  
  //int a=analogRead(0);
  int m=map(dist,0,30,0,255);

  int ma;
  
  char ledcolor;

  if(m<85){
    ma=map(m,0,84,0,255);
    analogWrite(9,ma);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    ledcolor='Y';
  }
  else if(m<170){
    ma=map(m,85,169,0,255);
    digitalWrite(9,HIGH);
    analogWrite(10,ma);
    digitalWrite(11,LOW);
    ledcolor='G';
  }
  else{
    ma=map(m,170,255,0,255);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    analogWrite(11,ma);
    ledcolor='R';
  }

  char buf[128];
  sprintf(buf,"distance : %d, value : %d, color is : %c",dist,m,ledcolor);
  Serial.println(buf);
  delay(100);
}
