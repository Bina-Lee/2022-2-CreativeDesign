#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Hello, world!");
// lcd.write(239);
  lcd.setCursor(0, 1);
  lcd.print("Arduino at INU!");
}

void loop() {
}

////////////////////////////////////////////////////

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Times 2 Table");
}

int n = 0;
void loop() {
  char line[41];
  sprintf( line, "2x%d=%2d", n, 2*n);
  lcd.setCursor(0,1);
  lcd.print(line);
  n++; n = n % 10;
  delay(1000);
}

////////////////////////////////////////////////////

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Times 2 Table");
  lcd.setCursor(0, 1);
}

boolean introMode = true;
int     counter = 0;
void intro() {
  lcd.print(counter++, HEX);
  if ( counter > 15 )
    introMode = false;
  delay(500);
}

int  x = 0;
char line[41];

void loop() {
  if (introMode) intro();
  else {
    lcd.clear();

    sprintf( line, "2x%d=%2d", x, 2 * x);
    lcd.print(line);
    lcd.setCursor(8, 0);

    sprintf( line, "7x%d=%2d", x, 7 * x);
    lcd.print(line);
    lcd.setCursor(0, 1);

    x = (x + 1) % 10;
    sprintf( line, "2x%d=%2d", x, 2 * x);
    lcd.print(line);
    lcd.setCursor(8, 1);

    sprintf( line, "7x%d=%2d", x, 7 * x);
    lcd.print(line);

    delay(1000);
  }
}

////////////////////////////////////////////////////

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int stringlength = 0;
char stringprint[200]
  ="Yesterday is history, tomorrow is a mystery, buy today is a gift. That is why it is called the present.";

void setup() {
  lcd.init();
  lcd.backlight();

  int count=0;

  while(1){
    if(stringprint[count]==0){
      stringlength=count;
      break;
    }
    count++;
  }
}

void loop() {
  char forprint[2];
  for(int i=0;i<stringlength;i++){
    lcd.setCursor(0,0);
    for(int j=0;j<32;j++){
      sprintf(forprint,"%c\0",stringprint[(i+j)%(stringlength)]);
      if(j==16)lcd.setCursor(0,1);
      lcd.print(forprint);
    }
    delay(400);
  }
}

////////////////////////////////////////////////////

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 in PCF8574 by NXP and Set to 0x3F in PCF8574A by Ti
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte c0[] = {
  B00100,
  B01010,
  B10001,
  B01010,
  B00100,
  B01010,
  B10001,
  B01010
};
byte c1[] = {0x0A, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x0A, 0x04};
byte c2[] = {0x11, 0x0A, 0x04, 0x0A, 0x11, 0x0A, 0x04, 0x0A};
byte c3[] = {0x00, 0x00, 0x00, 0x04, 0x04, 0x0F, 0x11, 0x1F};

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, c0);
  lcd.createChar(1, c1);
  lcd.createChar(2, c2);
  lcd.createChar(3, c3);
  lcd.home();
  lcd.write(0);
  lcd.write(1);
  lcd.write(2);
  lcd.write(3);
}

void loop() { }

////////////////////////////////////////////////////

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
  line1 = "Serial";
  line2.reserve(100);
  line2 = "Enter message!";
  
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
    line1 = line2;// scroll
    input.trim(); // remove \r\n at the end
    line2 = input;
    lcd.print(line1);
    lcd.setCursor(0,1);
    lcd.print(line2);
    input = "";
    stringComplete = false;
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

////////////////////////////////////////////////////

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
