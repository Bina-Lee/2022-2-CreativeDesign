let serial;
let bData = 0;
let aData = 0;
 
function setup() {
  createCanvas(600, 400);
  background(220);
  fill(200);
  circle(300,200,200);
 
  serial = new p5.SerialPort();
  serial.open("COM6");
  serial.on("data", dataReceived);
}
 
function dataReceived() {
  let str = serial.readLine();
  trim(str);
  if (!str) return;
  let words = str.split(' ');
  print(str);
  switch (words[0]) {
    case 'b':
        bData = Number(words[1]);
        break;
    case 'a':
        aData = Number(words[1]);
        break;
    default:
        print('unknown command' + words[0]);
  }
}
 
function draw() {
  background(220);
  if (bData) {
    fill(255, 0, 0);
  } else {
    fill(200);
  }
  circle(300, 200, 200);
  let m = map(aData, 0, 1023, 0, width);
  rect(0,380,m,20);
}

////////////////////////////////////////////////////

//원의 위치, 사이즈 랜덤
//가변저항 값으로 주기 조절

//frameRate

let serial;
let bData = 0;
let aData = 0;
 
function setup() {
  createCanvas(600, 400);
  background(220);
 
  serial = new p5.SerialPort();
  serial.open("COM3");
  serial.on("data", dataReceived);
}

function dataReceived() {
  let str = serial.readLine();
  trim(str);
  if (!str) return;
  let words = str.split(' ');
  print(str);
  switch (words[0]) {
    case 'b':
        bData = Number(words[1]);
        break;
    case 'a':
        aData = Number(words[1]);
        break;
    default:
        print('unknown command' + words[0]);
  }
}

function draw(){
  r=random(255);
  g=random(255);
  b=random(255);
  fill(r,g,b,50);
  x=random(599);
  y=random(399);
  d=random(150)+50;
  circle(x,y,d);
  t=map(aData,0,1023,1,60);
  
  frameRate(t);
  //delay(1000);
  
  //delay(1/t);
  if(!bData){
    createCanvas(600, 400);
    background(220);
  }
}

////////////////////////////////////////////////////

