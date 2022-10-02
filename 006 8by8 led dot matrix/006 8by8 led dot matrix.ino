#include "LedControl.h"
LedControl lc=LedControl(12,11,10,1);
 
void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,2);
  lc.clearDisplay(0);
}
 
void loop() { 
  for( int i=0; i<8; i++ ) {
    for( int j=0; j<8; j++ ) {
      lc.setLed(0, i,j, true);
      delay(100);
      lc.setLed(0, i,j, false);
    }
  }
}

////////////////////////////////////////////////////

#include "LedControl.h"
LedControl lc=LedControl(12,11,10,1);
 
void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,2);
  lc.clearDisplay(0);
}
 
void loop() { 
  for(int i=0;i<4;i++){
    for(int j=0;j<7;j++){
      switch(i){
        case 0:
          lc.setLed(0, 0,j, true);
          delay(100);
          lc.setLed(0, 0,j, false);
          break;
        case 1:
          lc.setLed(0, j,7, true);
          delay(100);
          lc.setLed(0, j,7, false);
          break;
        case 2:
          lc.setLed(0, 7,7-j, true);
          delay(100);
          lc.setLed(0, 7,7-j, false);
          break;
        case 3:
          lc.setLed(0, 7-j,0, true);
          delay(100);
          lc.setLed(0, 7-j,0, false);
          break;
      }
    }
  }
}

