let portName = 'COM3';
let serial;         
let inMsg;   
let bitsCount = 0; 
let val = 0;
let writeAPIkey = "8H4OEMYC4SNPMAXE";
let urlBase = "https://api.thingspeak.com/update.json?api_key=" + writeAPIkey + "&field1=";
//https://api.thingspeak.com/update.json?api_key=8H4OEMYC4SNPMAXE&field1=1&field2=1010&field3=25&field4=36

let loadedJson = null;
let pUpdateSecond = 0;

let splitMsg=[];

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
  //s = second();
  //print(s);
  updateIoTchannel();
}

function serialEvent() {
  inMsg = serial.readLine();
  //print(inMsg);
  //splitMsg=split(inMsg);
  splitMsg=inMsg.split(",");
    
//   if (inMsg !=''){
    
//     if ( inMsg == 1){
//       background('red');
//       print("RED:1")
//     }
//     else if (inMsg == 2) {
//       background('yellow');
//       print("YELLOW:2")
//     }
//     else if (inMsg == 3) {
//       background('green');
//       print("GREEN:3")
//     }
//   }
}

function updateDone() {
  //print(loadedJson);
}

function updateIoTchannel() {
  s = second();
  //print(s);
  if(s%20==0 && Number.isInteger(Number(splitMsg[1]))){
  //d = (s + 60 - pUpdateSecond) % 60;
  
  //if ( d > 20) { // free update interval > 15 sec
    //pUpdateSecond = s;
    //fieldNum = Number(inMsg);
    //if(Number.isInteger(Number(splitMsg[1]))){
      url = urlBase + String((splitMsg[0])) + "&field2=" + String((splitMsg[1])) + "&field3=" + String((splitMsg[2])) + "&field4=" + String((splitMsg[3])) ;
      print(url);
      loadedJson = loadJSON(url, updateDone);
    //}
  }
}
