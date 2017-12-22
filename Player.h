#ifndef Player_h
#define Player_h

#include "Arduino.h"

namespace Player {
  void setup(byte pin);
  void play(byte pin, short pitch, short duration);
  void playTune(byte pin, byte tuneLength, short tune[][2]);
}
//class Player
//{
//  public:
//    Player(byte pin);
//    static void play(short pitch, short duration);
//    void playTune(byte tuneLength, short tune[][2]);
//  private:
//    byte _pin;
//};


#endif
