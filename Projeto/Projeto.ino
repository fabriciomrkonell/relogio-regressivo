#include "SevSeg.h"

SevSeg sevseg;

int const buttonInterval1 = 10;
int const buttonInterval2 = 9;
int const buttonInterval3 = 8;
int const buttonShow = 9;
int display1 = 0;
int display2 = 0;
int display3 = 0;
int timer = 0;
boolean show = false;

void setup() {
  Serial.begin(9600);
  pinMode(buttonInterval1, INPUT);
  pinMode(buttonInterval2, INPUT);
  pinMode(buttonInterval3, INPUT);
  pinMode(buttonShow, INPUT);
  //sevseg.Begin(1,13,10,11,12,2,3,4,5,6,7,8,9);  
  //sevseg.Brightness(50);
}

void loop() {
  if(getShow() == true){
    if(setTimer(getTimer() - 1) == true){
      actions();
      showDisplay();
      delay(1000);
    }
  }else{
    if(digitalRead(buttonInterval1) == 1){
      setInterval1(getInterval1() + 1);
      showDisplay();
      delay(800);
    }
    if(digitalRead(buttonInterval2) == 1){
      setInterval2(getInterval2() + 1);
      showDisplay();
      delay(800);
    }
    if(digitalRead(buttonInterval3) == 1){
      setInterval1(getInterval3() + 1);
      showDisplay();
      delay(800);
    }
    if(digitalRead(buttonShow) == 1){    
      setTimer(getCounter());
      delay(1000);
    }
    delay(100);
  }
}

void finish(){
  setShow(false);
  display1 = 0;
  display2 = 0;
  display3 = 0;
  timer = 0;
}

void actions(){
}

int getCounter(){
  return ((getInterval1() * 100) + (getInterval2() * 10) + getInterval3());
}

void setInterval1(int new_interval){
  if(new_interval <= 9){
    display1 = new_interval;
  }else{
    display1 = 0;
  } 
}

void setInterval2(int new_interval){
  if(new_interval <= 9){
    display2 = new_interval;
  }else{
    display2 = 0;
  }
}

void setInterval3(int new_interval){
  if(new_interval <= 9){
    display3 = new_interval;
  }else{
    display3 = 0;
  }
}

int getInterval1(){
  return display1;
}

int getInterval2(){
  return display2;
}

int getInterval3(){
  return display3;
}

void showDisplay(){
  //sevseg.PrintOutput();  
  //sevseg.NewNum(getCounter(),(byte) 2);  
  Serial.println(getCounter());
}

void setShow(boolean new_show){
  show = new_show;
}

int getShow(){
  return show;
}

boolean setTimer(int new_timer){
  if(new_timer > 0){
    timer = new_timer;
    setShow(true);
    return true;
  }else{    
    finish();
    return false;
  }
}

int getTimer(){
  return timer;
}
