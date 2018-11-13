const int DT = 2; 
const int CLK = 3; 
 
unsigned long time = 0; 
long ilosc_impulsow = 0; 
long licznik = 0;
 
void setup()
{
 Serial.begin(9600);
 
 pinMode(DT,INPUT); 
 pinMode(CLK,INPUT); 

 //przerwania
 attachInterrupt(digitalPinToInterrupt(DT), dekrementacja, LOW); 
 attachInterrupt(digitalPinToInterrupt(CLK), inkrementacja, LOW); 
 
 time = millis(); 
}
 
void loop()
{
 while (licznik != ilosc_impulsow)
 {
 licznik = ilosc_impulsow;
 Serial.println(licznik);
 }
}

//osobne metody wywoływane od przerwań 
void dekrementacja()
{
 if ((millis() - time) > 3)
 ilosc_impulsow--; 
 time = millis();
}
 
void inkrementacja()
{
 if ((millis() - time) > 3) 
 ilosc_impulsow++ ;
 time = millis();
}
