// DS1337+ Address locations
#define RTCDS1337 B01101000   // was B11010000  
#define RTCCONT   B00001110   // Control
#define RTCSTATUS B00001111   // Status

#define RTC_HSEC  B00000001   // Hundredth of a secound
#define RTC_SEC   B00000000   // Seconds
#define RTC_MIN   B00000001   // Minuites
#define RTC_HOUR  B00000010   // Hours
#define RTC_DAY   B00000011   // Day
#define RTC_DATE  B00000100   // Date
#define RTC_MONTH B00000101   // Month
#define RTC_YEAR  B00000110   // Year

#define RTC_ALARM1SEC   B00000111   // Seconds
#define RTC_ALARM1MIN   B00001000   // Minuites
#define RTC_ALARM1HOUR  B00001001   // Hours
#define RTC_ALARM1DATE  B00001010   // Date

void checkTime()
{
  uint8_t data;
  
  data = I2C_RX(RTCDS1337, RTC_SEC);
  SecOnes = data & B00001111;                  
  SecTens = data & B01110000;                  
  SecTens = SecTens >> 4;

  data = I2C_RX(RTCDS1337, RTC_MIN);
  MinOnes = data & B00001111;                   
  MinTens = data & B01110000;                  
  MinTens = MinTens >> 4;

  data = I2C_RX(RTCDS1337, RTC_HOUR);
  HourOnes = data & B00001111;
  HourTens = data & B00110000;
  HourTens = HourTens >> 4;
}

void resetTime()
{
  I2C_TX(RTCDS1337, RTC_HOUR, 0);
  I2C_TX(RTCDS1337, RTC_MIN, 0);
  I2C_TX(RTCDS1337, RTC_SEC, 0);
}


