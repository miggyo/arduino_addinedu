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

List<MFRC522::Uid> tag_list;
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance


int buttonPress() {
  static int prebutton = LOW;
  int currbutton = digitalRead(button);
  int press;
  press = (currbutton ==HIGH && prebutton ==LOW);
  prebutton = currbutton;
  return press;
}

void register_uid(){
  
}
void setup() {
	Serial.begin(9600);		// Initialize serial communications with the PC
	while (!Serial);		// Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
	SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522
	delay(4);				// Optional delay. Some board do need more time after init to be ready, see Readme
	mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
	Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
  pinMode(button,OUTPUT);
}

void loop() {
  if(!buttonPress()){
    	if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}

	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}

  }



  //READ UID
  Serial.print("Read UID Tag : ");
  for (byte i = 0; i < mfrc522.uid.size; i++){
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i],HEX);
  }
  Serial.println();

  //CHECK UID 
  // Serial.print(", Check UID Tag : ");
  // if(memcmp(mfrc522.uid.uidByte,MY_TAG, 4) ==0){
  //   Serial.print("Valid");
  // }
  // else{
  //   Serial.print("Invalid");
  // }
  Serial.println(buttonPress());  
  //print Tag_list
  bool registered = false;

  if(buttonPress())
  {
    Serial.println("YOU CAN REGISTER UID NOW");
    for (int i = 0; i<tag_list.getSize();i++){
        if(memcmp(tag_list.get(i).uidByte, mfrc522.uid.uidByte, 4) == 0)//byte 마다 동일한지 확인을 하며 같으면 0을 반환
        {
          registered = true;
        }
      }
      if(!registered){//등록되지 않을 때만 등록
        tag_list.addLast(mfrc522.uid);  
      }


    Serial.print("\nRegistered Tag List (");
    Serial.print(tag_list.getSize());
    Serial.print(") :");
    Serial.println();
    
    for (int i = 0; i<tag_list.getSize(); i++){
      for (byte j = 0; j < 4; j++){
        Serial.print(tag_list.get(i).uidByte[j] < 0x10 ? " 0" : " ");
        Serial.print(tag_list.get(i).uidByte[j],HEX);
      }
      Serial.println();
    }
  }
  
  delay(1000);
}