void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

int n=0;
void loop(){
  digitalWrite(LED_BUILTIN,1);
  delay(100+n*100);
  digitalWrite(LED_BUILTIN,0);
  delay(900-n*100);
  n=(++n)%5;
}
