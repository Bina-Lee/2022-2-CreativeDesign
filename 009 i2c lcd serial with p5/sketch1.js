let lcdFont;

function preload() {
  lcdFont = loadFont('assets/5x8_lcd.ttf');
}

function setup() {
  createCanvas(450, 120);
  background(100,150,255);
  fill('#FFFFFF');
  textFont(lcdFont);
  textSize(36);
  text('이게모노',   10,  50);
  text('Arduino at INU!', 10, 100);
}
