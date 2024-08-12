#include <Servo.h>

int key_min = 20;
int count =0;
int key_max = 70;
Servo servo;
void setup() { 
  // put your setup code here, to run once:
   Serial.begin(9600);
  servo.attach(9);
  servo.write(30);
}

void loop()
{
  int light = analogRead(A0);
  if (light < key_max && light > key_min) //처음 시작
  {
    count += 1;  
    servo.write(100);
    Serial.println(light);
    if(count<=10)
    {   
      delay(500);
      servo.write(30);
    }
    if(count<=15 && count>10)
    {
      delay(370);
      servo.write(30);
    }
    if(count<=20 && count>15)
    {
      delay(300);
      servo.write(30);
    }
    if(count<=25 && count>20)
    {
      delay(100);
      servo.write(30);
    }
    if(count<=30 && count>25)
    {
      delay(50);
      servo.write(30);
    }     
    servo.write(10);
  }
} // {
  //   servo.write(30);
  // }
