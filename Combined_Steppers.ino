#include <Stepper.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(1,2,4,5,6,7);
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 40, 41, 42, 43);
Stepper myStepper2(stepsPerRevolution, 32, 33, 34, 35);
Stepper myStepper3(stepsPerRevolution, 44, 45, 46, 47);
Stepper myStepper4(stepsPerRevolution, 36, 37, 38, 39);

const byte ROWS = 4;
const byte COLS = 4;
int Value;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {22, 23, 24, 25};
byte colPins[COLS] = {26, 27, 28, 29};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  lcd.begin(20,4);
  Serial.begin(9600);
  myStepper.setSpeed(70); 
  pinMode(8,OUTPUT);
  digitalWrite(8,HIGH);
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);

  myStepper2.setSpeed(70);
  pinMode(11,OUTPUT);
  digitalWrite(11,HIGH);
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);

  myStepper3.setSpeed(70);
  pinMode(6,OUTPUT);
  digitalWrite(6,HIGH);
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);

  myStepper4.setSpeed(70);
  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH);
  pinMode(5,OUTPUT);
  digitalWrite(5,HIGH);
}

void loop() {
  char customKey = customKeypad.getKey();
  if(customKey >= '0' && customKey  <= '2')
{
  Value = (customKey - '0');
  lcd.print(customKey);
}
  if (customKey){
   Serial.println(customKey);
   myStepper.step(stepsPerRevolution*Value);
   Serial.println("clockwise");
   delay(1000);
  }
  if (customKey!=NO_KEY){
    lcd.setCursor(10,2);
    lcd.leftToRight();
    lcd.print(customKey);
  }
  lcd.setCursor(0,0);
  lcd.print("Hello Amina!");
  lcd.setCursor(0,1);
  lcd.print("Enter number of pads");

  char customKey2 = customKeypad.getKey();
  if(customKey2 >= '2' && customKey2  <= '5') 
{
  Value = (customKey2 - '0');
  lcd.print(customKey2);
}
  if (customKey2){
   Serial.println(customKey2);
   myStepper2.step(stepsPerRevolution*Value);
   Serial.println("clockwise");
   delay(1000);
  }
  if (customKey2!=NO_KEY){
    lcd.setCursor(10,2);
    lcd.leftToRight();
    lcd.print(customKey2);
  }
    lcd.setCursor(0,0);
    lcd.print("Hello Amina!");
    lcd.setCursor(0,1);
    lcd.print("Enter number of pads");

  char customKey3 = customKeypad.getKey();
  if(customKey3 >= '5' && customKey2  <= '7') 
{
  Value = (customKey3 - '0');
  lcd.print(customKey3);
}
  if (customKey3){
   Serial.println(customKey3);
   myStepper3.step(stepsPerRevolution*Value);
   Serial.println("clockwise");
   delay(1000);
  }
  if (customKey3!=NO_KEY){
    lcd.setCursor(10,2);
    lcd.leftToRight();
    lcd.print(customKey3);
  }
    lcd.setCursor(0,0);
    lcd.print("Hello Amina!");
    lcd.setCursor(0,1);
    lcd.print("Enter number of pads");

  char customKey4 = customKeypad.getKey();
  if(customKey4 >= '7' && customKey2  <= '9') 
{
  Value = (customKey4 - '0');
  lcd.print(customKey4);
}
  if (customKey4){
   Serial.println(customKey4);
   myStepper4.step(stepsPerRevolution*Value);
   Serial.println("clockwise");
   delay(1000);
  }
  if (customKey4!=NO_KEY){
    lcd.setCursor(10,2);
    lcd.leftToRight();
    lcd.print(customKey4);
  }
    lcd.setCursor(0,0);
    lcd.print("Hello Amina!");
    lcd.setCursor(0,1);
    lcd.print("Enter number of pads");
}
