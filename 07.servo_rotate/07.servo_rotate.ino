#include <Servo.h>

const int PUSH_BUTTON = 12;
Servo servo;
int pos = 0;
int dir = 0;
bool flag;

void setup() {
  // put your setup code here, to run once:
  pinMode(PUSH_BUTTON, INPUT);
  Serial.begin(9600);
  servo.attach(9);
  servo.write(0);
}

void loop() {

  int button_status = digitalRead(PUSH_BUTTON);

    if( button_status == HIGH )
    {
      if( dir == 0){
        if ( flag == false )
        {
          pos +=10;
          flag = true;
          if( pos == 180)
          {
            dir =1;
          }
          else {}
        }
        else {}
      }

      else if( dir == 1){
        if (flag == false)
        {
          pos -=10;
          flag = true;
          if( pos == 0)
          {
            dir = 0;
          }
          else{}
        }
        else{}
      }
      else{}    
    }
   
    else if( button_status ==LOW ){
      if( flag == true )
      {
        flag =false;
      }
    }
    else{}
  servo.write(pos);
}

