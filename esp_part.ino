#include <ESP8266WiFi.h>;
 
#include <WiFiClient.h>;
 
#include <ThingSpeak.h>;
 
const char* ssid = "utshariya"; //Your Network SSID
 
const char* password = "amiriya98"; //Your Network Password
 
int data;
 
int LDRpin = A0; //LDR Pin Connected at A0 Pin
 
 
 
WiFiClient client;
 
unsigned long myChannelNumber = 866316; //Your Channel Number (Without Brackets)
 
const char * myWriteAPIKey = "LOFD5CAALXBGIXIL"; //Your Write API Key
 
void setup()
 
{
 
Serial.begin(9600);
 
delay(10);
 
// Connect to WiFi network
 
WiFi.begin(ssid, password);
 
 
 
ThingSpeak.begin(client);
 
}
 
 
int actual = 840;
void loop()
 
{

 if (Serial.available())
  {
    data=Serial.read();
    Serial.println(data);
    
    

    delay(1000);
 
ThingSpeak.writeField(myChannelNumber, 2,data, myWriteAPIKey); //Update in ThingSpeak

 
 
delay(100);
  }

 

 

}
 
