#include <Arduino.h>

const byte PIN_LED_R = 4;
const byte PIN_LED_Y = 5;
const byte PIN_LED_G = 6;
const byte PIN_BUTTON = 12;

void setup() {
  pinMode(PIN_LED_R, OUTPUT);
  digitalWrite(PIN_LED_R, LOW);
  pinMode(PIN_LED_Y, OUTPUT);
  digitalWrite(PIN_LED_Y, LOW);
  pinMode(PIN_LED_G, OUTPUT);
  digitalWrite(PIN_LED_G, LOW);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
}

void loop() {
  static int state = 0;
  static long last_loop_time = 0;

  long loop_time = millis();
  if(loop_time - last_loop_time > 1000)
  {
    state++;  
    last_loop_time = millis();
  } 
    
  if(digitalRead(PIN_BUTTON) == LOW)
  {
    digitalWrite(PIN_LED_R, HIGH);
    digitalWrite(PIN_LED_Y, HIGH);
    digitalWrite(PIN_LED_G, HIGH);
  }
  
  else
  {
    switch(state)
    {
    case 0:
        digitalWrite(PIN_LED_Y, LOW);
        digitalWrite(PIN_LED_R, HIGH);
        break;
    case 1:
        digitalWrite(PIN_LED_Y, HIGH);
        break;
    case 2:
        digitalWrite(PIN_LED_R, LOW);
        digitalWrite(PIN_LED_Y, LOW);
        digitalWrite(PIN_LED_G, HIGH);
        break;
    case 3:
        digitalWrite(PIN_LED_G, LOW);
        digitalWrite(PIN_LED_Y, HIGH);
        state = -1;
        break;
    default:
        break;
    }     
  }
}