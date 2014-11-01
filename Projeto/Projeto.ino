#include "SevSeg.h" 
   
SevSeg sevseg;  
int start = A1;
int centena = A2;
int dezena = A3;
int unidade = A4;
int rele = A5;
int buzzer = 13;
int centenaNumber = 0;
int dezenaNumber = 0;
int unidadeNumber = 0;
int regressivo = 000;
int atual = 0;
int anterior = 0;
boolean comecar = false;

void setup() 
{  
  sevseg.Begin(false, false,10,11,12,2,3,4,5,6,7,8,9);  
  sevseg.Brightness(20);
  pinMode(start, INPUT);
  pinMode(centena, INPUT); 
  pinMode(dezena, INPUT);
  pinMode(unidade, INPUT);
  pinMode(rele, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(rele, LOW);
  digitalWrite(buzzer, LOW);
  Serial.begin(9600);  
}  
   
void loop() 
{
  atual = ((int) millis() / 1000);  
  if(digitalRead(start) == 1){
    if(comecar == false){
      comecar = true;
    }else{
      comecar = false;      
    }    
    delay(200);
  }
  if(digitalRead(centena) == 1){
    if(centenaNumber < 9){
      centenaNumber = centenaNumber++;
    }else{
      centenaNumber = 0;
    }    
    regressivo = (centenaNumber * 100) + (dezenaNumber * 10) + unidadeNumber;
    delay(200);
  }
  if(digitalRead(dezena) == 1){
    if(dezenaNumber < 9){
      dezenaNumber = dezenaNumber++;
    }else{
      dezenaNumber = 0;
    }    
    regressivo = (centenaNumber * 100) + (dezenaNumber * 10) + unidadeNumber;
    delay(200);
  }
  if(digitalRead(unidade) == 1){
    if(unidadeNumber < 9){
      unidadeNumber = unidadeNumber++;
    }else{
      unidadeNumber = 0;
    }    
    regressivo = (centenaNumber * 100) + (dezenaNumber * 10) + unidadeNumber;
    delay(200);
  }
  if(comecar == true){
    if(atual != anterior){
      anterior = atual;
      diminuirTempo();
    }else{
      digitalWrite(buzzer, LOW);
    }
  }
  sevseg.PrintOutput(); 
  sevseg.NewNum(regressivo,(byte) 2);
}

void diminuirTempo(){
  if(unidadeNumber > 0){
    unidadeNumber = unidadeNumber--;
    regressivo = (centenaNumber * 100) + (dezenaNumber * 10) + unidadeNumber; 
    acoes(regressivo);
  }else{
    if(dezenaNumber > 0){
      dezenaNumber = dezenaNumber--;
      unidadeNumber = 9;
      regressivo = (centenaNumber * 100) + (dezenaNumber * 10) + unidadeNumber; 
      acoes(regressivo);
    }else{
      if(centenaNumber > 0){
        unidadeNumber = 9;
        dezenaNumber = 9;
        centenaNumber = centenaNumber--;
        regressivo = (centenaNumber * 100) + (dezenaNumber * 10) + unidadeNumber; 
        acoes(regressivo);
      }else{
        digitalWrite(rele, HIGH);
        digitalWrite(buzzer, HIGH);
        delay(500);
        comecar = false;
        digitalWrite(rele, LOW);
        digitalWrite(buzzer, LOW);
      }
    }
  }   
}

void acoes(int tempo){
  Serial.println(tempo);
  if(tempo < 6 && tempo >= 0){
    digitalWrite(buzzer, HIGH);
  }
}
