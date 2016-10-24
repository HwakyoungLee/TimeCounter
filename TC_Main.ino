#define blinkTime  500

boolean blinkON = false;
int UpdateTime = 0;

void loop() {
  boolean  bval = false;
  
  bval = !digitalRead(START_BUTTON);
  if (bval) {
    resetTime();
  }

  UpdateTime = UpdateTime + 1;
  if (UpdateTime > 2000)
  {
    checkTime();
    UpdateTime = 0;
  }

  writeTime(HourTens, HourOnes, MinTens, MinOnes);
}
