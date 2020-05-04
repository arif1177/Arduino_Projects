/*
  Melody
 
 Plays a melody 
 
 circuit:
 * 8-ohm speaker on digital pin 8
 
 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe 

This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone
 Arif: At present config. just put vcc and gnd from arduino VCC and ground. And pin 8 is Data
 this can be a good resource to get tones http://www.free-ringtones.uk.com/ringtone-composer-guide.html
 and http://en.wikipedia.org/wiki/Ring_Tone_Transfer_Language
 */
 #include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4
  //NOTE_C1, NOTE_D1, NOTE_E1, NOTE_F1, NOTE_C1, NOTE_F1, NOTE_E1, NOTE_F1, NOTE_G1, NOTE_D1, NOTE_D1, NOTE_E1, NOTE_F1, NOTE_A1, NOTE_G1, NOTE_G1, NOTE_F1, NOTE_F1, NOTE_E1, NOTE_D1, NOTE_E1, NOTE_C1, 0, NOTE_C1, NOTE_D1, NOTE_E1, NOTE_F1, NOTE_C1, NOTE_F1, NOTE_E1, NOTE_F1, NOTE_G1, NOTE_D1, NOTE_D1, NOTE_E1, NOTE_F1, NOTE_A1, NOTE_G1, NOTE_G1, NOTE_F1, NOTE_F1, NOTE_E1, NOTE_D1, NOTE_E1, NOTE_F1
  //Coca cola d=4,o=5,b=125:8f#6, 8f#6, 8f#6, 8f#6, g6, 8f#6, e6, 8e6, 8a6, f#6, d6, 2p
  };
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 
  //4,4,4,2,2,4,4,4,2,2,4,4,4,4,8,4,4,8,4,4,4,1,4,4,4,4,2,2,4,4,4,2,2,4,4,4,4,8,4,4,8,4,4,4,1
  
  
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    if(thisNote == 4 || thisNote == 9 || thisNote == 27 || thisNote == 32)
      noteDuration = 750;//2.
    if(thisNote == 13 || thisNote == 18 || thisNote == 36 || thisNote == 41)
      noteDuration = 375;//4.
    tone(8, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
