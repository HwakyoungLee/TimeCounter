#define blinkTime  500

boolean blinkON = false;
int UpdateTime = 0;

void loop() {
  boolean  bval = false;
  
  bval = !digitalRead(SET_BUTTON);
  if (bval) {
    ResetTime();
  }

  UpdateTime = UpdateTime + 1;
  if (UpdateTime > 2000)
  {
    CheckTime();
    UpdateTime = 0;
  }

  writeTime(HourTens, HourOnes, MinTens, MinOnes);
}
