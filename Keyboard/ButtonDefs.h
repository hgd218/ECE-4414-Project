#ifdef NOTES

 #define NOTE_F_PORT PORTC
 #define NOTE_F_DDR  DDRC
 #define NOTE_F_INPT PINC
 #define NOTE_F_PIN  (1 << 0)
 bool NOTE_F_DEBOUNCE = false;

 #define NOTE_Gd_PORT PORTC
 #define NOTE_Gd_DDR  DDRC
 #define NOTE_Gd_INPT PINC
 #define NOTE_Gd_PIN  (1 << 1)
 bool NOTE_Gd_DEBOUNCE = false;

 #define NOTE_G_PORT PORTC
 #define NOTE_G_DDR  DDRC
 #define NOTE_G_INPT PINC
 #define NOTE_G_PIN  (1 << 2)
 bool NOTE_G_DEBOUNCE = false;

 #define NOTE_Ad_PORT PORTC
 #define NOTE_Ad_DDR  DDRC
 #define NOTE_Ad_INPT PINC
 #define NOTE_Ad_PIN  (1 << 3)
 bool NOTE_Ad_DEBOUNCE = false;

 #define NOTE_A_PORT PORTC
 #define NOTE_A_DDR  DDRC
 #define NOTE_A_INPT PINC
 #define NOTE_A_PIN  (1 << 4)
 bool NOTE_A_DEBOUNCE = false;

 #define NOTE_Bd_PORT PORTC
 #define NOTE_Bd_DDR  DDRC
 #define NOTE_Bd_INPT PINC
 #define NOTE_Bd_PIN  (1 << 5)
 bool NOTE_Bd_DEBOUNCE = false;

 #define NOTE_B_PORT PORTB
 #define NOTE_B_DDR  DDRB
 #define NOTE_B_INPT PINB
 #define NOTE_B_PIN  (1 << 0)
 bool NOTE_B_DEBOUNCE = false;

 #define NOTE_C_PORT PORTB
 #define NOTE_C_DDR  DDRB
 #define NOTE_C_INPT PINB
 #define NOTE_C_PIN  (1 << 1)
 bool NOTE_C_DEBOUNCE = false;

//  #define NOTE_Dd_PORT PORTD
//  #define NOTE_Dd_DDR  DDRD
//  #define NOTE_Dd_INPT PIND
//  #define NOTE_Dd_PIN  (1 << 0)
//  bool NOTE_Dd_DEBOUNCE = false;

