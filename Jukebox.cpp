#include "Jukebox.h"

Jukebox::Jukebox(int pin):
  noteDuration(0, false), pauseBetweenNotes(20, false)
{
  speakerPin = pin;
  pinMode(speakerPin, OUTPUT);

  onRepeat = false;
  playing = false;
  songNumber = 0;
  noteCounter = 0;
}


void Jukebox::update() {

  if(playing){
  if (noteDuration.isFinished()) {
    noteDuration.stop();
    noTone(speakerPin);
    pauseBetweenNotes.start();
  }

  if ( pauseBetweenNotes.isFinished() ) {
    pauseBetweenNotes.stop();
    playNextNote();
  }
}
}

bool Jukebox::isPlaying(){
return playing;
}

void Jukebox::chooseSong(int song) {
  if (song != songNumber && ( songNumber < numberOfSongs ) && ( songNumber >= 0 ) ) {
    songNumber = song;
    noteDuration.reset();
    pauseBetweenNotes.reset();
    noteCounter = 0;
  }
}


void Jukebox::play(){
   pauseBetweenNotes.stop();
  playing = true;
  noteDuration.start();
}

void Jukebox::pause(){
  noTone(speakerPin);
  playing = false;
}

void Jukebox::restart(){ 
    pauseBetweenNotes.stop();
    noteDuration.setInterval(0);
     noteDuration.start();
    noteCounter = 0;
}

void Jukebox::repeat(bool on){
  onRepeat = on;
}

void Jukebox::playNextNote() {
 int note = melodies[songNumber][noteCounter];
 
  if ( note != 'X' ) {  
    if ( note == 0 ) {
      noTone(speakerPin);
    }
     else {
      tone(speakerPin, note);
    }
    
    int fractionOfASecond = durations[songNumber][noteCounter];
    int duration = 1800/fractionOfASecond;
    noteDuration.setInterval(duration);
    noteDuration.start();
    noteCounter++;
  }
  else {
    if (onRepeat) {
      noteCounter = 0;
       noteDuration.setInterval(0);
       noteDuration.start();
    }
  }
}
