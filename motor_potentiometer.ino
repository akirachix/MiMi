const int desiredValue = 2;

const int dir = 1;

int Pin1 = 8;
int Pin2 = 9;  
int Pin3 = 10;  
int Pin4 = 11; 
int potPin = A0;// center pin of pot is connected to this pin

int pole1[] ={0,0,0,0, 0,1,1,1, 0};
int pole2[] ={0,0,0,1, 1,1,0,0, 0};
int pole3[] ={0,1,1,1, 0,0,0,0, 0};
int pole4[] ={1,1,0,0, 0,0,0,1, 0};

int poleStep = 0; 
int calcDelayfromTime(int t);
void driveStepper(int c);
int N = calcDelayfromTime(desiredValue);


void setup() 
{ 
 pinMode(Pin1, OUTPUT);
 pinMode(Pin2, OUTPUT);
 pinMode(Pin3, OUTPUT);
 pinMode(Pin4, OUTPUT);
 pinMode(vcc2, OUTPUT);
 Serial.begin(9600);
 Serial.println("Stepper Control");
 Serial.print("Max time per rev set: ");
 Serial.print(desiredValue);
 Serial.print(" loop delay: ");
 Serial.println(N);
  delay(4000);
}

 void loop() 
{ 
 if(dir ==1){ 
   poleStep++; 
    driveStepper(poleStep);    
 }else if(dir ==2){ 
   poleStep--; 
    driveStepper(poleStep);    
 }else{
  driveStepper(8);   
 }
 if(poleStep>7){ 
   poleStep=0; 
 } 
 if(poleStep<0){ 
   poleStep=7; 
 } 
 int potValue =analogRead(potPin);// read potentiometer value
 int speed = map(potValue,0, 1023, 1,N);

 delay(speed); 


}

int calcDelayfromTime(int t){
  return ((t-5)/4)+1;
}

void driveStepper(int c)
{
     digitalWrite(Pin1, pole1[c]);  
     digitalWrite(Pin2, pole2[c]); 
     digitalWrite(Pin3, pole3[c]); 
     digitalWrite(Pin4, pole4[c]);   
}
