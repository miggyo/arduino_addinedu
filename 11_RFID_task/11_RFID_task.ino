#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <deprecated.h>
#include <require_cpp11.h>
#include <SPI.h>
#include <MFRC522.h>
#include <List.hpp>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above


const byte MY_TAG[4] = {0x03, 0x26, 0xD5, 0x0F};
const int button = 2;
const int R_LED = 6;
const int G_LED = 3;
const int B_LED = 5;

int color_count = 0;
int time_count =0;
int led = 0;// 색상
int led_on_off =0;// on = 0, off =1;
int register_flag = false;
int status = 0; //짝수면 인식모드 홀수면 등록 모드 인식모드로 시작
List<MFRC522::Uid> tag_list;

byte tmp[4];

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance



void setup() {
	Serial.begin(9600);		// Initialize serial communications with the PC
	while (!Serial);		// Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
	SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522
	delay(4);				// Optional delay. Some board do need more time after init to be ready, see Readme
	mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
	Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
  Serial.println(F("Please push the button for MODE CHANGE")); 
  pinMode(button,OUTPUT);
  memset(tmp,0x00,4);//tmp 초기화

}

void loop() {
  if (buttonPress()){
    status +=1;
    if (status % 2 != 0) //등록모드
    {
      Serial.println("MODE CHANGE : REGISTER");
      register_flag = HIGH; 
    }
    else if (status % 2 == 0)
    {
      Serial.println("MODE CHANGE : VERIFICATION");
      register_flag = LOW;
    }
  }

  if (register_flag == HIGH){ //등록모드
    register_uid();
  }
  else if (register_flag == LOW){ //인식모드
    check_uid();
  }

  if (led == 1)
  {
    
    if(led_on_off%2 ==0) //led on
    {
      time_count ++;
      analogWrite(B_LED, 255);
      analogWrite(G_LED, 0);    
      analogWrite(R_LED, 0);
      if(time_count ==15){
        time_count = 0;
        led_on_off = 1;
      }
    }
    else if(led_on_off%2 ==1) //led on
    {
      time_count ++;
      analogWrite(B_LED, 0);
      analogWrite(G_LED, 0);    
      analogWrite(R_LED, 0);
      if(time_count ==15){
        time_count = 0;
        led_on_off = 0;
        color_count ++;//한번 on 3이 되면 꺼짐  
      }
    }

    if (color_count==4){
      color_count = 0;
      led = 0;
    }
  }
  if (led == 2)
  {
    
    if(led_on_off%2 ==0) //led on
    {
      time_count ++;
      analogWrite(B_LED, 0);
      analogWrite(G_LED, 0);    
      analogWrite(R_LED, 255);
      if(time_count ==15){
        time_count = 0;
        led_on_off = 1;
      }
    }
    else if(led_on_off%2 ==1) //led off
    {
      time_count ++;
      analogWrite(B_LED, 0);
      analogWrite(G_LED, 0);    
      analogWrite(R_LED, 0);
      if(time_count ==15){
        time_count = 0;
        led_on_off = 0;
        color_count ++;//한번 on 3이 되면 꺼짐  
      }
    }

    if (color_count==4){
      color_count = 0;
      led = 0;
    }
  }

  if(led==0){
      analogWrite(B_LED, 255);
      analogWrite(G_LED, 255);    
      analogWrite(R_LED, 255);
  }
}

int buttonPress() {
  static int prebutton = LOW;
  int currbutton = digitalRead(button);
  int press;
  press = (currbutton ==HIGH && prebutton ==LOW);
  prebutton = currbutton;
  return press;
}

void register_uid(){

  bool registered = false;
  if ( ! mfrc522.PICC_IsNewCardPresent()){
      return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial()){
    return;
  }

  if(memcmp(tmp, mfrc522.uid.uidByte, 4) != 0){
    for (int i = 0; i < tag_list.getSize(); i++){
        if(memcmp(tag_list.get(i).uidByte, mfrc522.uid.uidByte, 4) == 0) {
          registered = true;
          Serial.println("register was already done");
        }
        
      }
    if(!registered){ 
      tag_list.addLast(mfrc522.uid);
      Serial.print("\nRegistered Tag List (");
      Serial.print(tag_list.getSize());
      Serial.print(") :");
      Serial.println();
      
      for (int i = 0; i < tag_list.getSize(); i++){
          for (byte j = 0; j < 4; j++){
              Serial.print(tag_list.get(i).uidByte[j] < 0x10 ? " 0" : " ");
              Serial.print(tag_list.get(i).uidByte[j],HEX);
          }
          Serial.println();
          Serial.println("registration is complete");
      }
    }
    memcpy(tmp,mfrc522.uid.uidByte,4);
  }
}

void check_uid(){
  int check_flag =0;
  bool checked = false;
  byte tmpuid[4];

  if ( ! mfrc522.PICC_IsNewCardPresent()){
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial()){
    return;
  }


  memcpy(tmpuid, mfrc522.uid.uidByte, 4);
  Serial.print("Read UID Tag : ");
  for (byte i = 0; i < mfrc522.uid.size; i++){
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i],HEX);
  }
  Serial.println();
  for (int i = 0; i<tag_list.getSize(); i++){
    if(memcmp(mfrc522.uid.uidByte,tag_list[i].uidByte, 4) ==0){ //tag_list도 uidbyte type으로 해줘야됨
      check_flag = 1;
    }
    else{
      check_flag = 0;
    }
  }

  Serial.print(" Check UID Tag : ");
  if (check_flag == 1){
    Serial.println("valid");
    led = 1;
    time_count = 0; //tag 할떄마다 초기화
    led_on_off = 0;
    
  }
  else{
    Serial.println("invalid");
    led =2; //미등록
    time_count = 0; //tag 할때마다 초기화
    led_on_off = 0;
  }
}