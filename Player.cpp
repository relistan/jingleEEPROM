#include "Arduino.h"
#include "Player.h"

namespace Player {
  void setup(byte pin) {
    pinMode(pin, OUTPUT);
  }  
  
  void play(byte pin, short pitch, short duration) {
    tone(pin, pitch, duration);
     // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
  
  void playTune(byte pin, byte tuneLength, short tune[][2]) {
    //output an frequency
    for(byte thisNote=0;thisNote<tuneLength;thisNote++) {
     // to calculate the note duration, take one second divided by the note type.
     //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
     short pitch = tune[thisNote][0];
     short duration = 1000 / tune[thisNote][1];
     play(pin, pitch, duration);
    }
  }
};
