#pragma once

#define SETTING_SNCA_PORT PORTB
#define SETTING_SNCA_DDR DDRB
#define SETTING_SNCA_INPT PINB
#define SETTING_SNCA_PIN  (1 << 3)

#define SETTING_MELODIC_MODE_PORT PORTB
#define SETTING_MELODIC_MODE_DDR DDRB
#define SETTING_MELODIC_MODE_INPT PINB
#define SETTING_MELODIC_MODE_PIN  (1 << 4)

#ifdef STRINGS
  #define SETTING_OVERDRIVE_PORT PORTB
  #define SETTING_OVERDRIVE_DDR DDRB
  #define SETTING_OVERDRIVE_INPT PINB
  #define SETTING_OVERDRIVE_PIN  (1 << 5)
#endif
#ifdef KEYBOARD
  #define SETTING_INVERSION_PORT PORTB
  #define SETTING_INVERSION_DDR DDRB
  #define SETTING_INVERSION_INPT PINB
  #define SETTING_INVERSION_PIN  (1 << 5)
#endif


void setup_setting_inputs()
{
  SETTING_SNCA_DDR &= ~SETTING_SNCA_PIN;
  SETTING_MELODIC_MODE_DDR &= ~SETTING_MELODIC_MODE_PIN;
 #ifdef STRINGS
  SETTING_OVERDRIVE_DDR &= ~SETTING_OVERDRIVE_PIN;
 #endif  
 #ifdef KEYBOARD
  SETTING_INVERSION_DDR &= ~SETTING_INVERSION_PIN;
 #endif

  SETTING_SNCA_PORT |= SETTING_SNCA_PIN;
  SETTING_MELODIC_MODE_PORT |= SETTING_MELODIC_MODE_PIN;
 #ifdef STRINGS
  SETTING_OVERDRIVE_PORT |= SETTING_OVERDRIVE_PIN;
 #endif  
 #ifdef KEYBOARD
  SETTING_INVERSION_PORT |= SETTING_INVERSION_PIN;
 #endif
}


struct Settings
{
  bool single_note   = true;
  bool chord         = false;
  bool arpegio       = false;
  bool debounce_snca = false;
  void get_snca()
  {
    // Check if this setting's button is pressed
    if (!(SETTING_SNCA_INPT & SETTING_SNCA_PIN))
      debounce_snca = false;

    // If snca switch was not previously not pressed, set up the values
    else if (!debounce_snca)
    {
      debounce_snca = true;

      if (single_note)
      {
        single_note = false;
        chord = true;
      }
      else if (chord)
      {
        chord = false;
        arpegio = true;
      }
      else if (arpegio)
      {
        single_note = true;
        arpegio = false;
      }
    }
  }

  bool major                 = true;
  bool minor                 = false;
  bool debounce_melodic_mode = false;
  void get_melodic_mode()
  {
    // Check if this setting's button is pressed
    if (!(SETTING_MELODIC_MODE_INPT & SETTING_MELODIC_MODE_PIN))
      debounce_melodic_mode = false;

    // If melodic mode switch was not previously not pressed, set up the values
    else if (!debounce_melodic_mode)
    {
      debounce_melodic_mode = true;

      if (major)
      {
        major = false;
        minor = true;
      }
      else if (chord)
      {
        major = false;
        minor = true;
      }
    }
  }

 #ifdef STRINGS
  bool acoustic           = true;
  bool electric           = false;
  bool debounce_overdirve = false;
  void get_overdrive()
  {
    // Check if this setting's button is pressed
    if (!(SETTING_OVERDRIVE_INPT & SETTING_OVERDRIVE_PIN))
      debounce_overdirve = false;

    // If melodic mode switch was not previously not pressed, set up the values
    else if (!debounce_overdirve)
    {
      debounce_overdirve = true;

      if (acoustic)
      {
        acoustic = false;
        electric = true;
      }
      else if (electric)
      {
        acoustic = true;
        electric = false;
      }
    }
  }
 #endif
 #ifdef KEYBOARD
  bool first_inversion   = true;
  bool second_inversion  = false;
  bool third_inversion   = false;
  bool debounce_inversion = false;
  void get_inversion()
  {
    // Check if this setting's button is pressed
    if (!(SETTING_INVERSION_INPT & SETTING_INVERSION_PIN))
      debounce_inversion = false;

    // If melodic mode switch was not previously not pressed, set up the values
    else if (!debounce_inversion)
    {
      debounce_inversion = true;

      if (first_inversion)
      {
        first_inversion = false;
        second_inversion = true;
      }
      else if (second_inversion)
      {
        second_inversion = false;
        third_inversion  = true;
      }
      else if (third_inversion)
      {
        third_inversion = false;
        first_inversion = true;
      }
    }
  }
 #endif

  void get_settings()
  {
    get_snca();
    get_melodic_mode();
   #ifdef STRINGS
    get_overdrive();
   #endif
   #ifdef KEYBOARD
    get_inversion();
   #endif
  }
};
