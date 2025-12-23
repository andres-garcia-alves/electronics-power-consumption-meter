#ifndef DEBUG_H
#define DEBUG_H

// enable/disable debuging
#define DEBUG   true


// initialization
void debugInit()
{
  #if DEBUG
  Serial.begin(9600);
  while (!Serial) { delay(1); }
  #endif
}

// print a message in serial monitor
void debugMessage(String msg)
{
  #if DEBUG
  Serial.println(msg);
  #endif
}

// print a measure in serial monitor
void debugMeasureRawData(RawData rawData)
{
  #if DEBUG
  Serial.print("Bus Voltage:   ");  Serial.print(rawData.busVoltage);    Serial.println(" V");
  Serial.print("Shunt Voltage: ");  Serial.print(rawData.shuntVoltage);  Serial.println(" mV");
  Serial.print("Load Voltage:  ");  Serial.print(rawData.loadVoltage);   Serial.println(" V");
  Serial.print("Current:       ");  Serial.print(rawData.current);       Serial.println(" mA");
  Serial.print("Power:         ");  Serial.print(rawData.power);         Serial.println(" mW");
  Serial.println("");
  #endif
}

#endif
