#ifndef INPUT_H
#define INPUT_H

WorkingMode workingMode;

// function declaration
void setLedsMode(bool voltage, bool current, bool power);


// initialization
void inputInit()
{
  pinMode(PUSH_BTN, INPUT_PULLUP);
  pinMode(LED_VOLTAGE, OUTPUT);
  pinMode(LED_CURRENT, OUTPUT);
  pinMode(LED_POWER, OUTPUT);

  workingMode = VOLTAGE;
  setLedsMode(true, false, false);
}

// getters & setters
WorkingMode getWorkingMode()              { return workingMode; }
void setWorkingMode(WorkingMode newMode)  { workingMode = newMode; }

// checks and process sw-button to change working mode
void processInput()
{
  bool btnMode;
  
  btnMode = digitalRead(PUSH_BTN);
  if (btnMode == HIGH) { return; }
  delay(DEBOUNCE_TIME);
  if (btnMode == HIGH) { return; }

  displayBlank();

  while (btnMode == LOW)
    btnMode = digitalRead(PUSH_BTN);
  delay(DEBOUNCE_TIME);

  if (workingMode == VOLTAGE)       { workingMode = CURRENT;  setLedsMode(false, true, false); }
  else if (workingMode == CURRENT)  { workingMode = POWER;    setLedsMode(false, false, true); }
  else if (workingMode == POWER)    { workingMode = VOLTAGE;  setLedsMode(true, false, false); }
  else                              { workingMode = VOLTAGE;  setLedsMode(true, false, false); }
}

void setLedsMode(bool voltage, bool current, bool power)
{
  digitalWrite(LED_VOLTAGE, voltage ? HIGH : LOW);
  digitalWrite(LED_CURRENT, current ? HIGH : LOW);
  digitalWrite(LED_POWER,   power   ? HIGH : LOW);
}

#endif
