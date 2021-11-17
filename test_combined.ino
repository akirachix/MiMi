#include <Stepper.h>

#include <Keypad.h>

#include<LiquidCrystal.h>

#include<EEPROM.h>

LiquidCrystal liquid_crystal_display(1,2,4,5,6,7);

const int stepsPerRevolution = 200; 

Stepper myStepper(stepsPerRevolution, 30, 31, 32, 33);

Stepper myStepper2(stepsPerRevolution, 34, 35, 36, 37);

Stepper myStepper3(stepsPerRevolution, 38, 39, 40, 41);

Stepper myStepper4(stepsPerRevolution, 42, 43, 44, 45);

char password[4];

char initial_password[4],new_password[4];

int i=0;

int relay_pin = 10;

char key_pressed=0;

const byte rows = 4; 

const byte columns = 4; 

char hexaKeys[rows][columns] = {

{'1','2','3','A'},

{'4','5','6','B'},

{'7','8','9','C'},

{'*','0','#','D'}

};

byte row_pins[rows] = {22, 23, 24, 25};

byte column_pins[columns] = {26, 27, 28, 29};  

int Value;

Keypad keypad_key = Keypad( makeKeymap(hexaKeys), row_pins, column_pins, rows, columns);

void setup()

{

  pinMode(relay_pin, OUTPUT);

  liquid_crystal_display.begin(20,4);
  
  liquid_crystal_display.print("  Welcome to Mi.Mi! ");

  liquid_crystal_display.setCursor(0,2);

  liquid_crystal_display.print("  Happy to serve you  ");

  delay(3000);

  liquid_crystal_display.clear();

  liquid_crystal_display.setCursor(0,1);
  
  liquid_crystal_display.print("Enter Password: ");

  liquid_crystal_display.setCursor(5,2);

  initialpassword();

  myStepper.setSpeed(70); 
  pinMode(3,OUTPUT);
  digitalWrite(3,HIGH);
  pinMode(8,OUTPUT);
  digitalWrite(8,HIGH);
  
  myStepper2.setSpeed(70);
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);

  myStepper3.setSpeed(70);
  pinMode(11,OUTPUT);
  digitalWrite(11,HIGH);
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);

  myStepper4.setSpeed(70);
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  pinMode(46,OUTPUT);
  digitalWrite(46,HIGH);  

}

void loop()

