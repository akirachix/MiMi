#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper myStepper(stepsPerRevolution, 44, 45, 46, 47);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(10);
  // initialize the serial port:
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}
