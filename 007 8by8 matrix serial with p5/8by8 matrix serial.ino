#include "LedControl.h"
 
LedControl lc=LedControl(12,11,10,1);
 
String inputString = "";       
bool stringComplete = false; 
 
void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,10); // 0 ~ 15
  lc.clearDisplay(0);
 
  Serial.begin(9600);
  inputString.reserve(200);
}

void LEDCommand() {
  int n = inputString.length();
  if ( n >= 3 ) {
    int x = inputString.charAt(0) - '0';
    int y = inputString.charAt(1) - '0';
    int v = inputString.charAt(2) - '0';
    lc.setLed(0, x,y,v );
  }
}

void loop() {
  if (stringComplete) {
    Serial.println(inputString);
    LEDCommand();
    inputString = "";
    stringComplete = false;
  }
}

 
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

////////////////////////////////////////////////////

//자릿수 5자리로 늘리고 슬라이드 값 전송으로 밝기 조절 및
//클리어 신호에 따라서 한번에 led값들을 0으로 만들도록 수정한 코드

#include "LedControl.h"
 
LedControl lc=LedControl(12,11,10,1);
 
String inputString = "";       
bool stringComplete = false; 
 
void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,10); // 0 ~ 15
  lc.clearDisplay(0);
 
  Serial.begin(9600);
  inputString.reserve(200);
}

void LEDCommand() {
  int n = inputString.length();
  if ( n >= 5 ) {
    int x = inputString.charAt(0) - '0';
    int y = inputString.charAt(1) - '0';
    int v = inputString.charAt(2) - '0';
    int bright = (inputString.charAt(3)-'0')*10
                +(inputString.charAt(4)-'0');
    lc.setLed(0, x,y,v );
    lc.setIntensity(0,bright);

    if(bright>=20){
      for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
          lc.setLed(0, i,j,0 );
        }
      }
    }
  }
}

void loop() {
  if (stringComplete) {
    Serial.println(inputString);
    LEDCommand();
    inputString = "";
    stringComplete = false;
  }
}

 
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
