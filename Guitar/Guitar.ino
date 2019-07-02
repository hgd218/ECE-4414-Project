// Arduino/My Inports
#include <Player.h>

#define NOTES
#define STRINGS
#include "Settings.h"
#include "ButtonDefs.h"


Player* player;
Settings settings;


void dispatch_notes(int octave, int base_note);
void play_note(int note);


void setup()
{
  Serial.begin(115200);

  setup_note_inputs();
  // setup_setting_inputs();

  Serial.print("Initializing new player...");
  player = new Player();
  Serial.println("Done");
}


void loop()
{
  settings.get_settings();
  uint16_t notes = get_notes();  // Only returns a bitvector of new notes since the last time this was called

  for (int n = 0; n < 12; ++n)
  {
    if (notes & 1)
      dispatch_notes(4, n);  // Octave 4, n'th note in this octave...it sorts out the settings

    notes >>= 1;
  }
}


void play_note(int note)
{
  int remaind = note % 100;
  if (remaind >= 24)
    note += 200 - 24;
  else if (remaind >= 12)
    note += 100 - 12;

  Serial.print("Playing note: ");
  Serial.println(note);

  // Octave 1
  if (note == 100)
    player->play("ACPNO1FNWAV");
  else if (note == 101)
    player->play("ACPNO1GBWAV");
  else if (note == 102)
    player->play("ACPNO1GNWAV");
  else if (note == 103)
    player->play("ACPNO1ABWAV");
  else if (note == 104)
    player->play("ACPNO1ANWAV");
  else if (note == 105)
    player->play("ACPNO1BBWAV");
  else if (note == 106)
    player->play("ACPNO1BNWAV");
  else if (note == 107)
    player->play("ACPNO1CNWAV");
  else if (note == 108)
    player->play("ACPNO1DBWAV");
  else if (note == 109)
    player->play("ACPNO1DNWAV");
  else if (note == 110)
    player->play("ACPNO1EBWAV");
  else if (note == 111)
    player->play("ACPNO1ENWAV");
 
  // Octave 2
  else if (note == 200)
    player->play("ACPNO2FNWAV");
  else if (note == 201)
    player->play("ACPNO2GBWAV");
  else if (note == 202)
    player->play("ACPNO2GNWAV");
  else if (note == 203)
    player->play("ACPNO2ABWAV");
  else if (note == 204)
    player->play("ACPNO2ANWAV");
  else if (note == 205)
    player->play("ACPNO2BBWAV");
  else if (note == 206)
    player->play("ACPNO2BNWAV");
  else if (note == 207)
    player->play("ACPNO2CNWAV");
  else if (note == 208)
    player->play("ACPNO2DBWAV");
  else if (note == 209)
    player->play("ACPNO2DNWAV");
  else if (note == 210)
    player->play("ACPNO2EBWAV");
  else if (note == 211)
    player->play("ACPNO2ENWAV");

  // Octave 3
  else if (note == 300)
    player->play("ACPNO3FNWAV");
  else if (note == 301)
    player->play("ACPNO3GBWAV");
  else if (note == 302)
    player->play("ACPNO3GNWAV");
  else if (note == 303)
    player->play("ACPNO3ABWAV");
  else if (note == 304)
    player->play("ACPNO3ANWAV");
  else if (note == 305)
    player->play("ACPNO3BBWAV");
  else if (note == 306)
    player->play("ACPNO3BNWAV");
  else if (note == 307)
    player->play("ACPNO3CNWAV");
  else if (note == 308)
    player->play("ACPNO3DBWAV");
  else if (note == 309)
    player->play("ACPNO3DNWAV");
  else if (note == 310)
    player->play("ACPNO3EBWAV");
  else if (note == 311)
    player->play("ACPNO3ENWAV");

  // Octave 4
  else if (note == 400)
    player->play("ACPNO4FNWAV");
  else if (note == 401)
    player->play("ACPNO4GBWAV");
  else if (note == 402)
    player->play("ACPNO4GNWAV");
  else if (note == 403)
    player->play("ACPNO4ABWAV");
  else if (note == 404)
    player->play("ACPNO4ANWAV");
  else if (note == 405)
    player->play("ACPNO4BBWAV");
  else if (note == 406)
    player->play("ACPNO4BNWAV");
  else if (note == 407)
    player->play("ACPNO4CNWAV");
  else if (note == 408)
    player->play("ACPNO4DBWAV");
  else if (note == 409)
    player->play("ACPNO4DNWAV");
  else if (note == 410)
    player->play("ACPNO4EBWAV");
  else if (note == 411)
    player->play("ACPNO4ENWAV");

  // Octave 5
  else if (note == 500)
    player->play("ACPNO5FNWAV");
  else if (note == 501)
    player->play("ACPNO5GBWAV");
  else if (note == 502)
    player->play("ACPNO5GNWAV");
  else if (note == 503)
    player->play("ACPNO5ABWAV");
  else if (note == 504)
    player->play("ACPNO5ANWAV");
  else if (note == 505)
    player->play("ACPNO5BBWAV");
  else if (note == 506)
    player->play("ACPNO5BNWAV");
  else if (note == 507)
    player->play("ACPNO5CNWAV");
  else if (note == 508)
    player->play("ACPNO5DBWAV");
  else if (note == 509)
    player->play("ACPNO5DNWAV");
  else if (note == 510)
    player->play("ACPNO5EBWAV");
  else if (note == 511)
    player->play("ACPNO5ENWAV");

  // Octave 6
  else if (note == 600)
    player->play("ACPNO6FNWAV");
  else if (note == 601)
    player->play("ACPNO6GBWAV");
  else if (note == 602)
    player->play("ACPNO6GNWAV");
  else if (note == 603)
    player->play("ACPNO6ABWAV");
  else if (note == 604)
    player->play("ACPNO6ANWAV");
  else if (note == 605)
    player->play("ACPNO6BBWAV");
  else if (note == 606)
    player->play("ACPNO6BNWAV");
  else if (note == 607)
    player->play("ACPNO6CNWAV");
  else if (note == 608)
    player->play("ACPNO6DBWAV");
  else if (note == 609)
    player->play("ACPNO6DNWAV");
  else if (note == 610)
    player->play("ACPNO6EBWAV");
  else if (note == 611)
    player->play("ACPNO6ENWAV");
 
  // Octave 7
  else if (note == 700)
    player->play("ACPNO7FNWAV");
  else if (note == 701)
    player->play("ACPNO7GBWAV");
  else if (note == 702)
    player->play("ACPNO7GNWAV");
  else if (note == 703)
    player->play("ACPNO7ABWAV");
  else if (note == 704)
    player->play("ACPNO7ANWAV");
  else if (note == 705)
    player->play("ACPNO7BBWAV");
  else if (note == 706)
    player->play("ACPNO7BNWAV");
  else if (note == 707)
    player->play("ACPNO7CNWAV");
  else if (note == 708)
    player->play("ACPNO7DBWAV");
  else if (note == 709)
    player->play("ACPNO7DNWAV");
  else if (note == 710)
    player->play("ACPNO7EBWAV");
  else if (note == 711)
    player->play("ACPNO7ENWAV");
}


