#include <Wire.h>
#include <TimerOne.h>

#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>

// Time Variables
uint8_t HourTens = 0;
uint8_t HourOnes = 0;
uint8_t MinTens = 0;
uint8_t MinOnes = 0;
uint8_t SecTens = 0;
uint8_t SecOnes = 0;

boolean showColon = false;

// Constants
// Buttons
#define BUTTON1         2
#define SLEEP_BUTTON    BUTTON1
#define BUTTON2         3
#define START_BUTTON    BUTTON2




