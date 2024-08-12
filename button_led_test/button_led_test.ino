const int PUSH_BUTTON = 2;
bool flag;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PUSH_BUTTON, INPUT);
  flag=false;
    // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  int button_status = digitalRead(PUSH_BUTTON);
  if(button_status == HIGH)
  {

    if(flag == false){
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("BUTTON IS PRESSED.");
      flag = true;
    }

  }
    if(button_status == LOW)
  {
    
    if(flag == true){
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("---");
      flag = false;
    }

  }


}
