const int PIR = 2;
const int LED = 3;
unsigned long time =0;
int PIR_flag = 0;
unsigned long before = 0;
extern volatile unsigned long timer0_millis;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIR,INPUT);
  pinMode(LED,OUTPUT); 
}

void loop() {

  int tmp = digitalRead(PIR);
  
  if( tmp == 1)
  {
    PIR_flag =1;
    timer0_millis = 0;
    time=0;
    Serial.println("PIR SIGNAL ON");
  } 
  if (PIR_flag ==1)
  {
    time = millis();
    digitalWrite(LED, HIGH);
    if ((time-before)== 5000)
    {
      PIR_flag =0;
      timer0_millis = 0;
      time = 0;
      digitalWrite(LED, LOW);
      Serial.println("5 seconds! led off");
    }
  }
}