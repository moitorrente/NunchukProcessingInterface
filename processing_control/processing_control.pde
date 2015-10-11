import processing.serial.*;

Serial port; 

int wait=2000;
int extra=100;
int stop_char='a';
int joyx, joyy, accx, accy, cbut, zbut;

String myString;
boolean serialInited;

void setup() {
  size(500, 600);
  noStroke();
  initSerial();
  cursor(CROSS);
}

void draw() {
  background(0);
  if (serialInited) {
    parse_nunchuck();
  } else {
    initSerial();
  }
}


void initSerial() {
  try {
    port = new Serial(this, Serial.list()[1], 19200);
    port.bufferUntil(stop_char);
    delay(wait);
    println("Serial communication inited");
    serialInited=true;
  } 
  catch(RuntimeException e) {
    println("Serial communication not inited");
    serialInited=false;
  }
}


void serialEvent(Serial myPort) {
  myString=myPort.readString();
}


void parse_nunchuck() {
  int[] inBuffer = int(split(myString, " "));
  joyx=inBuffer[0];
  joyy=inBuffer[1];
  accx=inBuffer[2];
  accy=inBuffer[3];
  cbut=inBuffer[4];
  zbut=inBuffer[5];
  print("joyx: "+joyx+"\t");
  print("joyy: "+joyy+"\t");
  print("accx: "+accx+"\t");
  print("accx: "+accy+"\t");
  print("cbut: "+cbut+"\t");
  println("zbut: "+zbut+"\t");
}