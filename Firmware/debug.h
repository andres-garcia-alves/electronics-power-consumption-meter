#ifndef DEBUG_H
#define DEBUG_H
#include "definitions.h"

// enable/disable debuging
#define DEBUG   true


void debugInit()
{
  #if DEBUG
  Serial.begin(9600);
  while (!Serial) { delay(1); }
  #endif
}

void debugMessage(String msg)
{
  #if DEBUG
  Serial.println(msg);
  #endif
}

void debugMeasure(MeasureData measureData)
{
  #if DEBUG
  Serial.print("Bus Voltage:   ");  Serial.print(measureData.busVoltage);    Serial.println(" V");
  Serial.print("Shunt Voltage: ");  Serial.print(measureData.shuntVoltage);  Serial.println(" mV");
  Serial.print("Load Voltage:  ");  Serial.print(measureData.loadVoltage);   Serial.println(" V");
  Serial.print("Current:       ");  Serial.print(measureData.current);       Serial.println(" mA");
  Serial.print("Power:         ");  Serial.print(measureData.power);         Serial.println(" mW");
  Serial.println("");
  #endif
}

#endif
