//część która wykonuje się jednorazowo na początku
void setup() {
  pinMode(13, OUTPUT);  //ustawienie pinu 13 jako wyjście (tutaj podpięta jest LED)
}

//pętla ktora wykonuje się cały czas, w kółko 
void loop() {
  digitalWrite(13, HIGH);   //ustawienie stanu wysokiego na pinie 13 (LED świeci) 
  delay(1000);              //program przez 1000 milisekund nic nie robi
  digitalWrite(13, LOW);    //ustawienie stanu niskiego na pinie 13 (LED wygaszona)
  delay(1000);              //program przez 1000 milisekund nic nie robi
}
