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
  
  int level = map(vol, min, max, 0,8);  
  if(level < 0)
  {
    level =0;
  }

  if(level > 8)
  {
    level =8;
  }
  if( level == 0)
  {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
    digitalWrite(LED_5, LOW);
    digitalWrite(LED_6, LOW);
    digitalWrite(LED_7, LOW);
    digitalWrite(LED_8, LOW);   

  }
  if( level == 1)
  {
    digitalWrite(LED_1, HIGH);
    delay(50); 

    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
    digitalWrite(LED_5, LOW);
    digitalWrite(LED_6, LOW);
    digitalWrite(LED_7, LOW);
    digitalWrite(LED_8, LOW);   

  }
  if( level == 2)
  {
    digitalWrite(LED_1, HIGH);
    delay(50); 
    digitalWrite(LED_2, HIGH);
    delay(50); 

    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
    digitalWrite(LED_5, LOW);
    digitalWrite(LED_6, LOW);
    digitalWrite(LED_7, LOW);   
    digitalWrite(LED_8, LOW);   

  }
  if( level == 3)
  {
    digitalWrite(LED_1, HIGH);
    delay(50); 
    digitalWrite(LED_2, HIGH);
    delay(50);
    digitalWrite(LED_3, HIGH);
    delay(50);

    digitalWrite(LED_4, LOW);
    digitalWrite(LED_5, LOW);
    digitalWrite(LED_6, LOW);
    digitalWrite(LED_7, LOW);   
    digitalWrite(LED_8, LOW);   

  }
  if( level == 4)
  {
    digitalWrite(LED_1, HIGH);
    delay(50); 
    digitalWrite(LED_2, HIGH);
    delay(50);
    digitalWrite(LED_3, HIGH);
    delay(50);
    digitalWrite(LED_4, HIGH);
    delay(50);
    digitalWrite(LED_5, LOW);
    digitalWrite(LED_6, LOW);
    digitalWrite(LED_7, LOW);   
    digitalWrite(LED_8, LOW);   

  }
  if( level == 5)
  {
    digitalWrite(LED_1, HIGH);
    delay(50); 
    digitalWrite(LED_2, HIGH);
    delay(50);
    digitalWrite(LED_3, HIGH);
    delay(50);
    digitalWrite(LED_4, HIGH);
    delay(50);
    digitalWrite(LED_5, HIGH);
    delay(50);
    digitalWrite(LED_6, LOW);
    digitalWrite(LED_7, LOW);   
    digitalWrite(LED_8, LOW);   

  }
  if( level == 6)
  {
    digitalWrite(LED_1, HIGH);
    delay(50); 
    digitalWrite(LED_2, HIGH);
    delay(50);
    digitalWrite(LED_3, HIGH);
    delay(50);
    digitalWrite(LED_4, HIGH);
    delay(50);
    digitalWrite(LED_5, HIGH);
    delay(50);
    digitalWrite(LED_6, HIGH);
    delay(50);
    digitalWrite(LED_7, LOW);   
    digitalWrite(LED_8, LOW);   
  }
  if( level == 7)
  {
    digitalWrite(LED_1, HIGH);
    delay(50); 
    digitalWrite(LED_2, HIGH);
    delay(50);
    digitalWrite(LED_3, HIGH);
    delay(50);
    digitalWrite(LED_4, HIGH);
    delay(50);
    digitalWrite(LED_5, HIGH);
    delay(50);
    digitalWrite(LED_6, HIGH);
    delay(50);
    digitalWrite(LED_7, HIGH);
    delay(50);  
    digitalWrite(LED_8, LOW);   
  }
  if( level == 8)
  {
    digitalWrite(LED_1, HIGH);
    delay(50); 
    digitalWrite(LED_2, HIGH);
    delay(50);
    digitalWrite(LED_3, HIGH);
    delay(50);
    digitalWrite(LED_4, HIGH);
    delay(50);
    digitalWrite(LED_5, HIGH);
    delay(50);
    digitalWrite(LED_6, HIGH);
    delay(50);
    digitalWrite(LED_7, HIGH);
    delay(50);  
    digitalWrite(LED_8, HIGH);   
  }
  Serial.print("level : ");
  Serial.println(level);
}