void dispatch_notes(int octave, int base_note)
{
  int note = (octave*100)+base_note;
  play_note(note);
  return;
  // if (settings.single_note)
  // {
  //   if (settings.acoustic)
  //     play_note(...);
  //   else if (settings.electric)
  //     play_note(...);
  // }
  // else if (settings.chord)
  // {
  //   if (settings.major)
  //   {
  //     if (settings.acoustic)
  //     {
  //       play_note(...);
  //       play_note(...);
  //       play_note(...);
  //     }
  //     else if (settings.electric)
  //     {
  //       play_note(...);
  //       play_note(...);
  //       play_note(...);
  //     }
  //   }
  //   else if (settings.minor)
  //   {
  //     if (settings.acoustic)
  //     {
  //       play_note(...);
  //       play_note(...);
  //       play_note(...);
  //     }
  //     else if (settings.electric)
  //     {
  //       play_note(...);
  //       play_note(...);
  //       play_note(...);
  //     }
  //   }
  // }
  // else if (settings.arpegio)
  // {
  //   if (settings.major)
  //   {
  //     if (settings.acoustic)
  //     {
  //       play_note(...);
  //       play_note(...);
  //       play_note(...);
  //     }
  //     else if (settings.electric)
  //     {
  //       play_note(...);
  //       play_note(...);
  //       play_note(...);
  //     }
  //   }
  //   else if (settings.minor)
  //   {
  //     if (settings.acoustic)
  //     {
  //       play_note(...);
  //       play_note(...);
  //       play_note(...);
  //     }
  //     else if (settings.electric)
  //     {
  //       play_note(...);
  //       play_note(...);
  //       play_note(...);
  //     }
  //   }
  // }
}