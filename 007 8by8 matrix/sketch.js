let LEDs = new Array(64).fill(0);
let W = 400;
let H = 400;
let D =  50;

let serial;

function setup() {
  createCanvas(W, H);
  stroke(150);
  
  serial = new p5.SerialPort();
  serial.open("COM3");
}

function draw() {
  background(220);
  drawLEDs();
}

function drawLEDs() {
  for( i=0; i < 8; i++ ) {
    for( j=0; j < 8; j++ ) {
      if (LEDs[j*8+i]) fill('red');
      else fill(200);
      circle(50*i+25, 50*j+25,D);
    }
  }
}

function mousePressed() {
  x = Math.floor(mouseX / D);
  y = Math.floor(mouseY / D);
  LEDs[8*y+x] ^= 1;
  print("" + y + x + LEDs[8*y+x]);
  serial.write("" + y + x + LEDs[8*y+x] + "\r\n");
}

////////////////////////////////////////////////////

//슬라이더로 밝기 조절 및 클리어로 전체 led off 제어 코드

let LEDs = new Array(64).fill(0);
let W = 400;
let H = 440;
let D =  50;

let serial;

let slider;

let button;

function setup() {
  createCanvas(W, H);
  stroke(150);
  
  serial = new p5.SerialPort();
  serial.open("COM3");
  
  slider=createSlider(0,15,0);
  slider.position(10,410);
  slider.style('width','300px');
  
  button = createButton('Clear');
  button.position(325,410);
  button.mousePressed(clearSignal)
}

function draw() {
  background(220);
  drawLEDs();
  
  let val=slider.value();
}

function drawLEDs() {
  for( i=0; i < 8; i++ ) {
    for( j=0; j < 8; j++ ) {
      if (LEDs[j*8+i]) fill(255,00,00,15+14*slider.value());
      else fill(200);
      circle(50*i+25, 50*j+25,D);
    }
  }
}

function mousePressed() {
  x = Math.floor(mouseX / D);
  y = Math.floor(mouseY / D);
  let bright1=floor(slider.value()/10);
  let bright2=slider.value()%10;
  LEDs[8*y+x] ^= 1;
  print("" + y + x +LEDs[8*y+x] + bright1 + bright2);
  serial.write("" + y + x + LEDs[8*y+x] + bright1 + bright2 + "\r\n");
}

function clearSignal(){
  print("" + y + x +LEDs[8*y+x] + 20);
  serial.write("" + y + x + LEDs[8*y+x] + 20 + "\r\n");
  
  createCanvas(W, H);
  stroke(150);

  LEDs = new Array(64).fill(0);
  
  background(220);
  drawLEDs();
}
