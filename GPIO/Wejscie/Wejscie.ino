void setup() {
  Serial.begin(9600);  //ustawienie prędkości portu szeregowego na 9600 bodów 
  pinMode(13, INPUT);  //ustawienie pinu 13 jako wejścia
}

void loop() {
  int stan = digitalRead(13); //odczytanie stanu na pinie 13 (wysoki lub niski)  
  Serial.println(stan);       //wysłanie przez port szeregowy informacji o stanie wejścia (1 lub 0)
  delay(1000);              
}
