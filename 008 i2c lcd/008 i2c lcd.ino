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
