#include <Servo.h>

const int PUSH_BUTTON_dir = 12;
const int PUSH_BUTTON_sp = 8;

Servo servo;
int pos = 0;
int sp = 0;
int dir = 0;
int del = 0;
int tmp = 0;
int move = 0;
bool flag;
bool flag_sp;

void setup() {
  // put your setup code here, to run once:
  pinMode(PUSH_BUTTON_dir, INPUT);
  pinMode(PUSH_BUTTON_sp, INPUT);
  Serial.begin(9600);
  servo.attach(9);
  servo.write(0);
}
void loop() {

  int button_status_dir = digitalRead(PUSH_BUTTON_dir);
  int button_status_sp = digitalRead(PUSH_BUTTON_sp);

    if( button_status_dir == HIGH )
    {
      move = 1;
      if( dir == 0){
        if ( flag == false )
        {
          tmp = pos;
          pos +=20;
          Serial.print("position : "); 
          Serial.println(pos);
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
          tmp = pos;
          pos -=20;
          Serial.print("position : "); 
          Serial.println(pos);
          flag = true;
          if( pos == 0 )
          {
            dir = 0;
          }
          else{}
        }
        else{}
      }
      else{}    
    }
   
    else if( button_status_dir ==LOW ){
      if( flag == true )
      {
        flag =false;
      }
    }
    else{}
  

    if( button_status_sp == HIGH )
    {
      if( sp == 0){
        if ( flag_sp == false )
        {
          del += 5;
          Serial.print("delay : "); 
          Serial.println(del);
          flag_sp = true;
          if( del == 30)
          {
            sp =1;
          }
          else {}
        }
        else {}
      }

      else if( sp == 1){
        if (flag_sp == false)
        {
          del -= 5;
          Serial.print("delay : "); 
          Serial.println(del);
          flag_sp= true;
          if( del == 0)
          {
            sp = 0;
          }
          else{}
        }
        else{}
      }
      else{}   
    }
   
    else if( button_status_sp ==LOW ){
      if( flag_sp == true )
      {
        flag_sp =false;
      }
    }
    else{}

    if(move = 1)
    {
      if(dir == 0){
        while(tmp<=pos)
        {
          tmp += 1;
        // Serial.print("position : ");
        // Serial.print(pos);
          servo.write(tmp);
          delay(del);
       }
      }

      move = 0;
    }

}