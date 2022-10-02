//09.12.001 pin13 idea1

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

////////////////////////////////////////////////////

//09.13.001 pin13 idea2

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
