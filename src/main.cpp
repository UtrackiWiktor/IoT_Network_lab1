#include <Arduino.h>
#include <LiquidCrystal.h>

#define LED_BUILTIN 14

// ex. 1 print in serial
//ex 2. print on LCD
// ex 3 button increment + LCD
const int rs = 12, en = 13, d4 = 4, d5 = 0, d6 = 2, d7 = 14;
const int buttonPin = A0;  
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int buttonState = 0; 
int counter = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  //pinMode(LED_BUILTIN, OUTPUT);

  lcd.print("C < Python");
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  Serial.print(counter);
  // digitalWrite(LED_BUILTIN, HIGH);
   delay(300);
  // digitalWrite(LED_BUILTIN, LOW);
  // delay(500)
  buttonState = analogRead(buttonPin);
  if(buttonState > 0)
  {
    counter++;
    buttonState = 0;
  }
  lcd.setCursor(0,1);
  Serial.println(counter);
}