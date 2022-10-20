#include <TaskScheduler.h>

void toggle_Red_ON();
void toggle_Red_OFF();
void toggle_Yellow_ON();
void toggle_Yellow_OFF();
void toggle_Green_ON();
void toggle_Green_OFF();
void toggle_White_ON();
void toggle_White_OFF();

bool Red=true;
bool Yellow=false;
bool Green=false;
bool White=false;

Scheduler SR;
Scheduler SY;
Scheduler SG;
Scheduler SW;

Task SR1(15000, -1, toggle_Red_ON , &SR, true);
Task SR2(15000, -1, toggle_Red_OFF , &SR, false);

Task SY1(15000, -1, toggle_Yellow_ON , &SY, true);
Task SY2(15000, -1, toggle_Yellow_OFF, &SY, false);
Task SY3(15000, -1, toggle_Yellow_ON , &SY, false);
Task SY4(15000, -1, toggle_Yellow_OFF, &SY, false);

Task SG1(15000, -1, toggle_Green_ON , &SG, true);
Task SG2(15000, -1, toggle_Green_OFF, &SG, false);
Task SG3(15000, -1, toggle_Green_ON , &SG, false);
Task SG4(15000, -1, toggle_Green_OFF, &SG, false);
Task SG5(15000, -1, toggle_Green_ON , &SG, false);
Task SG6(15000, -1, toggle_Green_OFF, &SG, false);
Task SG7(15000, -1, toggle_Green_ON , &SG, false);
Task SG8(15000, -1, toggle_Green_OFF, &SG, false);

Task SW1(15000, -1, toggle_White_ON , &SW, true);
Task SW2(15000, -1, toggle_White_OFF, &SW, false);
Task SW3(15000, -1, toggle_White_ON , &SW, false);
Task SW4(15000, -1, toggle_White_OFF, &SW, false);
Task SW5(15000, -1, toggle_White_ON , &SW, false);
Task SW6(15000, -1, toggle_White_OFF, &SW, false);
Task SW7(15000, -1, toggle_White_ON , &SW, false);
Task SW8(15000, -1, toggle_White_OFF, &SW, false);

void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(13,OUTPUT);
  SR2.enableDelayed(5000);

  SY1.enableDelayed(8000);
  SY2.enableDelayed(11000);
  SY3.enableDelayed(14000);
  SY4.enableDelayed(15000);
  
  SG1.enableDelayed(5000);
  SG2.enableDelayed(8000);
  SG3.enableDelayed(8500);
  SG4.enableDelayed(9000);
  SG5.enableDelayed(9500);
  SG6.enableDelayed(10000);
  SG7.enableDelayed(10500);
  SG8.enableDelayed(11000);
  
  SW1.enableDelayed(8000);
  SW2.enableDelayed(11000);
  SW3.enableDelayed(11500);
  SW4.enableDelayed(12000);
  SW5.enableDelayed(12500);
  SW6.enableDelayed(13000);
  SW7.enableDelayed(13500);
  SW8.enableDelayed(14000);
}

void loop() {
  SR.execute();
  SY.execute();
  SG.execute();
  SW.execute();
}

void toggle_Red_ON(){
  Red=1;
  digitalWrite(9,Red);
}

void toggle_Red_OFF(){
  Red=0;
  digitalWrite(9,Red);
}

void toggle_Yellow_ON(){
  Yellow=1;
  digitalWrite(8,Yellow);
}

void toggle_Yellow_OFF(){
  Yellow=0;
  digitalWrite(8,Yellow);
}
void toggle_Green_ON(){
  Green=1;
  digitalWrite(7,Green);
}

void toggle_Green_OFF(){
  Green=0;
  digitalWrite(7,Green);
}

void toggle_White_ON(){
  White=1;
  digitalWrite(13,White);
}

void toggle_White_OFF(){
  White=0;
  digitalWrite(13,White);
}

///////////////////////////////////////////////////
//위와 작동방식이 같으면서 다름

