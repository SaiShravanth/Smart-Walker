   #include <Servo.h>
Servo myservo1;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;

int val1;// variable to read the value from the analog pin for rotation of arm
int val2;//variable for moment of elbow
int val3;//variable for wrist roll
int val4;//variable for gripper
int ang1=0;
int ang2=0;
int ang3=70
;
int ang4=0;

void setup() {
 Serial.begin(9600);
 myservo1.attach(3);
 myservo2.attach(5);
 myservo3.attach(6);
 myservo4.attach(9);
 myservo1.write(ang1);
 delay(500);
 myservo2.write(ang2);
 delay(500);
 myservo3.write(ang3);
 delay(500);
 myservo4.write(ang4);
 delay(15);
 pinMode(A0,INPUT);
 pinMode(A1,INPUT);
 pinMode(A2,INPUT);
 pinMode(A3,INPUT);
}

void loop() {
  val1 = analogRead(A0);            // reads the value of the potentiometer (value between 0 and 1023)
  val1 = map(val1, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  
  if(val1>105){
    for(;ang1<180;ang1++){
      myservo1.write(ang1);
      delay(15);
      val1 = analogRead(A0);
      val1 = map(val1, 0, 1023, 0, 180);
      if(val1<105)
      break;
    }
  }
 if(val1<75){
    for(;ang1>0;ang1--){
      myservo1.write(ang1);
      delay(15);
      val1 = analogRead(A0);
      val1 = map(val1, 0, 1023, 0, 180);
      if(val1>75)
      break;
    }
  }
//Serial.println(val1);
//Serial.println(ang1);

  val2=analogRead(A1);        // reads the value of the potentiometer (value between 0 and 1023)
  val2 = map(val2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  
  if(val2>105){
    for(;ang2<180;ang2++){
      myservo2.write(ang2);
      delay(15);
      val2 = analogRead(A1);
      val2 = map(val2, 0, 1023, 0, 180);
      if(val2<105)
      break;
    }
  }
 if(val2<75){
    for(;ang2>0;ang2--){
      myservo2.write(ang2);
      delay(15);
      val2 = analogRead(A1);
      val2 = map(val2, 0, 1023, 0, 180);
      if(val2>75)
      break;
    }
  }
//Serial.println(val2);  
//Serial.println(ang2);

  val3 = analogRead(A2);            // reads the value of the potentiometer (value between 0 and 1023)
  val3 = map(val3, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  
  if(val3>105){
    for(;ang3<180;ang3++){
      myservo3.write(ang3);
      delay(15);
      val3 = analogRead(A2);
      val3 = map(val3, 0, 1023, 0, 180);
      if(val3<105)
      break;
    }
  }
 if(val3<75){
    for(;ang3>0;ang3--){
      myservo3.write(ang3);
      delay(15);
      val3 = analogRead(A2);
      val3 = map(val3, 0, 1023, 0, 180);
      if(val3>75)
      break;
    }
  }
//Serial.println(val3);
Serial.println(ang3);

  val4 = analogRead(A3);            // reads the value of the potentiometer (value between 0 and 1023)
  val4 = map(val4, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  
  if(val4>105){
    for(;ang4<180;ang4++){
      myservo4.write(ang4);
      delay(15);
      val4 = analogRead(A3);
      val4 = map(val1, 0, 1023, 0, 180);
      if(val4<105)
      break;
    }
  }
 if(val4<75){
    for(;ang4>0;ang4--){
      myservo4.write(ang4);
      delay(15);
      val4 = analogRead(A3);
      val4 = map(val4, 0, 1023, 0, 180);
      if(val4>75)
      break;
    }
  }
Serial.println(val4);
Serial.println(ang4);

}
