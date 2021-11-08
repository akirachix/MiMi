#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(1,2,4,5,6,7);

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {22, 23, 24, 25};
byte colPins[COLS] = {26, 27, 28, 29};

Keypad mykeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  lcd.begin(20,4);
}
 
void loop(){
  char key = mykeypad.getKey();
   if (key!=NO_KEY){
    lcd.setCursor(10,2);
    lcd.leftToRight();
    lcd.print(key);
  }
  lcd.setCursor(0,0);
  lcd.print("Hello Amina!");
  lcd.setCursor(0,1);
  lcd.print("Enter number of pads");
  
  }  
