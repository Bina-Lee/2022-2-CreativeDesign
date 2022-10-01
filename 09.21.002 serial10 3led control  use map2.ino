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
