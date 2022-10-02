//원을 그리고 버튼의 눌림상태에 따라서 빨간색으로 표시

let serial;
let latestData = 0;

function setup() {
  createCanvas(600, 400);
  background(220);
  fill(200);
  circle(300,200,200);

  serial = new p5.SerialPort();
  serial.open("COM34");
  serial.on("data", dataReceived);
}

function dataReceived() {
  let str = serial.readLine();
  trim(str);
  if (!str) return;
  latestData = Number(str);
  if (latestData) {
    fill(255, 0, 0);
  } else {
    fill(200);
  }
  circle(300, 200, 200);
}

function draw() {
}

////////////////////////////////////////////////////

//위 코드에서 440Hz소리를 내도록 추가

let serial;
let latestData = 0;
let osc;
 
function setup() {
  createCanvas(600, 400);
  background(220);
  fill(200);
  circle(300,200,200);
  serial = new p5.SerialPort();
  serial.open("COM34");
  serial.on("data", dataReceived);
  osc = new p5.Oscillator(440);
}

function dataReceived() {
  let str = serial.readLine();
  trim(str);
  if (!str) return;
  latestData = Number(str);
  if (latestData) {
    fill(255, 0, 0);
    osc.start();
    osc.amp(0.5);
  } else {
    fill(200);
    osc.amp(0,1);
  }
  circle(300, 200, 200);
}

////////////////////////////////////////////////////

p5.Oscillator

////////////////////////////////////////////////////
