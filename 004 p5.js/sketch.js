createCanvas(windowWidth, windowHeight);
background(120,250,50, 100);
fill(255,255,0, 20);
noStroke();
stroke(0,255,0, 20);
rect(100,50, 200,100, 20);
rect(100,50, 200,100, 50,50,0,0);
ellipse(100,50, 100,100); circle(100,50, 100);
triangle(100,100, 200,100, 200,200);

////////////////////////////////////////////////////

function setup(){
  createCanvas(400,400);
  background(220);
}

runction draw(){
  circle(200,200,100);
}

////////////////////////////////////////////////////

//랜덤 동심원 그리기

let x = 0;

function setup() {
  createCanvas(400, 400);
  background(220);
  frameRate(5);
}

function draw() {
  r = random(255);
  g = random(255);
  b = random(255);
  fill(r, g, b);
  circle(0,0,800-x);
  x = x + 10;
  if ( x > 800 ) {
    x = 0;
  }
}

////////////////////////////////////////////////////

//랜덤 컬러, 랜덤 크기
//좌표는 마우스 위치

//mouseX, mouseY, pmouseX, pmouseY

function setup() {
  createCanvas(600, 400);
  background(220);
}

function draw() {
  r = random(255);
  g = random(255);
  b = random(255);
  fill(r, g, b, 50);
  d = random(100);
  circle(mouseX, mouseY, d);
}

////////////////////////////////////////////////////

//위 코드에서 원을 삼각형으로 변경

function setup() {
  createCanvas(600, 400);
  background(220);
}

function draw() {
  r = random(255);
  g = random(255);
  b = random(255);
  fill(r, g, b, 50);
  d = random(100);
  translate(mouseX, mouseY);
  triangle(0,0, d,0, d,-d);
}
