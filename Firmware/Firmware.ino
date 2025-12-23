#include "definitions.h"
#include "display.h"
#include "measurements.h"

MeasureData measureData;
float valueNumber;
eWorkingMode workingMode = VOLTAGE;


void setup(void) 
{
  debugInit();
  displayInit();
  measureInit();

  pinMode(PUSH_BTN, INPUT_PULLUP);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
}

void loop(void) 
{
  checkInput();
  measureData = measureGetData();
  valueNumber = processData(workingMode, measureData);
  displayValueNumber(valueNumber);

  // bool asd = digitalRead(PUSH_BTN);
  // delay(DEBOUNCE_TIME);
}

float processData(eWorkingMode workingMode, MeasureData measureData)
{
  if (workingMode == VOLTAGE)       { return measureData.loadVoltage; }
  else if (workingMode == CURRENT)  { return measureData.current; }
  else if (workingMode == POWER)    { return measureData.power; }
  else                              { return 0; }
}

void checkInput()
{
  bool  = digitalRead(PUSH_BTN);
  Serial.println(v);
  delay(1000);
}
