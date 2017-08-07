/**             A     SIMPLE     TEMPLATE       **/
/**   

ITS A BASIC CODE FOR LINE FOLLOWER. CODE SOLELY DEPENDS ON THE NUMBER OF IR SENSORS AND MOTORS YOU ARE USING AND MAINLY 
YOUR BUSINESS LOGIC IS SOLELY BASED ON THE TYPE OF TRACK YOUR BOT GOING TO RUN. FOR BETTER RESULTS ITS ADVICED TO USE 
PWM CONCEPT AS analogRead() IN PLACE OF digitalRead()
      
**/

// 2 IR sensors
#define LS 2      // left IR sensor
#define RS 3      // right IR sensor

// 2 DC center shaft motors
#define LMF 4       // left motor Forward
#define LMB 5       // left motor Backward
#define RMF 6       // right motor Forward
#define RMB 7       // right motor Backward

void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}

void loop()
{
  if(digitalRead(LS) && digitalRead(RS))     // Move Forward
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS))     // Turn right
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
  
  if(digitalRead(LS) && !(digitalRead(RS)))     // turn left
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
}