//  #define NOTE_D_PORT PORTD
//  #define NOTE_D_DDR  DDRD
//  #define NOTE_D_INPT PIND
//  #define NOTE_D_PIN  (1 << 1)
//  bool NOTE_D_DEBOUNCE = false;

 #define NOTE_Ed_PORT PORTD
 #define NOTE_Ed_DDR  DDRD
 #define NOTE_Ed_INPT PIND
 #define NOTE_Ed_PIN  (1 << 6)
 bool NOTE_Ed_DEBOUNCE = false;

 #define NOTE_E_PORT PORTD
 #define NOTE_E_DDR  DDRD
 #define NOTE_E_INPT PIND
 #define NOTE_E_PIN  (1 << 7)
 bool NOTE_E_DEBOUNCE = false;

  void setup_note_inputs()
  {
    NOTE_F_DDR  &= ~NOTE_F_PIN;
    NOTE_Gd_DDR &= ~NOTE_Gd_PIN;
    NOTE_G_DDR  &= ~NOTE_G_PIN;
    NOTE_Ad_DDR &= ~NOTE_Ad_PIN;
    NOTE_A_DDR  &= ~NOTE_A_PIN;
    NOTE_Bd_DDR &= ~NOTE_Bd_PIN;
    NOTE_B_DDR  &= ~NOTE_B_PIN;
    NOTE_C_DDR  &= ~NOTE_C_PIN;
    // NOTE_Dd_DDR &= ~NOTE_Dd_PIN;
    // NOTE_D_DDR  &= ~NOTE_D_PIN;
    NOTE_Ed_DDR &= ~NOTE_Ed_PIN;
    NOTE_E_DDR  &= ~NOTE_E_PIN;

    NOTE_F_PORT  |= NOTE_F_PIN;
    NOTE_Gd_PORT |= NOTE_Gd_PIN;
    NOTE_G_PORT  |= NOTE_G_PIN;
    NOTE_Ad_PORT |= NOTE_Ad_PIN;
    NOTE_A_PORT  |= NOTE_A_PIN;
    NOTE_Bd_PORT |= NOTE_Bd_PIN;
    NOTE_B_PORT  |= NOTE_B_PIN;
    NOTE_C_PORT  |= NOTE_C_PIN;
    // NOTE_Dd_PORT |= NOTE_Dd_PIN;
    // NOTE_D_PORT  |= NOTE_D_PIN;
    NOTE_Ed_PORT |= NOTE_Ed_PIN;
    NOTE_E_PORT  |= NOTE_E_PIN;
  }

  uint16_t get_notes()
  {
    uint16_t resultant_notes = 0;

    if (!(NOTE_F_INPT & NOTE_F_PIN))
      NOTE_F_DEBOUNCE = false;  
    else if (!NOTE_F_DEBOUNCE)
    {
      NOTE_F_DEBOUNCE = true;
      resultant_notes |= 1;
    }

    if (!(NOTE_Gd_INPT & NOTE_Gd_PIN))
      NOTE_Gd_DEBOUNCE = false;
    else if (!NOTE_Gd_DEBOUNCE)
    {
      NOTE_Gd_DEBOUNCE = true;
      resultant_notes |= 2;
    }

    if (!(NOTE_G_INPT & NOTE_G_PIN))
      NOTE_G_DEBOUNCE = false;
    else if (!NOTE_G_DEBOUNCE)
    {
      NOTE_G_DEBOUNCE = true;
      resultant_notes |= 4;
    }

    if (!(NOTE_Ad_INPT & NOTE_Ad_PIN))
      NOTE_Ad_DEBOUNCE = false;
    else if (!NOTE_Ad_DEBOUNCE)
    {
      NOTE_Ad_DEBOUNCE = true;
      resultant_notes |= 8;
    }

    if (!(NOTE_A_INPT & NOTE_A_PIN))
      NOTE_A_DEBOUNCE = false;
    else if (!NOTE_A_DEBOUNCE)
    {
      NOTE_A_DEBOUNCE = true;
      resultant_notes |= 16;
    }

    if (!(NOTE_Bd_INPT & NOTE_Bd_PIN))
      NOTE_Bd_DEBOUNCE = false;
    else if (!NOTE_Bd_DEBOUNCE)
    {
      NOTE_Bd_DEBOUNCE = true;
      resultant_notes |= 32;
    }

    if (!(NOTE_B_INPT & NOTE_B_PIN))
      NOTE_B_DEBOUNCE = false;
    else if (!NOTE_B_DEBOUNCE)
    {
      NOTE_B_DEBOUNCE = true;
      resultant_notes |= 64;
    }

    if (!(NOTE_C_INPT & NOTE_C_PIN))
      NOTE_C_DEBOUNCE = false;
    else if (!NOTE_C_DEBOUNCE)
    {
      NOTE_C_DEBOUNCE = true;
      resultant_notes |= 128;
    }

    // if (!(NOTE_Dd_INPT & NOTE_Dd_PIN))
    //   NOTE_Dd_DEBOUNCE = false;
    // else if (!NOTE_Dd_DEBOUNCE)
    // {
    //   NOTE_Dd_DEBOUNCE = true;
    //   resultant_notes |= 256;
    // }

    // if (!(NOTE_D_INPT & NOTE_D_PIN))
    //   NOTE_D_DEBOUNCE = false;
    // else if (!NOTE_D_DEBOUNCE)
    // {
    //   NOTE_D_DEBOUNCE = true;
    //   resultant_notes |= 512;
    // }

    if (!(NOTE_Ed_INPT & NOTE_Ed_PIN))
      NOTE_Ed_DEBOUNCE = false;
    else if (!NOTE_Ed_DEBOUNCE)
    {
      NOTE_Ed_DEBOUNCE = true;
      resultant_notes |= 1024;
    }

    if (!(NOTE_E_INPT & NOTE_E_PIN))
      NOTE_E_DEBOUNCE = false;
    else if (!NOTE_E_DEBOUNCE)
    {
      NOTE_E_DEBOUNCE = true;
      resultant_notes |= 2048;
    }

    return resultant_notes;
  }

#endif
