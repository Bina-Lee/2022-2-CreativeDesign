//09.16.001 serial1

void setup() {
  Serial.begin(9600);
}

int n=0;
void loop() {
  Serial.println(n);
  delay(2000);
  n++;
}

////////////////////////////////////////////////////

//09.16.002 serial2

void setup() {
  Serial.begin(9600);
}

int n=0;
void loop() {
  Sprintf("%d",n);
  delay(2000);
  n++;
}

////////////////////////////////////////////////////

//09.16.003 serial3

void setup() {
  Serial.begin(9600);
}

int n=0;
char buf[128];
void loop() {
  sprintf(buf,"%2d",n++);
  //버퍼값을 만들기만 함
  Serial.println(buf);
  //출력은 실질적으로 얘가 다 함
  delay(2000);
}

////////////////////////////////////////////////////

//09.16.004 serial4

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

////////////////////////////////////////////////////

//09.16.005 serial5 control led from digital input

const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  //PULLUP을 하면 별도 저항구성 없이 저항을 연결해서 5V를 연결한 효과를 줌
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}

////////////////////////////////////////////////////

//09.16.006 serial6 serial print from digital input

const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  //PULLUP을 하면 별도 저항구성 없이 저항을 연결해서 5V를 연결한 효과를 줌
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    Serial.println("눌림");
    while(1){
      if(buttonState==HIGH)break;
    }
  }
}

////////////////////////////////////////////////////

//09.16.007 serial7 3led control idea from digital input

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
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
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

////////////////////////////////////////////////////

//09.20.001 serial8 3led control idea from digital or serial input practice

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
