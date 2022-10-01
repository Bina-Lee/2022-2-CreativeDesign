void setup() {
  Serial.begin(9600);
}

int n=0;
char buf[128];
void loop() {
  n++;
  sprintf(buf,"%2d x%2d =%2d",2,n,2*n);
  Serial.println(buf);
  delay(5000);
  n=n%9;
}
