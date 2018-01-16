#include "Jukebox.h"
#include <Button.h>
const int speakerPin = 8;
Jukebox jukebox(speakerPin);


Button up(7);
Button ok(6);
Button down(5);

void setup() {
  
 jukebox.repeat(true);
 
}

void loop() {
  up.update();
  down.update();
  ok.update();
  if(up.wasTapped()){
    jukebox.play();
  }
  else if(down.wasTapped()){
    jukebox.pause();
  }
  jukebox.update();

}

