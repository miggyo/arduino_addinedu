#include <Wire.h>

#define LED_PIN 2

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Wire.begin(0x08); // 슬레이브 주소 0x08 설정
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
}

void loop() {
  // 메인 루프가 필요하지 않음
}

void receiveEvent(int howMany) {
  while (Wire.available()) {
    char c = Wire.read();
    if (c == 'S') {
      digitalWrite(LED_PIN, HIGH); // LED 켜기
    }
  }
}

void requestEvent() {
  Wire.write(digitalRead(LED_PIN)); // LED 상태 전송
}
