const byte Button1 = 2;
const byte Button2 = 4;

byte ButtonState1;
byte lastState1 = LOW;

byte ButtonState2;
byte lastState2 = LOW;

byte ButtonState3;
byte lastState3 = LOW;

byte ButtonState4;
byte lastState4 = LOW;

byte menuNumber = 0;

boolean printed = 0;

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
//************************************************************************
//************************************************************************

void m0() {
  if (!printed) {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Watering sys");
    lcd.setCursor(1, 1);
    lcd.print("Moister lvl");
    printed = 1;
  }

  if (ButtonState1 && ButtonState1 != lastState1) // button latch, no debounce needed.
  {

    menuNumber = 1;
    printed = 0;

  }
  lastState1 = ButtonState1;


  if (ButtonState2 && ButtonState2 != lastState2) // button latch, no debounce needed.
  {
    menuNumber = 2;
    printed = 0;
  }
  lastState2 = ButtonState2;

}
//************************************************************************
//************************************************************************
void m1() {
  if (!printed) {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Select plant");
    lcd.setCursor(1, 1);
    lcd.print("based system");
    printed = 1;
  }

  if (ButtonState1 && ButtonState1 != lastState1) // button latch, no debounce needed.
  {

    menuNumber = 2;
    printed = 0;

  }
  lastState1 = ButtonState1;


  if (ButtonState2 && ButtonState2 != lastState2) // button latch, no debounce needed.
  {
    menuNumber = 0;
    printed = 0;
  }
  lastState2 = ButtonState2;

  if (ButtonState3 && ButtonState3 != lastState3) // button latch, no debounce needed.
  {
    menuNumber = 11;
    printed = 0;
  }
  lastState3 = ButtonState3;

//  if (ButtonState4 && ButtonState4 != lastState4) // button latch, no debounce needed.
//  {
//    menuNumber = 0;
//    printed = 0;
//  }
//  lastState4 = ButtonState4;
//}

//************************************************************************
//************************************************************************


//************************************************************************
//************************************************************************


//************************************************************************
//************************************************************************


//************************************************************************
//************************************************************************


//************************************************************************
//************************************************************************

void m2() {
  if (!printed) {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Select frequency");
    lcd.setCursor(1, 1);
    lcd.print("based system");
    printed = 1;
  }

  if (ButtonState1 && ButtonState1 != lastState1) // button latch, no debounce needed.
  {

    menuNumber = 0;
    printed = 0;

  }
  lastState1 = ButtonState1;


  if (ButtonState2 && ButtonState2 != lastState2) // button latch, no debounce needed.
  {
    menuNumber = 1;
    printed = 0;
  }
  lastState2 = ButtonState2;
}

void printMenuOnLCD() {



  switch (menuNumber) {
    case 0:
      m0(); break;
      break;
    case 1:
      m1(); break;
    case 2:
      m2(); break;
    case 32:
      lcd.setCursor(1, 0);
      lcd.print("menu 3");    break;
    case 42:
      lcd.setCursor(1, 0);
      lcd.print("menu 4");    break;
    case 52:
      lcd.setCursor(1, 0);
      lcd.print("menu 5");    break;
    default:
      lcd.setCursor(1, 0);
      lcd.print("menu 0");    break;
  }

  //  lcd.print(menuItems[menuPage]);
  //  lcd.setCursor(1, 1);
  //  lcd.print(menuItems[menuPage + 1]);
}

void setup() {
  Serial.begin(9600);
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);

  lcd.begin(16, 2);

  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Automatic Plant");
  lcd.setCursor(1, 1);
  lcd.print("Watering System");

  delay(4000);

  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Team");
  lcd.setCursor(1, 1);
  lcd.print("sorry I forgot");
  delay(4000);
  menuNumber = 0;

}

void loop() {
  ButtonState1 = digitalRead(Button1);
  ButtonState2 = digitalRead(Button2);
  Serial.println(menuNumber);
  printMenuOnLCD();
  delay(100);



}
