let lcdFont, input0, input1;
 
function preload() {
  lcdFont = loadFont('assets/5x8_lcd.ttf');
}
 
function setup() {
  createCanvas(450, 240);
  background(100,150,255);
  noStroke();        fill('#FFFFFF');
  textFont(lcdFont); textSize(36);
  text('Hello, world!',   10,  50);
  text('Arduino at INU!', 10, 100);
  input0 = createInput('Hello, world!');
  input0.position(5, 120 );
  input0.size(420);
  input0.input(input0Event);
  input1 = createInput('Arduino at INU!');
  input1.position(5, 180 );
  input1.size(420);
  input1.input(input1Event);
}

function input0Event() {
  console.log('input0: ', this.value());
  fill(100,150,255);
  rect(0,0, 450, 60);
  fill('#FFFFFF');
  text(this.value(),   10,  50);
}
 
function input1Event() {
  console.log('input1: ', this.value());
  fill(100,150,255);
  rect(0,60, 450, 60);
  fill('#FFFFFF');
  text(this.value(),   10, 100);
}
