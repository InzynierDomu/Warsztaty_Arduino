#include <Arduino.h>

const byte PIN_LED_R = 4;
const byte PIN_LED_Y = 5;
const byte PIN_LED_G = 6;
const byte PIN_BUTTON = 12;
const int change_time = 1000;

enum class light_state
{
  green,
  yelow,
  red,
  yelow_and_red
};

void setup() 
{
  pinMode(PIN_LED_R, OUTPUT);
  digitalWrite(PIN_LED_R, LOW);
  pinMode(PIN_LED_Y, OUTPUT);
  digitalWrite(PIN_LED_Y, LOW);
  pinMode(PIN_LED_G, OUTPUT);
  digitalWrite(PIN_LED_G, LOW);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
}

void change_light()
{
  static light_state state = light_state::red;

  switch(state)
  {
  case light_state::red:
    digitalWrite(PIN_LED_G, LOW);
    digitalWrite(PIN_LED_R, HIGH);
    digitalWrite(PIN_LED_Y, LOW);
    state = light_state::yelow_and_red;
    break;
  case light_state::yelow:
    digitalWrite(PIN_LED_G, LOW);
    digitalWrite(PIN_LED_R, LOW);
    digitalWrite(PIN_LED_Y, HIGH);
    state = light_state::red;
    break;
  case light_state::green:
    digitalWrite(PIN_LED_G, HIGH);
    digitalWrite(PIN_LED_R, LOW);
    digitalWrite(PIN_LED_Y, LOW);
    state = light_state::yelow;
    break;
  case light_state::yelow_and_red:
    digitalWrite(PIN_LED_G, LOW);
    digitalWrite(PIN_LED_R, HIGH);
    digitalWrite(PIN_LED_Y, HIGH);
    state = light_state::green;
    break;
  default:
    break;
  }
}

void loop() 
{  
  static long last_loop_time = 0;
  long loop_time = millis();

  if(digitalRead(PIN_BUTTON) == LOW)
  {
    digitalWrite(PIN_LED_G, HIGH);
    digitalWrite(PIN_LED_R, HIGH);
    digitalWrite(PIN_LED_Y, HIGH);
  }
  else
  {
    if(loop_time - last_loop_time > change_time)
    {
      change_light();
      last_loop_time = millis();
    } 
  } 
}