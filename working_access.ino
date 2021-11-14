#include <LiquidCrystal.h> 
#include <Keypad.h>
#include <Wire.h>

char* password = "5014";
char* number = "7";

int pozition = 0;
int num = 0;

const byte rows = 4; 
const byte cols = 4;

char keyMap [rows] [cols] = { 
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins [rows] = {22, 23, 24, 25};
byte colPins [cols] = {26, 27, 28, 29};

Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, rows, cols);

const int rs = 1, en = 2, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(){
  lcd.begin(20, 4);
  char whichKey = myKeypad.getKey();
  lcd.setCursor(0, 0);
  lcd.print("      Welcome!    ");
  lcd.setCursor(0, 1);
  lcd.print("   Enter Password  ");

  if(pozition == 4){
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("  *** Verified *** ");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("    Hey Brenda!  ");
    lcd.setCursor(0, 1);
    lcd.print("Enter Number of Pads");
  }
}

void loop(){
  char whichKey = myKeypad.getKey();  
    
  if(whichKey == '*' || whichKey == '#' || whichKey == 'A' ||       
    whichKey == 'B' || whichKey == 'C' || whichKey == 'D'){
    pozition=0;
    num=0;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("    Invalid Key!  ");
    delay(1000);
    lcd.clear();
  }
  if(whichKey == password [pozition]){
    pozition ++;
  }
  if(pozition == 4){
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("  *** Verifying *** ");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("    Hey Brenda!  ");
    lcd.setCursor(0, 1);
    lcd.print("Enter Number of Pads");
}
  delay(100);

  if(whichKey == number [num]){
    num ++;
  }
    if(num == 1){
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("     7 pads being   ");
      lcd.setCursor(0, 2);
      lcd.print("     dispensed  ");
      delay(5000);
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("      Thank You!  ");
}
  delay(100);
}
