const int WYJSCIE = 13;

void setup() {
  pinMode(WYJSCIE, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) //sprawdzanie czy coś nie pojawiło się na porcie
  {
    char stan = Serial.read(); //pamiętajmy że są to znaki
    if (stan == '1') digitalWrite(WYJSCIE, HIGH); //kiedy przy warunku ma się wykonać jedna rzecz, możemy zapisać bez nawiasów
    else digitalWrite(WYJSCIE, LOW);
  }
}
