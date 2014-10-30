int const buttonInterval = 10;
int const buttonShow = 9;
int intervals[] = { 15000, 30000, 45000, 60000, 90000, 120000 };
int interval = 0;
int counter = 1000;
int timer = 5000;
boolean show = false;

void setup() {
  Serial.begin(9600);
  pinMode(buttonInterval, INPUT);
  pinMode(buttonShow, INPUT);
}

void loop() {
  if(getShow() == true){
    actions();
    setTimer(getTimer() - 1000); 
    delay(1000);
  }else{
    if(digitalRead(buttonInterval) == 1){
      setInterval(getInterval() + 1);
    }
    if(digitalRead(buttonShow) == 1){    
      getCounter(getInterval());
    }
    delay(100);
  }
}

void finish(){
  setShow(false);
  interval = 0;
  timer = 5000;
}

void actions(){
}

void setInterval(int new_interval){
  if(new_interval <= 5){
    interval = new_interval;
  }else{
    interval = 0;
  }
}

int getInterval(){
  return interval;
}

void getCounter(int new_counter){
  setTimer(intervals[new_counter]);
  setShow(true); 
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
  }else{
    finish();
  }
}

int getTimer(){
  return timer;
}
