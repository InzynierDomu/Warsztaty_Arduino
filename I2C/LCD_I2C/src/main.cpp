#include <Arduino.h>
#include <Wire.h>             
#include <LiquidCrystal_I2C.h>  
 
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  

void setup() {
  lcd.begin(16,4);
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print("PCF8574 i LCD");
  lcd.setCursor(0, 2);
  lcd.print("InzynierDomu.pl");
}

void loop() {
}