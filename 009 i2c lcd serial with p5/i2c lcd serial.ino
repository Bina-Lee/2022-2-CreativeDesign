//시리얼 입력 문자 lcd로 출력

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

String input = "";
String line1 = "";
String line2 = "";
bool stringComplete = false; 

void setup() {
  Serial.begin(9600);
  input.reserve(100);
  line1.reserve(100);
  line1 = "Hello, world!";
  line2.reserve(100);
  line2 = "Arduino at INU!";
  
  lcd.init(); 
  lcd.backlight(); 
  lcd.print(line1);
  lcd.setCursor(0,1);
  lcd.print(line2);
}

void loop() {
  if (stringComplete) {
    Serial.println(input);
    lcd.clear();
    input.trim(); // remove \r\n at the end
    if( input.charAt(0) == '0' ) 
      line1 = input.substring(1);
    else                        
      line2 = input.substring(1);
    lcd.print(line1); lcd.setCursor(0,1); lcd.print(line2);
    input = ""; stringComplete = false;
  }
}


void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    input += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