#include <TaskScheduler.h>

const int RED_TIME    = 5000;

const int YELLOW_TIME = 3000;

const int GREEN_TIME  = 3000;
const int GREEN_BLINK = 3000;
const int GREEN_BLINK_INTERVAL = 500;

const int WHITE_TIME  = 3000;
const int WHITE_BLINK = 3000;
const int WHITE_BLINK_INTERVAL = 500;

const int YELLOW2_TIME = 1000;

bool redOE();
void redOD();

bool yellowOE();
void yellowOD();

bool greenOE();
void greenOD();

bool greenBlinkOE();
void greenBlinkCB();
void greenBlinkOD();

bool whiteOE();
void whiteOD();

bool whiteBlinkOE();
void whiteBlinkCB();
void whiteBlinkOD();

bool yellow2OE();
void yellow2OD();

Scheduler ts;

Task red(RED_TIME,       TASK_ONCE, NULL,         &ts, false,   redOE,    redOD);

Task yellow(YELLOW_TIME, TASK_ONCE, NULL,         &ts, false,   yellowOE, yellowOD);

Task green(GREEN_TIME,   TASK_ONCE, NULL,         &ts, false,   greenOE,  greenOD);
Task greenBlink(500,     6,         greenBlinkCB, &ts, false,   greenBlinkOE, greenBlinkOD);

Task white(WHITE_TIME,   TASK_ONCE, NULL,         &ts, false,   whiteOE,  whiteOD);
Task whiteBlink(500,     6,         whiteBlinkCB, &ts, false,   whiteBlinkOE, whiteBlinkOD);

Task yellow2(YELLOW2_TIME, TASK_ONCE, NULL,       &ts, false,   yellow2OE, yellow2OD);

bool redToGreen = true;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13,OUTPUT);

  redToGreen = true;
  red.restartDelayed();
}

void loop() {
  ts.execute();
}

///////////////////////////////////////////////////////

bool redOE() {
  digitalWrite(8, HIGH);
  redToGreen = true;
  return true;
}

void redOD() {
  digitalWrite(8, LOW);
  green.restartDelayed();
}

///////////////////////////////////////////////////////

bool yellowOE() {
  digitalWrite(11, HIGH);
  return true;
}

void yellowOD() {
  digitalWrite(11, LOW);
  //if (redToGreen) green.restartDelayed();
  //else red.restartDelayed();
}

///////////////////////////////////////////////////////

bool greenOE() {
  digitalWrite(9, HIGH);
  return true;
}

void greenOD() {
  digitalWrite(9, LOW);
  greenBlink.restartDelayed();
  yellow.restartDelayed();
  white.restartDelayed();
}

bool greenState;
bool greenBlinkOE() {
  digitalWrite(9, LOW);
  greenState = false;
  return true;
}

void greenBlinkCB()  {
  greenState = greenState ^ 1;
  digitalWrite(9, greenState ? HIGH : LOW);
}

void greenBlinkOD() {
  digitalWrite(9, LOW);
  //yellow.restartDelayed();
  //redToGreen = false;
}

///////////////////////////////////////////////////////

bool whiteOE() {
  digitalWrite(13, HIGH);
  return true;
}

void whiteOD() {
  digitalWrite(13, LOW);
  whiteBlink.restartDelayed();
}

bool whiteState;
bool whiteBlinkOE() {
  digitalWrite(13, LOW);
  whiteState = false;
  return true;
}

void whiteBlinkCB()  {
  whiteState = whiteState ^ 1;
  digitalWrite(13, whiteState ? HIGH : LOW);
}

void whiteBlinkOD() {
  digitalWrite(13, LOW);
  //yellow.restartDelayed();
  //redToGreen = false;
  yellow2.restartDelayed();
}

///////////////////////////////////////////////////////

bool yellow2OE() {
  digitalWrite(11, HIGH);
  return true;
}

void yellow2OD() {
  digitalWrite(11, LOW);
  red.restartDelayed();
  redToGreen = false;
}
