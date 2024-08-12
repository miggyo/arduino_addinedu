const int button=2;
int count =0;

int digits [10][7]{
  {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0}, //1
  {1,1,0,1,1,0,1}, //2
  {1,1,1,1,0,0,1}, //3
  {0,1,1,0,0,1,1}, //4
  {1,0,1,1,0,1,1}, //5
  {1,0,1,1,1,1,1}, //6
  {1,1,1,0,0,0,0}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,1,0,1,1}, //9
};
int buttonPress() {
  static int prebutton = LOW;
  int currbutton = digitalRead(button);
  int press;
  press = (currbutton ==HIGH && prebutton ==LOW);
  prebutton = currbutton;
  return press;
}

void displayDigit(int i){
  if(digits[i][0] ==1) digitalWrite(3,HIGH); else digitalWrite(3,LOW); 
  if(digits[i][1] ==1) digitalWrite(4,HIGH); else digitalWrite(4,LOW);
  if(digits[i][2] ==1) digitalWrite(5,HIGH); else digitalWrite(5,LOW);
  if(digits[i][3] ==1) digitalWrite(6,HIGH); else digitalWrite(6,LOW);
  if(digits[i][4] ==1) digitalWrite(7,HIGH); else digitalWrite(7,LOW);
  if(digits[i][5] ==1) digitalWrite(8,HIGH); else digitalWrite(8,LOW);
  if(digits[i][6] ==1) digitalWrite(9,HIGH); else digitalWrite(9,LOW);
}

void setup() {
  // p ut your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button,INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  displayDigit(count);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(buttonPress()){
    count += 1;
    if(count == 10){
      count = 0;
    }
    displayDigit(count);
  }
  Serial.println(count);
}
