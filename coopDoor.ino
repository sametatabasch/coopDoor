#include "CoopDoor.h"

int TX = A0;
int RX = A1;
SoftwareSerial BTSerial(RX, TX);

int buttonPin=4;


/**
  which recieved data
*/
String data;

CoopDoor theDoor(9);

void setup() {
  // put your setup code here, to run once:
  BTSerial.begin(38400);
  theDoor._setup();
  pinMode(buttonPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BTSerial.available()) {
    data = BTSerial.readString();
    if (data == "Aç") {
      theDoor._open();
    } else if (data == "Kapat") {
      theDoor._close();
    }
  }else if(digitalRead(buttonPin) == 1){
    if(theDoor.isOpened)
      theDoor._close();
    else
      theDoor._open();
    delay(200);
  }
}
