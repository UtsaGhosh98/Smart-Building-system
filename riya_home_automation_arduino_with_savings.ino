
#include <Ultrasonic.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#include <SoftwareSerial.h>
SoftwareSerial a(5,6);  //rx - tx of nodemcu , tx


int on_time = 0;          //count the actual time
int total_time = 0;       //count the total time
int saving = 0;

//vcc - 5v
//gnd = gnd
//sda = A5
//scl = A4

Ultrasonic ultrasonic1(2,3); // (Trig PIN,Echo PIN)   //entry
Ultrasonic ultrasonic2(12,13); // (Trig PIN,Echo PIN)   //exit

LiquidCrystal_I2C lcd(0x3F,20,4); 

int count = 0;          //PERSON'S IN THE ROOM
int relay1 = 7;
int relay2 = 8;     

void setup() {
  pinMode(relay1,OUTPUT);
  Serial.begin(9600); 
  a.begin(115200);
  lcd.init();                      // initialize the lcd 
  
  // Print a message to the LCD.
  lcd.backlight();
  
}

void loop()
{
  
  int data1 = 0,data2=0;
   data1 = ultrasonic1.Ranging(CM);
  if(data1<20){
 delay(500);
   data2 = ultrasonic2.Ranging(CM);
  if(data2<20){
      
      count --;
       if(count<0){
          count  = 0;}
        Serial.println("exit");
        lcd.setCursor(3,0);
        lcd.print("EXIT");
        
       
       goto a;
  }
  }
data1 = data2 =0;


   data2 = ultrasonic2.Ranging(CM);
  if(data2<20){
 delay(500);
   data1 = ultrasonic1.Ranging(CM);
  if(data1<20){
    lcd.setCursor(3,0);
        lcd.print("ENTRY");
      Serial.println("entry");
      count ++;
     
  }
  }
a:
  Serial.println(count);
   
  lcd.setCursor(3,1);
  lcd.print(count);
  if(count >0){
    digitalWrite(relay1,LOW);
    digitalWrite(relay2,LOW);
    on_time++;
  }
      
  else{
    digitalWrite(relay1,HIGH);
 
      digitalWrite(relay2,HIGH);
  }

total_time++;
  //delay(3000);

  saving = (on_time/total_time)*100;
  a.write(saving);
  // Serial.print(data1); // CM or INC
  //Serial.print(" ," );
  //Serial.println(data2); // CM or INC
  
  //delay(100);
}
