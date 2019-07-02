#ifdef DRUMS

 #define NOTE_SNARE_PORT PORTC
 #define NOTE_SNARE_DDR  DDRC
 #define NOTE_SNARE_INPT PINC
 #define NOTE_SNARE_PIN (1 << 0)
  bool NOTE_SNARE_DEBOUNCE = false;

 #define NOTE_HIGHHAT_PORT PORTC
 #define NOTE_HIGHHAT_DDR  DDRC
 #define NOTE_HIGHHAT_INPT PINC
 #define NOTE_HIGHHAT_PIN (1 << 1)
  bool NOTE_HIGHHAT_DEBOUNCE = false;

 #define NOTE_CRASH_PORT PORTC
 #define NOTE_CRASH_DDR  DDRC
 #define NOTE_CRASH_INPT PINC
 #define NOTE_CRASH_PIN (1 << 3)
  bool NOTE_CRASH_DEBOUNCE = false;

 #define NOTE_KICK_PORT PORTC
 #define NOTE_KICK_DDR DDRC
 #define NOTE_KICK_INPT PINC
 #define NOTE_KICK_PIN (1 << 2)
  bool NOTE_KICK_DEBOUNCE = false;

 #define NOTE_TOM_PORT PORTC
 #define NOTE_TOM_DDR  DDRC
 #define NOTE_TOM_INPT PINC
 #define NOTE_TOM_PIN (1 << 4)
  bool NOTE_TOM_DEBOUNCE = false;

  void setup_note_inputs()
  {
    NOTE_SNARE_DDR  &= ~NOTE_SNARE_PIN;
    NOTE_HIGHHAT_DDR &= ~NOTE_HIGHHAT_PIN;
    NOTE_CRASH_DDR  &= ~NOTE_CRASH_PIN;
    NOTE_KICK_DDR &= ~NOTE_KICK_PIN;
    NOTE_TOM_DDR  &= ~NOTE_TOM_PIN;

    NOTE_SNARE_PORT  |= NOTE_SNARE_PIN;
    NOTE_HIGHHAT_PORT |= NOTE_HIGHHAT_PIN;
    NOTE_CRASH_PORT  |= NOTE_CRASH_PIN;
    NOTE_KICK_PORT |= NOTE_KICK_PIN;
    NOTE_TOM_PORT  |= NOTE_TOM_PIN;
  }

  uint8_t get_notes()
  {
    uint8_t resultant_notes = 0;

    if (!(NOTE_SNARE_INPT & NOTE_SNARE_PIN))
      NOTE_SNARE_DEBOUNCE = false;  
    else if (!NOTE_SNARE_DEBOUNCE)
    {
      NOTE_SNARE_DEBOUNCE = true;
      resultant_notes |= 1;
    }

    if (!(NOTE_HIGHHAT_INPT & NOTE_HIGHHAT_PIN))
      NOTE_HIGHHAT_DEBOUNCE = false;
    else if (!NOTE_HIGHHAT_DEBOUNCE)
    {
      NOTE_HIGHHAT_DEBOUNCE = true;
      resultant_notes |= 2;
    }

    if (!(NOTE_CRASH_INPT & NOTE_CRASH_PIN))
      NOTE_CRASH_DEBOUNCE = false;
    else if (!NOTE_CRASH_DEBOUNCE)
    {
      NOTE_CRASH_DEBOUNCE = true;
      resultant_notes |= 4;
    }

    if (!(NOTE_KICK_INPT & NOTE_KICK_PIN))
      NOTE_KICK_DEBOUNCE = false;
    else if (!NOTE_KICK_DEBOUNCE)
    {
      NOTE_KICK_DEBOUNCE = true;
      resultant_notes |= 8;
    }

    if (!(NOTE_TOM_INPT & NOTE_TOM_PIN))
      NOTE_TOM_DEBOUNCE = false;
    else if (!NOTE_TOM_DEBOUNCE)
    {
      NOTE_TOM_DEBOUNCE = true;
      resultant_notes |= 16;
    }

    return resultant_notes;
  }

#endif
