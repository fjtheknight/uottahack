const byte Button1 = 2;
const byte Button2 = 4;
const byte Button3 = 3;
const byte Button4 = 7;

String wateringSystem = "Not Slect.";
String plant = "-";
String frequency = "-";
String moisture = "-";
String watering = "-";

int moistLevel = 0;



int val = 0; //value for storing moisture value
int soilPin = A0;//Declare a variable for the soil moisture sensor
int soilPower = 7;//Variable for Soil moisture Power



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


unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long period = 10000;  //the value is a number of milliseconds


unsigned long startMillisWatering;  //some global variables available anywhere in the program
unsigned long currentMillisWatering;
const unsigned long periodWatering = 10000;  //the value is a number of milliseconds


#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;



//************************************************************************
//************************************************************************
int readSoil()
{

  digitalWrite(soilPower, HIGH);//turn D7 "On"
  delay(10);//wait 10 milliseconds
  val = analogRead(soilPin);//Read the SIG value form sensor
  digitalWrite(soilPower, LOW);//turn D7 "Off"
  return val;//send current moisture value
}


//************************************************************************
//************************************************************************

void m0() {
  if (!printed) {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Wtr:"+watering);
    lcd.setCursor(10, 0);
    lcd.print("Frq:" + frequency);
    lcd.setCursor(10, 1);
    lcd.print(plant);
    lcd.setCursor(0, 1);
    lcd.print("Mst:" + moisture);

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
    lcd.setCursor(2, 0);
    lcd.print("Select plant");
    lcd.setCursor(2, 1);
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
    menuNumber = 10;
    printed = 0;
  }
  lastState3 = ButtonState3;

  //  if (ButtonState4 && ButtonState4 != lastState4) // button latch, no debounce needed.
  //  {
  //    menuNumber = 0;
  //    printed = 0;
  //  }
  //  lastState4 = ButtonState4;
}

//************************************************************************
//************************************************************************

void m10() {
  if (!printed) {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Plant: Tomato");
    lcd.setCursor(1, 1);
    lcd.print("% moisture: 60%");
    printed = 1;
  }

  if (ButtonState1 && ButtonState1 != lastState1) // button latch, no debounce needed.
  {

    menuNumber = 11;
    printed = 0;

  }
  lastState1 = ButtonState1;


  if (ButtonState2 && ButtonState2 != lastState2) // button latch, no debounce needed.
  {
    menuNumber = 11;
    printed = 0;
  }
  lastState2 = ButtonState2;

  if (ButtonState3 && ButtonState3 != lastState3) // button latch, no debounce needed.
  {
    menuNumber = 101;
    printed = 0;
  }
  lastState3 = ButtonState3;

  if (ButtonState4 && ButtonState4 != lastState4) // button latch, no debounce needed.
  {
    menuNumber = 1;
    printed = 0;
  }
  lastState4 = ButtonState4;
}

//************************************************************************
//************************************************************************

void m11() {
  if (!printed) {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Plant: Pepper");
    lcd.setCursor(1, 1);
    lcd.print("% moisture: 70%");
    printed = 1;
  }

  if (ButtonState1 && ButtonState1 != lastState1) // button latch, no debounce needed.
  {

    menuNumber = 10;
    printed = 0;

  }
  lastState1 = ButtonState1;


  if (ButtonState2 && ButtonState2 != lastState2) // button latch, no debounce needed.
  {
    menuNumber = 10;
    printed = 0;
  }
  lastState2 = ButtonState2;

  if (ButtonState3 && ButtonState3 != lastState3) // button latch, no debounce needed.
  {
    menuNumber = 111;
    printed = 0;
  }
  lastState3 = ButtonState3;

  if (ButtonState4 && ButtonState4 != lastState4) // button latch, no debounce needed.
  {
    menuNumber = 1;
    printed = 0;
  }
  lastState4 = ButtonState4;
}

//************************************************************************
//************************************************************************

void m20() {
  if (!printed) {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Frequency:");
    lcd.setCursor(1, 1);
    lcd.print("4 hours");
    printed = 1;
  }

  if (ButtonState1 && ButtonState1 != lastState1) // button latch, no debounce needed.
  {

    menuNumber = 21;
    printed = 0;

  }
  lastState1 = ButtonState1;


  if (ButtonState2 && ButtonState2 != lastState2) // button latch, no debounce needed.
  {
    menuNumber = 21;
    printed = 0;
  }
  lastState2 = ButtonState2;

  if (ButtonState3 && ButtonState3 != lastState3) // button latch, no debounce needed.
  {
    menuNumber = 201;
    printed = 0;
  }
  lastState3 = ButtonState3;

  if (ButtonState4 && ButtonState4 != lastState4) // button latch, no debounce needed.
  {
    menuNumber = 2;
    printed = 0;
  }
  lastState4 = ButtonState4;
}

