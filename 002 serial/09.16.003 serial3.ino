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
