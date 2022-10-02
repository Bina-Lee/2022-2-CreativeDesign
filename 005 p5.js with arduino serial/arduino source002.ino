const int bPin = 2;
int       bVal = 0;
int       aVal = 0;
 
void setup() {
  pinMode( bPin, INPUT );
  Serial.begin(9600);
}
 
void loop() {
  int b = digitalRead(bPin);
  if (b != bVal) {
    bVal = b;
    Serial.println("b " + String(bVal));
  }
  
  int a = analogRead(A0);
  if (abs(a-aVal)>1) {
    aVal = a;
    Serial.println("a " + String(aVal));
  }
 
  delay(20); 
}
