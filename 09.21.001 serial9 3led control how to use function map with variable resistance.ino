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
