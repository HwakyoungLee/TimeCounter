#define blinkTime  500

boolean blinkON = false;
int UpdateTime = 0;
boolean sleeping = true;

void loop() {
  boolean  bval;
  
  bval = !digitalRead(START_BUTTON);
  if (bval) {
    sleeping = false;
    resetTime();
  }

  bval = !digitalRead(SLEEP_BUTTON);
  if (bval) {
    sleeping = true;
    clearMatrix();
  }

  if (!sleeping) {
    UpdateTime = UpdateTime + 1;
    if (UpdateTime > 2000) {
      checkTime();
      UpdateTime = 0;
    }
    writeTime(HourTens, HourOnes, MinTens, MinOnes);
  }
}
