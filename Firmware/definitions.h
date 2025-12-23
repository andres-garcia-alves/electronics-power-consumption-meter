#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// display: digit selector pins
#define DISPLAY_DIGIT_1   13
#define DISPLAY_DIGIT_2   4
#define DISPLAY_DIGIT_3   3
#define DISPLAY_DIGIT_4   5

// display: segment pins
#define DISPLAY_SEG_A     12
#define DISPLAY_SEG_B     2
#define DISPLAY_SEG_C     7
#define DISPLAY_SEG_D     9
#define DISPLAY_SEG_E     10
#define DISPLAY_SEG_F     11
#define DISPLAY_SEG_G     6
#define DISPLAY_SEG_DOT   8

// sensor INA219
#define I2C_SCL           A5
#define I2C_SDA           A4

// other hardware
#define LED_VOLTAGE       A0
#define LED_CURRENT       A1
#define LED_POWER         A2
#define PUSH_BTN          A3

// miscellaneous
#define DEBOUNCE_TIME     50

// enumerations
enum WorkingMode { VOLTAGE, CURRENT, POWER };

// data structures
struct RawData
{
  float busVoltage = 0;
  float shuntVoltage = 0;
  float loadVoltage = 0;
  float current = 0;
  float power = 0;
};

#endif
