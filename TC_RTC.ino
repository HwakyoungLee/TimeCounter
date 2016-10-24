//*******************************************************************************************************************
//                                                  Check Time
//*******************************************************************************************************************
uint8_t i2cData = 0;

void checkTime()
{
  I2C_RX(RTCDS1337, RTC_SEC);
  SecOnes = i2cData & B00001111;                  
  SecTens = i2cData & B01110000;                  
  SecTens = SecTens >> 4;

  I2C_RX(RTCDS1337, RTC_MIN);
  MinOnes = i2cData & B00001111;                   
  MinTens = i2cData & B01110000;                  
  MinTens = MinTens >> 4;

  I2C_RX(RTCDS1337, RTC_HOUR);
  HourOnes = i2cData & B00001111;
  HourTens = i2cData & B00110000;
  HourTens = HourTens >> 4;
}

void resetTime()
{
  I2C_TX(RTCDS1337, RTC_HOUR, 0);
  I2C_TX(RTCDS1337, RTC_MIN, 0);
  I2C_TX(RTCDS1337, RTC_SEC, 0);
}


