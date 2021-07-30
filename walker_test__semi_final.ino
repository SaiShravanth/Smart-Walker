int   g=2;
int yo=0;
int xpos =0;
int ypos =0;
int pot =A0;
int xaxis =A1;
int yaxis =A2;
int switch1;
//int enA =D10; //pwm
//int enB =D11; //pwm

void setup()
{
Serial.begin(9600);
pinMode(pot,INPUT);
pinMode(xaxis,INPUT);
pinMode(yaxis,INPUT);
pinMode(3,OUTPUT);  
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);//button1
pinMode(8,OUTPUT);//button2
pinMode(9,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,INPUT);
pinMode(10,OUTPUT);//pwm
pinMode(11,OUTPUT);//pwm
pinMode(A3,INPUT);//switch

}

void loop() {
  int xpos = analogRead(xaxis);
  int ypos = analogRead(yaxis);
  int speed1 = analogRead(pot);
  analogWrite(10,speed1);
  analogWrite(11,speed1);

switch1 =analogRead(A3);
Serial.println(switch1);
//if(switch1<500 && yo==0)
  //{
    //  g=g+1;
      //yo=1;
  //}
  //Serial.println(g);
//if(switch1>500 && yo!=0)
//{
  if(g%2==0)
   {
   Serial.println("even");
    digitalWrite(9,HIGH);
  digitalWrite(12,LOW);
   delay(8000);
  digitalWrite(9,LOW);
  digitalWrite(12,LOW);
  delay(150);
  
   switch1 =analogRead(A3);
        while(true)
     {
   //run1();
    Serial.println("run1()");
   int button1=digitalRead(7);
   int button2=digitalRead(8);
   Serial.println(button1);
   Serial.println(button2);
   switch1 =analogRead(A3);
   if(switch1<500){
    yo=0;
    break;
    }
   else if (button1==0 && button2==0)
   {
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    Serial.println("stop");
    int button1=digitalRead(7);
   int button2=digitalRead(8);
   int speed1 = analogRead(pot);
  analogWrite(10,speed1);
  analogWrite(11,speed1);

   }
   else if (button1==1 && button2==0) //button1 on right and 3,4 pins for right motor
   {
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    Serial.println("left");
    int button1=digitalRead(7);
   int button2=digitalRead(8);
   int speed1 = analogRead(pot);
  analogWrite(10,speed1);
  analogWrite(11,speed1);

   }
   else if (button1==0 && button2==1)
   {
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    Serial.println("right");
    int button1=digitalRead(7);
   int button2=digitalRead(8);
   int speed1 = analogRead(pot);
  analogWrite(10,speed1);
  analogWrite(11,speed1);

   }
   else if (button1==1 && button2==1)
   {
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    Serial.println("front");
    int button1=digitalRead(7);
   int button2=digitalRead(8);
   int speed1 = analogRead(pot);
  analogWrite(10,speed1);
  analogWrite(11,speed1);

   }
  }
 }
 yo=0;
   //Serial.println(g);
   if(g%2!=0)
   {
   Serial.println("odd");
    digitalWrite(9,LOW);
  digitalWrite(12,HIGH);
   delay(5000);
  digitalWrite(9,LOW);
  digitalWrite(12,LOW);
  delay(150);
 
   switch1 =analogRead(A3);
   while(true){
       //run2();
  Serial.println("run2()");
  int xpos = analogRead(xaxis);
  int ypos = analogRead(yaxis);
  //Serial.println(xpos);
  //Serial.println(ypos);
  switch1 =analogRead(A3);
   if(switch1<500){
    yo=0;
    break;
   }
   else if (350<xpos && xpos<600 && 450<ypos && ypos<600) //stop
   {
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    Serial.println("stop");
    switch1 =analogRead(A3);
    int xpos = analogRead(xaxis);
   int ypos = analogRead(yaxis);
   int speed1 = analogRead(pot);
  analogWrite(10,speed1);
  analogWrite(11,speed1);

   }
   else if (0<=xpos && xpos<350) //forward
   {
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    Serial.println("FRONT");
    switch1 =analogRead(A3);
     int xpos = analogRead(xaxis);
  int ypos = analogRead(yaxis);
  int speed1 = analogRead(pot);
  analogWrite(10,speed1);
  analogWrite(11,speed1);

  }
  else if (600<xpos && xpos<=1023) //BACKward
  {
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    Serial.println("BACK");
    switch1 =analogRead(A3);
      int xpos = analogRead(xaxis);
  int ypos = analogRead(yaxis);
  int speed1 = analogRead(pot);
  analogWrite(10,speed1);
  analogWrite(11,speed1);

  }
  else if (0<=ypos && ypos<450) //LEFT (3,4 pins for right motor)
  {
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    Serial.println("LEFT");
    switch1 =analogRead(A3);
      int xpos = analogRead(xaxis);
  int ypos = analogRead(yaxis);
  int speed1 = analogRead(pot);
  analogWrite(10,speed1);
  analogWrite(11,speed1);

  }
  else if (600<ypos && ypos<=1023) //RIGHt (5,6 pins for left motor)
  {
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    Serial.println("RIGHT");
    switch1 =analogRead(A3);
      int xpos = analogRead(xaxis);
  int ypos = analogRead(yaxis);
  int speed1 = analogRead(pot);
  analogWrite(10,speed1);
  analogWrite(11,speed1);

  }
  
}
   }
   yo=0;
   }


