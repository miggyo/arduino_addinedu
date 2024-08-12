const int PIR = 2;
const int LED = 3;
int count =0;
int PIR_flag = 0;
bool re_alert;
bool alert;
// unsigned long before = 0;
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
    count =0;
    Serial.println("PIR SIGNAL ON");
  } 
  if (PIR_flag ==1)
  {
    if (count < 50)
    {
      count ++;
      digitalWrite(LED, HIGH);
      delay(100);      
    }
    else if (count == 50)
    {
      count = 0;
      PIR_flag =0;
      digitalWrite(LED, LOW);
      Serial.println("5 seconds! led off");
    }
  }
}
