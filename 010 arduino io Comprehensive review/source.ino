#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int aVal =  0;
int pVal = -1;
char buf[5];

void setup() {
  lcd.init();
  lcd.backlight();
  //lcd.print("Pot Test");
  aVal = analogRead( A0 );
  lcd.setCursor(0, 1);
  lcd.print(aVal);
}

void loop() {
  aVal = analogRead( A0 );
  if (abs(pVal - aVal) >= 2) {
    pVal = aVal;
    lcd.setCursor(0, 1);
    sprintf( buf, "%4d", aVal);
    lcd.print(buf);
  }
  delay(100);
}

////////////////////////////////////////////////////

/*
1. LCD 연결해서 헬로우 월드한다.
2. + 가변저항 연결해서 0~1024 값을 LCD에 나타낸다.
3. + 버튼 연결해서 누를 때마다 적-녹-황 LED를 돌아가며 켜게한다.
4. + DHT11 온습도 센서 연결해서 2초마다 1회씩 시리얼에 프린트한다.
5. + LCD에 가변저항값, 온도, 습도를 차례대로 나타낸다.
6. + 시리얼에 가변저항값, 온도, 습도를 차례대로 나타낸다.
*/

#include <LiquidCrystal_I2C.h>
#include "DHT.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(8,DHT11);

int aVal =  0;
int pVal = -1;
char buf[5];

int state=0;
int nextstate=0;

int ledr=1;
int ledg=0;
int ledy=0;

int temp=0;
int humid=0;

char dhtbuf[41];

char serialbuf[41];

void setup() {
  pinMode(2,INPUT_PULLUP);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

  Serial.begin(9600);

  dht.begin();

  lcd.init();
  lcd.backlight();
  lcd.print("Hello,world!");
  // lcd.write(239);
  //lcd.setCursor(0, 1);
  //lcd.print("Arduino at INU!");
  aVal = analogRead( A0 );
  lcd.setCursor(12, 0);
  lcd.print(aVal);
}

void loop() {

  nextstate=digitalRead(2);

  if(nextstate==1&&state==0){
    if(ledr){
      ledr=0;
      ledg=1;
    }
    else if(ledg){
      ledg=0;
      ledy=1;
    }
    else if(ledy){
      ledy=0;
      ledr=1;
    }
  }
  digitalWrite(11,ledr);
  digitalWrite(12,ledg);
  digitalWrite(13,ledy);

  state=nextstate;

  aVal = analogRead( A0 );
  if (abs(pVal - aVal) >= 2) {
    pVal = aVal;
    lcd.setCursor(12, 0);
    sprintf( buf, "%4d", aVal);
    lcd.print(buf);
  }

  temp=dht.readTemperature();
  humid=dht.readHumidity();

  sprintf(dhtbuf,"T:%2d H:%2d",temp,humid);
  sprintf(serialbuf,"%4d T:%2d H:%2d",aVal,temp,humid);
  lcd.print(dhtbuf);
  Serial.println(serialbuf);
  lcd.setCursor(0,1);

  delay(10);
}
