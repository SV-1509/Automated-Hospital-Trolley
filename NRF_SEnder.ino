#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN         
const byte address[6] = "00001";     //Byte of array representing the address. This is the address where we will send the data. This should be same on the receiving side.
int forward = 2;
int backward = 3;
int left = 4;
int right = 5;
int aboutturn = 6;
//1-Forward
//2-Backeard
//3-Left
//4-Right
//5-Aboutturn
void setup() 
{
  for(int i=2;i<7;i++)
  {
    pinMode(i, INPUT_PULLUP);
  }
   for(int i=14;i<19;i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  Serial.begin(9600);
  radio.begin();                  //Starting the Wireless communication
  radio.openWritingPipe(address); //Setting the address where we will send the data
  radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.stopListening();          //This sets the module as transmitter
}
void loop()
{
 int f = digitalRead(2);
 int b = digitalRead(3);
 int l = digitalRead(4);
 int r = digitalRead(5);
 int a = digitalRead(6);
  
  if(f == 0)
  {
    int text =1;
    radio.write(&text, sizeof(text));                  //Sending the message to receiver
    Serial.println("1");
  }
  else if(b == 0)
  {
    int text =2;
    radio.write(&text, sizeof(text));                  //Sending the message to receiver 
    Serial.println("Backward");
  }
  else if(l == 0)
  {
    int text =3;
    radio.write(&text, sizeof(text)); 
    Serial.println("Left");  
  }                   
  else if(r == 0)
  {
    int text =4;
    radio.write(&text, sizeof(text));                  //Sending the message to receiver 
    Serial.println("Right");
  }
  else if(a == 0)
  {
    int text =5;
    radio.write(&text, sizeof(text));                  //Sending the message to receiver 
    Serial.println("AboutTurn");
  }
  //f=0;
  //b=0;
  //l=0;
  //r=0;
  //a=0;
  //radio.write(&button_state, sizeof(button_state));  //Sending the message to receiver 
  delay(100);
}
