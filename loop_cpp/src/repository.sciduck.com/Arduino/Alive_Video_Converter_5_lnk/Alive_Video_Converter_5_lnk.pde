///-------------------------------------
/// INCLUDES
///-------------------------------------
#include <Client.h>
#include <Ethernet.h>
#include <Server.h>
#include <Udp.h>
#include <SPI.h>
///-------------------------------------
/// GLOBAL VARIABLES
///-------------------------------------
// Ethernet shield's sticker MAC address.
byte mac[] = {0x90, 0xA2, 0xDA, 0x00, 0x23, 0x13};
// Assumed IP address
byte ipAddr[] = {192, 168, 1, 3};
// PINS
const int A = 10, B = 11, C = 12, D = 13, SEC = 1000;

void setup()
{
  // Initialize the Ethernet class
  Ethernet.begin(mac, ipAddr);
  /******** Initialize Pins *******/
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  /********************************/
}

void loop()
{
  //start();
}

// Entry point
void start()
{
  int i;
  for(i = 0; 1; i++)
  {
    if(i % 10 == 0)
    {
      digitalWrite(A, !digitalRead(A));
      delay(SEC);
    }
    else if(i % 100 == 0)
    {
      digitalWrite(B, !digitalRead(B));
      delay(SEC);
    }
    else if(i % 1000 == 0)
    {
      digitalWrite(C, !digitalRead(C));
      delay(SEC);
    }
    else if(i % 10000 ==0)
    {
      digitalWrite(D, !digitalRead(D));
      delay(SEC);
      i = 0;
    }
  }  
}
