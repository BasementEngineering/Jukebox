#ifndef JUKEBOX_H
#define JUKEBOX_H

#include "Timer.h"
#include <Arduino.h>

extern int* melodies[];
extern int* durations[];
extern int numberOfSongs;

class Jukebox{
  public:
  Jukebox(int pin);
  void update();
  void chooseSong(int song);
bool isPlaying();
  void play();
  void pause();
  void restart();
  void repeat(bool on);

  private: 
  Timer noteDuration;
  Timer pauseBetweenNotes;
  void playNextNote();
  int speakerPin;
  bool onRepeat;
  bool playing;
  int songNumber;
  int noteCounter;
};

#endif
