
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output: 
  
  
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(2, INPUT_PULLUP);
  //PULLUP을 하면 별도 저항구성 없이 저항을 연결해서 5V를 연결한 효과를 줌
  Serial.begin(9600);
}

void loop() {
    int check_s=0;
    if(Serial.available()){
      check_s=Serial.read();
    }
  
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH || check_s!='s') {
    // turn LED on:
  } else {
    // turn LED off:
    Serial.println("눌림");
    
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    delay(500);
    
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    delay(500);
    
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    delay(500);
  }
}
