let portName = 'COM10';
let serial;         
let inMsg;   
let bitsCount = 0; 
let val = 0;
let writeAPIkey = "54J2G7ZQA1QXEB81";
let urlBase = "https://api.thingspeak.com/update.json?api_key=" + writeAPIkey + "&field1=";
let loadedJson = null;
let pUpdateSecond = 0;

function setup() {
  createCanvas(400, 275);
  colorMode(HSB, 256, 100, 100);
  background(0);
  
  serial = new p5.SerialPort(); 
  serial.open(portName);
  serial.on('data', serialEvent);
  serial.clear();
}

function draw() {

  updateIoTchannel();
}

function serialEvent() {
  inMsg = serial.readLine();
  if (inMsg !=''){
    
    if ( inMsg == 1){
      background('red');
      print("RED:1")
    }
    else if (inMsg == 2) {
      background('yellow');
      print("YELLOW:2")
    }
    else if (inMsg == 3) {
      background('green');
      print("GREEN:3")
    }
  }
}

function updateDone() {
  print(loadedJson);
}

function updateIoTchannel() {
  s = second();
  d = (s + 60 - pUpdateSecond) % 60;
  
  if ( d > 20) { // free update interval > 15 sec
    pUpdateSecond = s;
    fieldNum = Number(inMsg);
    url = urlBase + String(fieldNum);
    loadedJson = loadJSON(url, updateDone);
  }
}
