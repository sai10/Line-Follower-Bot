#define IR1 3
#define IR2 4
#define IR3 5
#define IR4 6
#define IR5 7
//#define IR6 A0
#define RMF 10
#define RMB 9
#define LMF 11
#define LMB 12



void setup() {
  // put your setup code here, to run once:
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
  pinMode(LMF, OUTPUT);
  pinMode(LMB, OUTPUT);
  pinMode(RMF, OUTPUT);
  pinMode(RMB, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
/*  Serial.println(digitalRead(IR1));
  Serial.println(digitalRead(IR2));
  Serial.println(digitalRead(IR3));
  Serial.println(digitalRead(IR4));
  Serial.println(digitalRead(IR5));
  Serial.println();
  Serial.println();
  Serial.println();*/
 // delay(3000);

// Serial.println(digitalRead(IR6));
  if((digitalRead(IR1)==0)&&(digitalRead(IR2)==0&&digitalRead(IR3)==1&&digitalRead(IR4)==0)&&(digitalRead(IR5)==0))
  {
      //go straight
      digitalWrite(LMF, HIGH);
      digitalWrite(LMB, LOW);
      digitalWrite(RMF, HIGH);
      digitalWrite(RMB, LOW);
    }
    
    else if((digitalRead(IR1)==1)&&(digitalRead(IR2)==1&&digitalRead(IR3)==0&&digitalRead(IR4)==0)&&(digitalRead(IR5)==1) || (digitalRead(IR1)==1)&&(digitalRead(IR2)==0&&digitalRead(IR3)==1&&digitalRead(IR4)==0)&&(digitalRead(IR5)==0) )
  {
    digitalWrite(LMF, HIGH);
      digitalWrite(LMB, LOW);
      digitalWrite(RMF, LOW);
      digitalWrite(RMB, LOW);

     
      
      digitalWrite(LMF, HIGH);
      digitalWrite(LMB, LOW);
      digitalWrite(RMF, HIGH);
      digitalWrite(RMB, LOW);
    }
    
     else if((digitalRead(IR2)==0&&digitalRead(IR3)==1&&digitalRead(IR4)==1)||(digitalRead(IR2)==1&&digitalRead(IR3)==1&&digitalRead(IR4)==1))
  {
      
      digitalWrite(LMF, LOW);
      digitalWrite(LMB, LOW);
      digitalWrite(RMF, HIGH);
      digitalWrite(RMB, LOW);
    }
    
  else if((digitalRead(IR2)==1&&digitalRead(IR3)==1&&digitalRead(IR4)==0))
  {
      //go straight
      digitalWrite(LMF, HIGH);
      digitalWrite(LMB, LOW);
      digitalWrite(RMF, HIGH);
      digitalWrite(RMB, LOW);
    }
    else if((digitalRead(IR2)==0&&digitalRead(IR3)==0&&digitalRead(IR4)==1))
    {
      //left turn
       digitalWrite(LMF, LOW);digitalWrite(LMB, LOW);
      digitalWrite(RMF, HIGH);digitalWrite(RMB, LOW);
    }
    
    else if((digitalRead(IR2)==1&&digitalRead(IR3)==0&&digitalRead(IR4)==0) || (digitalRead(IR1)==0&&digitalRead(IR2)==0&&digitalRead(IR3)==0&&digitalRead(IR4)==0)&&digitalRead(IR5)==0)
    {
      //right turn
       digitalWrite(LMF, HIGH);digitalWrite(LMB, LOW);
      digitalWrite(RMF, LOW);digitalWrite(RMB, HIGH);
    }
    else
    {
       digitalWrite(LMF, LOW);
      digitalWrite(LMB, LOW);
      digitalWrite(RMF, LOW);
      digitalWrite(RMB, LOW);

    }
 }
