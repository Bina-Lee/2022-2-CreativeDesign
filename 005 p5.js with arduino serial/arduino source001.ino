const int buttonPin   = 2;
int       buttonState = 0;
void setup() {
  pinMode( buttonPin, INPUT );
  Serial.begin(9600);
}
 
void loop() {
  int val = digitalRead(buttonPin);
  if (val != buttonState) {
    buttonState = val;
    Serial.println(buttonState);
    delay(20);
  }
}
