#include "definitions.h"
#include "debug.h"
#include "display.h"
#include "input.h"
#include "measurements.h"

void setup(void) 
{
  debugInit();
  displayInit();
  measureInit();
  inputInit();
}

void loop(void)
{
  processInput();

  RawData rawData = measureGetRawData();
  processData(rawData);
}

void processData(RawData rawData)
{
  WorkingMode workingMode = getWorkingMode();
  
  if (workingMode == VOLTAGE)       { displayNumber(rawData.loadVoltage, 2); }
  else if (workingMode == CURRENT)  { displayNumber(rawData.current, 1); }
  else if (workingMode == POWER)    { displayNumber(rawData.power, 1); }
  else                              { displayBlank(); }
}
