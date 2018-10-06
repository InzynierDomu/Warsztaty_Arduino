const int WEJSCIE = 12;

void setup() {
  pinMode(WEJSCIE, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int stan = digitalRead(WEJSCIE);
  Serial.println(stan);
  delay(10);
}
