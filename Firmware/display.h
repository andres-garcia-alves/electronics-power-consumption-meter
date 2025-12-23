#ifndef DISPLAY_H
#define DISPLAY_H
#include "SevSeg.h"

#define N_DIGITS      4
#define BRIGHTNESS    50  // range 0-100

SevSeg sevseg;

byte digitPins[] = {DISPLAY_DIGIT_1, DISPLAY_DIGIT_2, DISPLAY_DIGIT_3, DISPLAY_DIGIT_4};
byte segmentPins[] =  {DISPLAY_SEG_A, DISPLAY_SEG_B, DISPLAY_SEG_C, DISPLAY_SEG_D, DISPLAY_SEG_E, DISPLAY_SEG_F, DISPLAY_SEG_G, DISPLAY_SEG_DOT};


// initialization
void displayInit()
{
  sevseg.begin(COMMON_ANODE, N_DIGITS, digitPins, segmentPins);
  sevseg.setBrightness(BRIGHTNESS);
}

// display a float number
void displayNumber(float number, byte decimals)
{
  sevseg.setNumberF(number, decimals);
  sevseg.refreshDisplay();
}

// cleans the display
void displayBlank()
{
  sevseg.blank();
  sevseg.refreshDisplay();
}

#endif
