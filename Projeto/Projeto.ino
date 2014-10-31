int const buttonInterval1 = 10;
int const buttonInterval2 = 9;
int const buttonInterval3 = 8;
int const buttonShow = 9;
int display1 = 0;
int display2 = 0;
int display3 = 0;
int counter = 1000;
int timer = 5000;
boolean show = false;

void setup() {
  Serial.begin(9600);
  pinMode(buttonInterval1, INPUT);
  pinMode(buttonInterval2, INPUT);
  pinMode(buttonInterval3, INPUT);
  pinMode(buttonShow, INPUT);
}

void loop() {
  if(getShow() == true){
    actions();
    setTimer(getTimer() - 1000); 
    delay(1000);
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
      getCounter(getInterval());
    }
    delay(100);
  }
}

void finish(){
  setShow(false);
  display1 = 0;
  display2 = 0;
  display3 = 0;
  timer = 5000;
}

void actions(){
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

int getInterval(){
  return (getInterval1() * 100) + (getInterval2() * 10) + getInterval3();
}

void getCounter(int new_interval){
  setTimer(new_interval);
}

void showDisplay(){
  Serial.println((getInterval1() * 100) + (getInterval2() * 10) + getInterval3());
}

void setShow(boolean new_show){
  show = new_show;
}

int getShow(){
  return show;
}

void setTimer(int new_timer){
  if(new_timer > 0){
    timer = new_timer;
    setShow(true); 
  }else{
    finish();
  }
}

int getTimer(){
  return timer;
}
