#include <Keypad.h>
#include <LiquidCrystal.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Stepper.h>

#define RST_PIN 10   
#define SS_PIN 53   

const int stepsPerRevolution = 200;

Stepper myStepper(stepsPerRevolution, 44, 45, 46, 47);
MFRC522 mfrc522(SS_PIN, RST_PIN);
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
  Serial.begin(9600);    
  while (!Serial);
  SPI.begin();      
  mfrc522.PCD_Init(); 
  delay(4);       
  mfrc522.PCD_DumpVersionToSerial();  
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
  myStepper.setSpeed(10);
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}
 
void loop(){
  char key = mykeypad.getKey();  
  if (key!=NO_KEY){
    lcd.setCursor(0,0);
    lcd.leftToRight();
    lcd.print(key);
//    lcd.setCursor(0,0);
//    lcd.print("Hello Amina!");
//    lcd.setCursor(0,1);
//    lcd.print("Enter number of pads");
  }
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid)); 
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
  }  
