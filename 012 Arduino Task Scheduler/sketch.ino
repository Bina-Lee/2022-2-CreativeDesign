#include <TaskScheduler.h>

void toggle(); //함수 이름은 함수 포인터 이다

Scheduler ts;
Task t1(1000, -1, toggle , &ts, true);
        //타임,횟수,할일,스케줄 주소
        //-1이나 뭔가를 쓰면 횟수제한없이 작동,
        //양의정수를 쓰면 그만큼만 작동

void setup() {
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  ts.execute();
}

void toggle(){
  static bool s=false;
  s^=1;
  digitalWrite(9,s);
  digitalWrite(8,!s);
}

////////////////////////////////////////////////////

#include <TaskScheduler.h>

void toggle(); //함수 이름은 함수 포인터 이다

Scheduler ts;
Task t1(1000, -1, toggle , &ts, true);
        //타임,횟수,할일,스케줄 주소
        //-1이나 뭔가를 쓰면 횟수제한없이 작동,
        //양의정수를 쓰면 그만큼만 작동
Task t2(1000, -1, toggle , &ts, false);

void setup() {
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  t2.enableDelayed(200);
      //스케줄러가 시작하는 타이밍을 조절할 수 있음
      //기본 t2의 상태가 false로 되어있기 때문에 작동을 하지 않음
      //enableDelayed로 실행시킴
  
      //근데 true로 두고 시작해도 문제는 없다 카더라
}

void loop() {
  ts.execute();
}

void toggle(){
  static bool s=false;
  s^=1;
  digitalWrite(9,s);
  digitalWrite(8,!s);
}

////////////////////////////////////////////////////

#include <TaskScheduler.h>

void toggle_Red(); //함수 이름은 함수 포인터 이다
void toggle_Yellow();

Scheduler ts1;
Task t1(1000, -1, toggle_Red , &ts1, true);
        //타임,횟수,할일,스케줄 주소
        //-1이나 뭔가를 쓰면 횟수제한없이 작동,
        //양의정수를 쓰면 그만큼만 작동
Task t2(1000, -1, toggle_Red , &ts1, false);

Task t3(850, -1, toggle_Yellow, &ts1, true);
Task t4(850, -1, toggle_Yellow, &ts1, false);

void setup() {
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  t2.enableDelayed(200);
      //스케줄러가 시작하는 타이밍을 조절할 수 있음
      //기본 t2의 상태가 false로 되어있기 때문에 작동을 하지 않음
      //enableDelayed로 실행시킴\
  t3.enableDelayed(500);
  t4.enableDelayed(550);
}

void loop() {
  ts1.execute();
}

void toggle_Red(){
  static bool s1=false;
  s1^=1;
  digitalWrite(9,s1);
}

void toggle_Yellow(){
  static bool s2=false;
  s2^=1;
  digitalWrite(8,s2);
}

////////////////////////////////////////////////////

