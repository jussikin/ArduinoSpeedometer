#include <Arduino.h>
#include <TM1637Display.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

#define CLK 12
#define DIO 11
TM1637Display display(CLK, DIO);
SoftwareSerial mySerial(2, 3);
TinyGPSPlus gps;

void setup() { 
  mySerial.begin(38400);
  display.setBrightness(0x08);
}

void loop() { // run over and over
   while (mySerial.available() > 0)
    if (gps.encode(mySerial.read())){
      setDisplay();
    }
}

void setDisplay(){
  if(gps.speed.isValid()){
    double speed = gps.speed.kmph();
    if(speed>10){
       display.showNumberDec(speed,false,4,0);
       return;
    }
  }
  if(gps.time.isValid()){
    int minutes = gps.time.minute();   
    display.showNumberDec(minutes,true,2,2);
    int hours = gps.time.hour();
    hours = hours+2;
    if(hours>24)
      hours=hours-24;
    display.showNumberDec(hours,true,2,0);
  }
}