{

  digitalWrite(relay_pin, HIGH);

  key_pressed = keypad_key.getKey();

  if(key_pressed=='#')

    change();

  if (key_pressed)

  {

    password[i++]=key_pressed;

    liquid_crystal_display.print(key_pressed);

      }

  if(i==4)

  {

    delay(200);

    for(int j=0;j<4;j++)

      initial_password[j]=EEPROM.read(j);

    if(!(strncmp(password, initial_password,4)))

    {

      liquid_crystal_display.clear();

      liquid_crystal_display.setCursor(0,1);

      liquid_crystal_display.print("Pass Accepted");

      digitalWrite(relay_pin, LOW);

      delay(2000);

      liquid_crystal_display.setCursor(0,2);

      liquid_crystal_display.print(" Processing ...");

      delay(2000);

      liquid_crystal_display.clear();

      liquid_crystal_display.setCursor(0,1);
      
      char customKey = keypad_key.getKey();
      
      if(customKey >= '0' && customKey  <= '2')
      
    {
      
      Value = (customKey - '0');
      
      liquid_crystal_display.setCursor(10,2);
      
      liquid_crystal_display.print(customKey);
      
    }
    
      if (customKey){
        
       myStepper.step(stepsPerRevolution*Value);
       
       delay(1000);
       
      }
      
      if (customKey!=NO_KEY)
      
      {
        
        liquid_crystal_display.setCursor(10,2);
        
        liquid_crystal_display.leftToRight();
        
        liquid_crystal_display.print(customKey);
        
      }
        liquid_crystal_display.setCursor(0,0);
        
        liquid_crystal_display.print("Hello Abigael!");
        
        liquid_crystal_display.setCursor(0,1);
        
        liquid_crystal_display.print("Enter number of pads");

        liquid_crystal_display.setCursor(8,3);

        i=0;

        char customKey2 = keypad_key.getKey();
        
        if(customKey2 >= '2' && customKey2  <= '5')
        
      {
        Value = (customKey2 - '0');
        
        liquid_crystal_display.setCursor(10,2);
        
        liquid_crystal_display.print(customKey2);
        
      }
      
        if (customKey2)
        
        {
          
         myStepper2.step(stepsPerRevolution*Value);
         
         delay(1000);
         
        }
        
        if (customKey2!=NO_KEY)
        
        {
          
          liquid_crystal_display.setCursor(10,2);
          
          liquid_crystal_display.leftToRight();
          
          liquid_crystal_display.print(customKey2);
          
        }
          liquid_crystal_display.setCursor(0,0);
          
          liquid_crystal_display.print("Hello Britney!");
          
          liquid_crystal_display.setCursor(0,1);
          
          liquid_crystal_display.print("Enter number of pads");

          liquid_crystal_display.setCursor(8,3);

          i=0;
      
        char customKey3 = keypad_key.getKey();
        
        if(customKey3 >= '5' && customKey3  <= '7')
        
      {
        
        Value = (customKey3 - '0');
        
        liquid_crystal_display.setCursor(10,2);

        liquid_crystal_display.print(customKey3);
        
      }
      
        if (customKey3)
        
        {
          
         myStepper3.step(stepsPerRevolution*Value);
         
         delay(1000);
         
        }
        
        if (customKey3!=NO_KEY)
        
        {
          
          liquid_crystal_display.setCursor(10,2);
          
          liquid_crystal_display.leftToRight();
          
          liquid_crystal_display.print(customKey3);
          
        }
          liquid_crystal_display.setCursor(0,0);
          
          liquid_crystal_display.print("Hello Aisha!");
          
          liquid_crystal_display.setCursor(0,1);
          
          liquid_crystal_display.print("Enter number of pads");

          liquid_crystal_display.setCursor(8,3);

          i=0;
      
        char customKey4 = keypad_key.getKey();
        
        if(customKey4 >= '7' && customKey4  <= '9')
        
      {
        
        Value = (customKey4 - '0');
        
        liquid_crystal_display.setCursor(10,2);
        
        liquid_crystal_display.print(customKey4);
        
      }
        if (customKey4)
        
        {
          
         myStepper4.step(stepsPerRevolution*Value);
         
         delay(1000);
        }
        
        if (customKey4!=NO_KEY)
        
        {
          
          liquid_crystal_display.setCursor(10,2);
          
          liquid_crystal_display.leftToRight();
          
          liquid_crystal_display.print(customKey4);
          
        }
          liquid_crystal_display.setCursor(0,0);
          
          liquid_crystal_display.print("Hello Amina!");
          
          liquid_crystal_display.setCursor(0,1);
          
          liquid_crystal_display.print("Enter number of pads");

          liquid_crystal_display.setCursor(8,3);

          i=0;  
               
    }

    else

    {

      digitalWrite(relay_pin, HIGH);
      
      liquid_crystal_display.clear();

      liquid_crystal_display.print("Wrong Password");

      liquid_crystal_display.setCursor(0,1);

      liquid_crystal_display.print("Pres # to Change");

      delay(2000);

      liquid_crystal_display.clear();

      liquid_crystal_display.print("Enter Password");

      liquid_crystal_display.setCursor(0,2);

      i=0;
    }

  }

}

void change()
{
  int j=0;

  liquid_crystal_display.clear();

  liquid_crystal_display.print("Current Password");

  liquid_crystal_display.setCursor(0,1);

  while(j<4)
  {
    char key=keypad_key.getKey();
    
    if(key)
    {
      new_password[j++]=key;

      liquid_crystal_display.print(key);
    }
    
    key=0;
  }

  delay(500);

  if((strncmp(new_password, initial_password, 4)))
  {

    liquid_crystal_display.clear();

    liquid_crystal_display.print("Wrong Password");

    liquid_crystal_display.setCursor(0,1);

    liquid_crystal_display.print("Try Again");

    delay(1000);
  }
  else
  {
    j=0;

    liquid_crystal_display.clear();

    liquid_crystal_display.print("New Password:");

    liquid_crystal_display.setCursor(0,2);

    while(j<4)
    {
      char key=keypad_key.getKey();

      if(key)
      {
        initial_password[j]=key;

        liquid_crystal_display.print(key);

        EEPROM.write(j,key);

        j++;   

      }
    }

    liquid_crystal_display.setCursor(0,2);
    
    liquid_crystal_display.print("Pass Changed");

    delay(1000);

  }

  liquid_crystal_display.clear();

  liquid_crystal_display.print("Enter Password: ");

  liquid_crystal_display.setCursor(0,2);

  key_pressed=0;

}

void initialpassword(){

  for(int j=0;j<4;j++)

    EEPROM.write(j, j+49);

  for(int j=0;j<4;j++)

    initial_password[j]=EEPROM.read(j);
} 
