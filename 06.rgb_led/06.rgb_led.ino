const int B_LED = 9;
const int G_LED = 10;
const int R_LED = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0)
  {
    Serial.println("----");
    char input = Serial.read();
    Serial.println(input);
    if (input == 'b'){
    for(int i = 0; i < 255; i++)
    {
      analogWrite(B_LED, i);
      analogWrite(G_LED, 0);    
      analogWrite(R_LED, 0);
      delay(5);
    }
  }
    else if (input == 'g'){
      for(int i = 0; i < 255; i++)
      {
        analogWrite(B_LED, 0);
        analogWrite(G_LED, i);    
        analogWrite(R_LED, 0);
        delay(5);
      }
    }
    else if (input == 'r'){
      for(int i = 0; i < 255; i++)
      {
        analogWrite(B_LED, 0);
        analogWrite(G_LED, 0);    
        analogWrite(R_LED, i);
        delay(5);
        
      }
    }
    else
    {
      Serial.println("NOT A COMMAND!");
    }
  }
}
