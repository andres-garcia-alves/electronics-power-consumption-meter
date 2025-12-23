#ifndef DISPLAY_H
#define DISPLAY_H
#include <Arduino.h>
#include "SevSeg.h"
#include "definitions.h"

#define N_DIGITS 4
#define BRIGHTNESS 90 // 0-100

SevSeg sevseg;

byte digitPins[] = {DISPLAY_DIGIT_1, DISPLAY_DIGIT_2, DISPLAY_DIGIT_3, DISPLAY_DIGIT_4};
byte segmentPins[] =  {DISPLAY_SEG_A, DISPLAY_SEG_B, DISPLAY_SEG_C, DISPLAY_SEG_D, DISPLAY_SEG_E, DISPLAY_SEG_F, DISPLAY_SEG_G, DISPLAY_SEG_DOT};


void displayInit()
{
  sevseg.begin(COMMON_ANODE, N_DIGITS, digitPins, segmentPins);
  sevseg.setBrightness(BRIGHTNESS);
}

void displayValueNumber(float valueNumber)
{
  sevseg.setNumber(valueNumber * 10, 1);
  sevseg.refreshDisplay();
}

#endif
