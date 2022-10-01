void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

int n=0;
void loop(){
  n++;
  digitalWrite(LED_BUILTIN,n==1||n=11||n=13||n==21||n==23||n==25);
  delay(100);
  n=n%30;
}
