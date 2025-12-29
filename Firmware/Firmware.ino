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
  if (!rawData.isValid) { displayInvalid(); return; }

  // ignore the direction of the electric current
  rawData.current = abs(rawData.current);

  // correct spurious reading under no-load conditions
  if (rawData.current < SPURIOUS_THRESHOLD) { // < 0.5 mA
    rawData.loadVoltage = 0.0;
    rawData.current = 0.0;
    rawData.power = 0.0;
  }

  // display que correct value
  WorkingMode workingMode = getWorkingMode();
  if (workingMode == VOLTAGE)       { displayNumber(rawData.loadVoltage, 2); }
  else if (workingMode == CURRENT)  { displayNumber(rawData.current, 1); }
  else if (workingMode == POWER)    { displayNumber(rawData.power, 1); }
  else                              { displayBlank(); }
}
