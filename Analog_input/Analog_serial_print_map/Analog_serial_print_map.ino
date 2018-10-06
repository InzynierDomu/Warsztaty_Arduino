const int sensorPin = A0; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin); 
  int convertedValue = map(sensorValue, 1, 1024, 0, 100); //mapowanie, jeśli chcemy od razu przeliczyć wartość
  Serial.println(convertedValue);
  delay(100);
}
