#include <Arduino.h>
const uint8_t pin0 =2;
const uint8_t pin1 =3;
const uint8_t pin2 =4;
const uint8_t pin3 =5;
const uint8_t uppin =11;
const uint8_t downpin =8;
uint8_t count;
unsigned long up_lastdebounceTime = 0;
unsigned long down_lastdebounceTime = 0;
unsigned long debouncedelay = 70;
bool up_buttonstateC = 0;
bool up_pre_buttonstate = 0;
bool down_buttonstateC = 0;
bool down_pre_buttonstate = 0;

void setup() {
  pinMode(pin0, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(uppin, INPUT_PULLUP);
  pinMode(downpin, INPUT_PULLUP);
  digitalWrite(pin0, LOW);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
}

void loop() {
  up_buttonstateC = digitalRead(uppin);
  down_buttonstateC = digitalRead(downpin);
  if(up_buttonstateC != up_pre_buttonstate){
    if(millis() - up_lastdebounceTime >= debouncedelay){
      if(up_buttonstateC == LOW){
      count++;
      if(count > 15){
      count = 0;
     }
      up_lastdebounceTime = millis();
     digitalWrite(pin0, (count >> 0) & 1);
     digitalWrite(pin1, (count >> 1) & 1);
     digitalWrite(pin2, (count >> 2) & 1);
     digitalWrite(pin3, (count >> 3) & 1);
    
    }
  }
}
  up_pre_buttonstate = up_buttonstateC;

if(down_buttonstateC != down_pre_buttonstate){
  if(millis() - down_lastdebounceTime >= debouncedelay){
    if(down_buttonstateC == LOW){
     count--;
     if(count == 255){
      count = 15;
     }
      down_lastdebounceTime = millis();
     digitalWrite(pin0, (count >> 0) & 1);
     digitalWrite(pin1, (count >> 1) & 1);
     digitalWrite(pin2, (count >> 2) & 1);
     digitalWrite(pin3, (count >> 3) & 1);
    
    }
  }
} 
  down_pre_buttonstate = down_buttonstateC;
}