void setup() {
  Serial.begin(9600);
}

int n=0;
void loop() {
  Sprintf("%d",n);
  delay(2000);
  n++;
}
