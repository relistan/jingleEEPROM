#include <EEPROM.h>
#include "Player.h"

#define NUM_NOTES 53

#define BUZZER 12

void setup() {
  Player::setup(BUZZER);
  Serial.begin(115200);
}

void loop() {
  unsigned char bytes[4];

  Serial.println("Playing...");
  // put your main code here, to run repeatedly:
  for(uint16_t i = 0; i < NUM_NOTES*4; i += 4) {
    bytes[0] = EEPROM.read(i);
    bytes[1] = EEPROM.read(i+1);
    bytes[2] = EEPROM.read(i+2);
    bytes[3] = EEPROM.read(i+3);

    short pitch =  bytes[1] | bytes[0] << 8;
    short duration = 1000 / (bytes[3] | bytes[2] << 8);
    Player::play(BUZZER, pitch, duration);
  }
  Serial.println("Done!");
}
