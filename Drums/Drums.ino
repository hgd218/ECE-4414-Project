// Arduino/My Inports
#include <Player.h>

#define DRUMS
#include "ButtonDefs.h"


Player* player;


void dispatch_notes(int octave, int base_note);
void play_note(int note);


void setup()
{
  Serial.begin(115200);

  setup_note_inputs();

  Serial.print("Initializing new player...");
  player = new Player();
  Serial.println("Done");
}


void loop()
{
  uint8_t notes = get_notes();  // Only returns a bitvector of new notes since the last time this was called

  for (int n = 0; n < 5; ++n)
  {
    if (notes & 1)
      play_note(n);  // Octave 4, n'th note in this octave...it sorts out the settings

    notes >>= 1;
  }
}


void play_note(int note)
{
  Serial.print("Playing note: ");
  Serial.println(note);

  // Octave 1
  if (note == 0)
    player->play("SNAREDRMWAV");
  else if (note == 1)
    player->play("HIGH_HATWAV");
  else if (note == 2)
    player->play("CRASHSYMWAV");
  else if (note == 3)
    player->play("KICKDRUMWAV");
  else if (note == 4)
    player->play("TOM_DRUMWAV");
}
