#ifndef MEASUREMENTS_H
#define MEASUREMENTS_H
#include <Wire.h>
#include <Adafruit_INA219.h>

#define MEASURE_TIMESPAN 2000

Adafruit_INA219 ina219;
RawData rawData;
unsigned long timeNow = 0;
unsigned long timeLastMeasure = -MEASURE_TIMESPAN;


// initialization
void measureInit()
{
  // sensor INA219 initialization
  if (!ina219.begin()) {
    debugMessage("Failed to find INA219 chip");
    while (1) { delay(50); }
  }

  // ina219.setCalibration_32V_2A(); // default
  // ina219.setCalibration_32V_1A(); // higher precision on amps
  ina219.setCalibration_16V_400mA(); // higher precision on volts and amps
}

// gets current measure data (refresh every 2 segs)
RawData measureGetRawData()
{
  timeNow = millis();
  if (timeNow - timeLastMeasure < MEASURE_TIMESPAN) { return rawData; }

  // new measure
  rawData.busVoltage    = ina219.getBusVoltage_V();
  rawData.shuntVoltage  = ina219.getShuntVoltage_mV();
  rawData.loadVoltage   = rawData.busVoltage + (rawData.shuntVoltage / 1000);
  rawData.current       = ina219.getCurrent_mA();
  rawData.power         = ina219.getPower_mW();

  debugMeasureRawData(rawData);
  timeLastMeasure = millis();

  return rawData;
}

#endif
