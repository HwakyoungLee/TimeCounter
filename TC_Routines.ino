//*******************************************************************************************************************
//                                                     Beep the piezo
//*******************************************************************************************************************
// NOTE: the piezo uses the same pin as the SET Button input
// This routine switches the pin to an output during the beeping process
// (There is a current limited resistor on the board to prevent over current if the Set Button is pressed at
//  the same time as the pin is driving the piezo.)
void beepsound(int freq, int freqlenght)
{
  // freq was 4000
  // freqlenght was 100
  pinMode(START_BUTTON, OUTPUT);
  tone(START_BUTTON, freq, freqlenght);
  delay(freqlenght);
  noTone(START_BUTTON);
  digitalWrite(START_BUTTON, HIGH);

  pinMode(START_BUTTON, INPUT_PULLUP);
  //  digitalWrite(START_BUTTON, HIGH);
}

//*******************************************************************************************************************
//                                       Output 4 Characters to Display
//*******************************************************************************************************************
void displayString(char outText[])
{
  uint8_t text;
  int  cindex = 0;
  for (int i = 0; i < 4; i++) {
    for (int y = 0; y < 5; y++) {
      text = outText[i] - 32;
      LEDMAT[cindex] = LETTERS[text][y];
      cindex = cindex + 1;
    }
  }
}

//*******************************************************************************************************************
//                                                 Clear LED Matrix
//*******************************************************************************************************************
void clearMatrix()
{
  for (int i = 0; i < 20; i++) {
    LEDMAT[i] = 0;
  }
}

//*******************************************************************************************************************
//                            Fill LED Matrix with formatted time
//*******************************************************************************************************************
// Fills diplay with formated time
// Depending on postion of "1"s spacing is adjusted beween it and next digit
// Blinks if it settng mode
// displays AM/PM dot and Alarm on dot

void writeTime(uint8_t dig1, uint8_t dig2, uint8_t dig3, uint8_t dig4)
{
  const int digitoffset = 95;
  
  int currentdig = 4;
  int y = 0;
  int i = 18;

  LEDMAT[0] = 0;
  LEDMAT[19] = 0;

  for (y = 5; y > 1; y--) {
    if (blinkON) {
      LEDMAT[i] = LETTERS[0][y - 2];                          // blank space
    } else {
      LEDMAT[i] = LETTERS[dig4 + digitoffset][y - 2];
    }
    i = i - 1;
  }

  // Special case of #1, smaller kerning
  if (dig3 == 1) {                                            
    LEDMAT[i] = 0;
    if (blinkON) {
      LEDMAT[i - 1] = 0;                                      // blank space
    } else {
      LEDMAT[i - 1] = 62; //LETTERS[dig3+digitoffset][3];
    }
    LEDMAT[i - 2] = 0;
    i = i - 3;
    currentdig = 2;
  } else {
    for (y = 5; y > 1; y--) {
      if (blinkON) {
        LEDMAT[i] = LETTERS[0][y - 2];                        // blank space
      } else {
        LEDMAT[i] = LETTERS[dig3 + digitoffset][y - 2];
      }
      i = i - 1;
    }
    currentdig = 2;
  }
  
  // ADD Colon Here - S ---------------------------------
  if (dig2 == 1 || dig1 == 3) {
    LEDMAT[i] = 0;
    LEDMAT[i - 1] = 20; //LETTERS[26][3];                        // the " : "
    LEDMAT[i - 2] = 0;
    i = i - 3;
  } else {
    LEDMAT[i] = 20; //LETTERS[26][3];                          // the " :"
    LEDMAT[i - 1] = 0;
    i = i - 2;
  }

  // ADD Colon Here - E ---------------------------------
  if (dig2 == 1) {                                              // Special case of #1, smaller kerning
    LEDMAT[i] = 0;
    if (blinkON) {
      LEDMAT[i - 1] = 0;                                       // blank space
    } else {
      LEDMAT[i - 1] = 62; //LETTERS[dig2+digitoffset][3];
    }
    LEDMAT[i - 2] = 0;
    i = i - 3;
    currentdig = 1;
  } else {
    for (y = 5; y > 1; y--) {
      if (blinkON) {
        LEDMAT[i] = LETTERS[0][y - 2];                        // blank space
      } else {
        LEDMAT[i] = LETTERS[dig2 + digitoffset][y - 2];
      }
      i = i - 1;
    }
    currentdig = 1;
  }

  if (dig1 == 1) {                                            // Special case of #1, smaller kerning
    LEDMAT[i] = 0;
    if (blinkON) {
      LEDMAT[i - 1] = 0;                                     // blank space
    } else {
      LEDMAT[i - 1] = 62; // LETTERS[dig1+digitoffset][3];
    }
    LEDMAT[i - 2] = 0;
    i = i - 2;
  } else {
    for ( y = 5; y > 1; y--) {
      if (blinkON) {
        LEDMAT[i] = LETTERS[0][y - 2];                        // blank space
      } else {
        LEDMAT[i] = LETTERS[dig1 + digitoffset][y - 2];
      }
      i = i - 1;
    }
    // i = 0;
  }

  //  for(y= i+1; y>0;y--)                                        // Clear any remaining columns
  for (y = i + 1; y > 1; y--) {                                // Clear any remaining columns, but not leftmost
    LEDMAT[y - 1] = 0;
  }
}

