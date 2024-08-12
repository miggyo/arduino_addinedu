int min = 50;
int max = 140;

const int LED = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int light = analogRead(A0);

  if (light < min )
  {
    min = light;
    Serial.println(min);
  }
  if (light > max )
  {
    max = light;
    Serial.println(max);
  }
  else{}


  int out = map(light, min, max, 5,250);
  if( out < 5 )
  {
    out = 0;
  }

  if( out > 250 )
  {
    out = 255;
  } 
  // Serial.print(light);
  // Serial.print(",");
  // Serial.println(out);
  analogWrite(LED, out);
}