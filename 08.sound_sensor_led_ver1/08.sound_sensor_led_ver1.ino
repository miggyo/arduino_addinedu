const int sound_sensor = A0;
const int LED_1 = 2;
const int LED_2 = 3; 
const int LED_3 = 4; 
const int LED_4 = 5; 
const int LED_5 = 6; 
const int LED_6 = 7; 
const int LED_7 = 8; 
const int LED_8 = 9;


int max = 800;
int min = 25;
int flag = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_1,OUTPUT);
  pinMode(LED_2,OUTPUT);
  pinMode(LED_3,OUTPUT);
  pinMode(LED_4,OUTPUT);
  pinMode(LED_5,OUTPUT);
  pinMode(LED_6,OUTPUT);
  pinMode(LED_7,OUTPUT);
  pinMode(LED_8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int vol = analogRead(sound_sensor);
  
  int out = map(vol, min, max, 0,255);  


  if(out < 0)
  {
    out =0;
  }

  if(out >255)
  {
    out =255;
  }
  else if( 10<out)
  {
    flag = 1;
    if(flag == 1)
      {
      digitalWrite(LED_1, flag);
      delay(50);
      if( 40  < out)
      {
        flag = 1;
        if(flag == 1)
        {
          digitalWrite(LED_2, flag);
          delay(50);
          Serial.println(flag);
          if( 90 < out)
          {
            flag = 1;
            if(flag == 1){
              digitalWrite(LED_3, flag);
              delay(50);
              if( 120 < out)
              {
                flag = 1;
                if(flag == 1){
                  digitalWrite(LED_4, flag);
                  delay(50);
                  if( 150 < out)
                  {
                    flag = 1;
                    if(flag == 1){
                      digitalWrite(LED_5, flag);
                      delay(50);
                      if( 180 < out)
                      {
                        flag = 1;
                        if(flag == 1){
                          digitalWrite(LED_6, flag);
                          delay(50);
                          if( 210<out)
                          {
                            flag = 1;
                            if(flag == 1){
                              digitalWrite(LED_7, flag);
                              delay(50);
                              if( 240<out )
                              {
                                flag = 1;
                                if(flag == 1){
                                  digitalWrite(LED_8, flag);
                                  delay(50);
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else
  {
    flag = 0;
    digitalWrite(LED_1, flag);
    digitalWrite(LED_2, flag);
    digitalWrite(LED_3, flag);
    digitalWrite(LED_4, flag);
    digitalWrite(LED_5, flag);
    digitalWrite(LED_6, flag);
    digitalWrite(LED_7, flag);
    digitalWrite(LED_8, flag);
  }
  delay(100);
  // Serial.println(out);     

}