//************************************************************************
//************************************************************************
void m21() {
  if (!printed) {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Frequency:");
    lcd.setCursor(1, 1);
    lcd.print("12 hours");
    printed = 1;
  }

  if (ButtonState1 && ButtonState1 != lastState1) // button latch, no debounce needed.
  {

    menuNumber = 20;
    printed = 0;

  }
  lastState1 = ButtonState1;


  if (ButtonState2 && ButtonState2 != lastState2) // button latch, no debounce needed.
  {
    menuNumber = 20;
    printed = 0;
  }
  lastState2 = ButtonState2;

  if (ButtonState3 && ButtonState3 != lastState3) // button latch, no debounce needed.
  {
    menuNumber = 211;
    printed = 0;
  }
  lastState3 = ButtonState3;

  if (ButtonState4 && ButtonState4 != lastState4) // button latch, no debounce needed.
  {
    menuNumber = 2;
    printed = 0;
  }
  lastState4 = ButtonState4;
}

//************************************************************************
//************************************************************************

void m101() {
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Plant: Tomato");
  lcd.setCursor(1, 1);
  lcd.print("Selected");

  wateringSystem = "Plant based";
  plant = "Tomato";
  frequency = "-";

  delay(2000);
  menuNumber = 0;
}

//************************************************************************
//************************************************************************

void m111() {
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Plant: Pepper");
  lcd.setCursor(1, 1);
  lcd.print("Selected");

  wateringSystem = "Plant based";
  plant = "Pepper";
  frequency = "-";


  delay(2000);
  menuNumber = 0;
}

//************************************************************************
//************************************************************************

void m201() {
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("4 hours");
  lcd.setCursor(1, 1);
  lcd.print("Selected");

  wateringSystem = "Frequency based";
  frequency = "4";

  delay(2000);
  menuNumber = 0;
}
//************************************************************************
//************************************************************************

void m211() {
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("12 hours");
  lcd.setCursor(1, 1);
  lcd.print("Selected");

  wateringSystem = "Frequency based";
  frequency = "4";

  delay(2000);
  menuNumber = 0;
}
//************************************************************************
//************************************************************************

void m2() {
  if (!printed) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Select frequency");
    lcd.setCursor(2, 1);
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

  if (ButtonState3 && ButtonState3 != lastState3) // button latch, no debounce needed.
  {
    menuNumber = 20;
    printed = 0;
  }
  lastState3 = ButtonState3;

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
    case 10:
      m10();    break;
    case 11:
      m11(); break;
    case 20:
      m20();    break;
    case 21:
      m21(); break;
    case 101:
      m101();    break;
    case 201:
      m201();    break;
    case 111:
      m111();    break;
    case 211:
      m211();    break;
  }

  //  lcd.print(menuItems[menuPage]);
  //  lcd.setCursor(1, 1);
  //  lcd.print(menuItems[menuPage + 1]);
}



String text() {
  String s = "Sensor 1";
  String s1 = "#S|TEST|[";
  String s2 = ";";
  String s3 = "]#";

  s = s1 + s + s2 + moisture + s2 + watering + s2 + wateringSystem + s2 + plant + s2 + frequency + s2 + s3;
  return s;
}

void waterFreq() {
  watering = "yes";

}


void waterMoist() {
  int x = 500;
  if(plant == "Tomato"){
    x = 600;
  } else if(plant == "Pepper"){
    x = 700;
  }
  if (moistLevel <  x) {
    watering = "yes";
  } else {
    watering = "no";
  }


}

void setup() {
  Serial.begin(9600);
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(Button3, INPUT);
  pinMode(Button4, INPUT);


  pinMode(soilPower, OUTPUT);//Set D7 as an OUTPUT
  digitalWrite(soilPower, LOW);//Set to LOW so no power is flowing through the sensor

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
  lcd.print("PowerPlant");
  delay(4000);
  menuNumber = 0;
  startMillis = millis();  //initial start time

}

void loop() {
  ButtonState1 = digitalRead(Button1);
  ButtonState2 = digitalRead(Button2);
  ButtonState3 = digitalRead(Button3);
  ButtonState4 = digitalRead(Button4);



  if (frequency == "4") {
    if (currentMillisWatering - startMillisWatering >= 4 * periodWatering) //test whether the period has elapsed
    {
      waterFreq();
      startMillisWatering = currentMillisWatering;  //IMPORTANT to save the start time of the current LED state.
    } else {
      if (currentMillisWatering - startMillisWatering >= periodWatering) {
        watering = "no";
      }

    }
  }

  else if (frequency == "12") {
    if (currentMillisWatering - startMillisWatering >= 12 * periodWatering) //test whether the period has elapsed
    {
      waterFreq();
      startMillisWatering = currentMillisWatering;  //IMPORTANT to save the start time of the current LED state.
    } else {
      if (currentMillisWatering - startMillisWatering >= periodWatering) {
        watering = "no";
      }
    }

  } else {
    if (currentMillis - startMillis >= period)  //test whether the period has elapsed
    {
      waterMoist();
    }

  }


  if (currentMillis - startMillis >= period)  //test whether the period has elapsed
  {
    moistLevel = readSoil();
    moisture = String(moistLevel / 14);
    moisture += "%";

    Serial.println(text());
    startMillis = currentMillis;  //IMPORTANT to save the start time of the current LED state.
    //watering = "no";
    printed = 0;

  }
  //Serial.println(watering);
  printMenuOnLCD();
  delay(100);


    currentMillis = millis();
  currentMillisWatering = millis();


}
