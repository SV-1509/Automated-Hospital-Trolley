#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
//38 - Right Motor forward
//42  - Left Motor forward
//36 - Right Motor backward
//40  - Left Motor backward
char a='S';
void forward()
{
  
    digitalWrite(38,1);
    digitalWrite(42,1);
    digitalWrite(36,0);
    digitalWrite(40,0);
    Serial.println("Forward");
    
}
void backward()
{
   
    digitalWrite(36,1);
    digitalWrite(40,1);
    digitalWrite(38,0);
    digitalWrite(42,0);
    Serial.println("Backward");
    
}
void left()
{
  
    digitalWrite(38,1);
    digitalWrite(36,0);
    Serial.println("Left");
    
}
void right()
{
  
    digitalWrite(42,1);
    digitalWrite(40,0);
    Serial.println("Right");
    
}
void aboutturn()
{
  
    digitalWrite(38,1);
    digitalWrite(40,1);
    digitalWrite(36,0);
    digitalWrite(42,0);
    Serial.println("AboutTurn");
    
}
void stopnow()
{
    digitalWrite(36,1);
    digitalWrite(42,1);
    digitalWrite(38,1);
    digitalWrite(40,1);
    Serial.println("Stopped");
}
void setup() 
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  for (int i=36;i<=42;i+=2)
   { 
     pinMode(i,OUTPUT);
   }
}
void loop() {
  char p[]="Forward";
  if (radio.available()) 
  {
     int stringOne = 0;
     radio.read(&stringOne, sizeof(stringOne));
     Serial.println(stringOne);
     //Serial.println(p);
     if (stringOne==1)
     {
         forward();
     }
     if (stringOne==2)
     {
         backward();
     }
     if (stringOne==3)
     {
         left();
     }
     if (stringOne==4)
     {
         right();
     }
     if (stringOne==5)
     {
      
         aboutturn();
     }
     //stopnow(); 
  }
  delay(100);
  stopnow();
}
