#include <QTRSensors.h>

#define Kp 8 // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Kd  161 // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define RIGHT_MAX_SPEED 200 // max speed of the robot
#define LEFT_MAX_SPEED 200 // max speed of the robot
#define RIGHT_BASE_SPEED 250 // this is the speed at which the motors should spin when the robot is perfectly on the line
#define LEFT_BASE_SPEED 250  // this is the speed at which the motors should spin when the robot is perfectly on the line
#define NUM_SENSORS  6     // number of sensors used
#define TIMEOUT       4  // waits for 2500 us for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2

#define rightMotor1 8
#define rightMotor2 9
#define rightMotorPWM 10
#define leftMotor1 13 // enable left
#define leftMotor2 12
#define leftMotorPWM 11
#define motorPower 7

QTRSensorsAnalog qtrrc((unsigned char[]) {
  14, 15, 16, 17, 18, 19
} , NUM_SENSORS, TIMEOUT, EMITTER_PIN); // sensor connected through analog pins A0 - A5 i.e. digital pins 14-19

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
  for (int i = 0; i < 400; i++) // calibrate for sometime by sliding the sensors across the line, or you may use auto-calibration instead

    qtrrc.calibrate();
  //  delay(20);
  // wait for 2s to position the bot before entering the main loop

}

int lastError = 0;

void loop()
{
  unsigned int sensors[6];
  int position = qtrrc.readLine(sensors); // get calibrated readings along with the line position, refer to the QTR Sensors Arduino Library for more details on line position.
  int error = position - 2500;
  Serial.println(position);
  int motorSpeed = Kp * error + Kd * (error - lastError);
  lastError = error;

  int rightMotorSpeed = RIGHT_BASE_SPEED + motorSpeed;
  int leftMotorSpeed = LEFT_BASE_SPEED - motorSpeed;

  if (rightMotorSpeed > RIGHT_MAX_SPEED ) rightMotorSpeed = RIGHT_MAX_SPEED; // prevent the motor from going beyond max speed
  if (leftMotorSpeed > LEFT_MAX_SPEED ) leftMotorSpeed = LEFT_MAX_SPEED; // prevent the motor from going beyond max speed
  if (rightMotorSpeed < 0) rightMotorSpeed = 0; // keep the motor speed positive
  if (leftMotorSpeed < 0) leftMotorSpeed = 0; // keep the motor speed positive

  {
    digitalWrite(motorPower, HIGH); // move forward with appropriate speeds
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    analogWrite(rightMotorPWM, rightMotorSpeed);
    digitalWrite(motorPower, HIGH);
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    analogWrite(leftMotorPWM, leftMotorSpeed);
  }
}







