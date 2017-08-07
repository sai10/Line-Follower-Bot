#include <QTRSensors.h>

// Sensors used -  Pololu QTR-8RC array 
// FINDING Kp AND Kd IS ARDOUS

#define Kp 10                     // change it by less margin that just makes your bot follow the line at a slow speed
#define Kd  200                   // change it slowly and Kp < Kd 
#define RIGHT_MAX_SPEED 100 
#define LEFT_MAX_SPEED 100 
#define RIGHT_BASE_SPEED 150      // speed of motors  when the robot is perfectly on the line
#define LEFT_BASE_SPEED 150       // speed of motors  when the robot is perfectly on the line
#define NUM_SENSORS  6            // number of sensors used
#define TIMEOUT 4                 // waits for 2500 us for sensor outputs to go low
#define EMITTER_PIN 2             // emitter is controlled by digital pin 2

#define rightMotor1 8     // FORWARD
#define rightMotor2 9     // BACKWARD
#define rightMotorPWM 10
#define leftMotor1 13     // FORWARD
#define leftMotor2 12     // BACKWARD
#define leftMotorPWM 11
#define motorPower 7

QTRSensorsAnalog qtrrc((unsigned char[]) {
  14, 15, 16, 17, 18, 19                            // A0 - A5
} , NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];

void setup()
{
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);
  pinMode(motorPower, OUTPUT);
  Serial.begin(9600);
  int i;
  for (int i = 0; i < 400; i++) 
    qtrrc.calibrate();                              // MOST IMPORTANT PART
    delay(20);
}

int lastError = 0;

void loop()
{
  unsigned int sensors[6];
  int position = qtrrc.readLine(sensors); 
  int error = position - 2500;
  Serial.println(position);
  int motorSpeed = Kp * error + Kd * (error - lastError);
  lastError = error;

  int rightMotorSpeed = RIGHT_BASE_SPEED + motorSpeed;
  int leftMotorSpeed = LEFT_BASE_SPEED - motorSpeed;

  if (rightMotorSpeed > RIGHT_MAX_SPEED ) 
    rightMotorSpeed = RIGHT_MAX_SPEED; 
  
  if (leftMotorSpeed > LEFT_MAX_SPEED ) 
    leftMotorSpeed = LEFT_MAX_SPEED; 
  
  if (rightMotorSpeed < 0) 
    rightMotorSpeed = 0;
  
  if (leftMotorSpeed < 0)
    leftMotorSpeed = 0; 
  
    digitalWrite(motorPower, HIGH); 
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    analogWrite(rightMotorPWM, rightMotorSpeed);
    digitalWrite(motorPower, HIGH);
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    analogWrite(leftMotorPWM, leftMotorSpeed);
  
}







