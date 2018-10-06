#define WEJSCIE 12 
const int WYJSCIE = 13;
//dwa zapisy aby używac nazw a nie numerów pinów
//ten drugi jest bardziej poprawny
//do opisów stałych używa się najczęściej samych dużych liter

void setup() {
  pinMode(WEJSCIE, INPUT_PULLUP);  //pullup czyli podciągnięty do stanu wysokiego, coś jak domyslny stan
  pinMode(WYJSCIE, OUTPUT);
}

void loop() {
  int stan = digitalRead(WEJSCIE); 
  digitalWrite(WYJSCIE, stan);
  //można to wpisać w jednej lini o tak:
  //digitalWrite(WYJSCIE, digitalRead(WEJSCIE));
  //jest to już jednak mniej czytelne
  delay(10);   
  //stan będzie sprawdzany co 10 milisekund           
}