/*void open1()
{
  digitalWrite(9,HIGH);
  digitalWrite(12,LOW);
   delay(8000);
  digitalWrite(9,LOW);
  digitalWrite(12,LOW);
  delay(150);
     Serial.println("open1");
      
}
void close1()
{
  digitalWrite(9,LOW);
  digitalWrite(12,HIGH);
   delay(5000);
  digitalWrite(9,LOW);
  digitalWrite(12,LOW);
  delay(150);
  Serial.println("close1");

}

/*void run1()
{
  Serial.println("run1()");
  delay(500);
  int button1= digitalRead(1);
  int button2= digitalRead(2);
  Serial.println(xpos);
  Serial.println(ypos);
   switch1 =digitalRead(0);
     if(switch1==0){
    yo=0;
   }
  else if (button1==0 && button2==0)
  {
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    Serial.println("stop");
  }
  else if (button1==1 && button2==0) //button1 on right and 3,4 pins for right motor
  {
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    Serial.println("left");
  }
  else if (button1==0 && button2==1)
  {
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    Serial.println("right");
  }
  else if (button1==1 && button2==1)
  {
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    Serial.println("front");
  }
}
void run2()
{
  Serial.println("run2()");
  delay(500);
  int xpos = analogRead(xaxis);
  int ypos = analogRead(yaxis);
  Serial.println(xpos);
  Serial.println(ypos);
  switch1 =digitalRead(0);
   if(switch1==0){
    break;
    yo=0;
   }
  else if (350<xpos && xpos<600 && 450<ypos && ypos<600) //stop
  {
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    Serial.println("stop");
    int xpos = analogRead(xaxis);
  int ypos = analogRead(yaxis);
  }
  else if (0<=xpos && xpos<350) //forward
  {
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    Serial.println("front");
     int xpos = analogRead(xaxis);
  int ypos = analogRead(yaxis);
  }
  else if (600<xpos && xpos<=1023) //backward
  {
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    Serial.println("back");
      int xpos = analogRead(xaxis);
  int ypos = analogRead(yaxis);
  }
  else if (0<=ypos && ypos<450) //left (3,4 pins for right motor)
  {
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    Serial.println("left");
      int xpos = analogRead(xaxis);
  int ypos = analogRead(yaxis);
  }
  else if (600<ypos && ypos<=1023) //right (5,6 pins for left motor)
  {
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    Serial.println("right");
      int xpos = analogRead(xaxis);
  int ypos = analogRead(yaxis);
  }
 
}*/
