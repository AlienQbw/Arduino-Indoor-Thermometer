#include <dht.h>
#include <LiquidCrystal.h>

// LCD pins <--> Arduino pins
const int RS = 11, EN = 12, D4 = 2, D5 = 3, D6 = 4, D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
dht DHT;

#define DHT11_PIN 7

void setup(){
  Serial.begin(9600);

  lcd.begin(16, 2); // set up number of columns and rows

  lcd.setCursor(0, 0);  // move cursor to   (0, 0)
  lcd.print("");        // print message at (0, 0)
  lcd.setCursor(2, 1);  // move cursor to   (2, 1)
  lcd.print("");        // print message at (2, 1)
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  if(DHT.humidity > 0 || DHT.temperature > 0){
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
  lcd.setCursor(12, 0);
  lcd.print(DHT.temperature);
  lcd.setCursor(0, 1);
  lcd.print("Humidity:");
  lcd.setCursor(10, 1);
  lcd.print(DHT.humidity);
  }
  
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(5000);
}
