#include "DHT.h"
#include <LiquidCrystal_I2C.h>

//NOTE: setCursor must be set i=i-1 where i is index to print

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define pin_dht11 2 //D2

//Arduino Nano: sda on A4, scl on A5
#define minute 60000

//istantiation of DHT class
DHT dht(pin_dht11, DHT11, 6); 

void setup()
{
  lcd.clear();
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("Hello antonio!");
  delay(2000);
  lcd.clear();
  
  dht.begin();
  
 
}

void loop()
{
  int t = dht.readTemperature();
  int h = dht.readHumidity();


  //TEMPERATURE
  //set the cursor at column 0 and row 0
  lcd.setCursor(0, 0);
  lcd.print("Temperatura:");
  if(t<10){
    //set the cursor at column 13 and row 0
    lcd.setCursor(13, 0);
    lcd.print(t);
    //ASCI per °
    lcd.print((char)223);
    lcd.print("C");
  }
  if (t>=10 && t<100){
    //set the cursor at column 12 and row 0
    lcd.setCursor(12, 0);
    lcd.print(t);
    //ASCII per °
    lcd.print((char)223);
    lcd.print("C");
  }
  if(t>=100){
     lcd.print("Errore");
  }



  //HUMIDITY

  //set the cursor at column 0 and row 1
  lcd.setCursor(0, 1);
  lcd.print("Umidita':");
  if (h<10) {
       lcd.setCursor(14, 1);
       lcd.print(h);
       lcd.print("%");
  }
  if (h>=10 && h<100){
       lcd.setCursor(13, 1);
       lcd.print(h);
       lcd.print("%");
  }
  if (h>=100){
    lcd.print("Errore");
  }
  
  delay(minute);
 

 
}
