#include <Arduino.h>

char data;

void  odlicz()
{
  for (size_t i = 0; i < 10; i++)
  {
    digitalWrite(13, HIGH);
    Serial.println("Stan wysoki");
    delay(350);
    digitalWrite(13, LOW);
    Serial.println("Stan niski");
    delay(350);
      
  }
  digitalWrite(13, LOW);
  Serial.println("Koniec odliczania");
  
}


void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  

 if(Serial.available())
 {
    data = Serial.read();
    Serial.println(data);
    switch (data)
    {
    case 'o': digitalWrite(13, HIGH);
      break;
    case 'f': digitalWrite(13, LOW);
      break;
    case 'l': odlicz();
      break;   
    }
 }

}