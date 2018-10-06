const int sensorPin = A0;   //tutaj podpięte jest wyjście analogowe z czujnika

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin); //odczyt wartości z czujnika
  Serial.println(sensorValue);
  delay(100);
}
