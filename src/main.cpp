#include <Arduino.h>
#include <hse_lib.h>
void setup()
{
  // Input Configuration
  HSELib::setPreAlarmInput(2);
  HSELib::setCraneDangerInput(3);
  HSELib::setCraneWarningInput(4);
  HSELib::setSenWarningInput(5);
  // Output Configuration
  HSELib::setBuzzerOutput(6);
  HSELib::setDangerStateOutput(7, true);
  HSELib::setNormalStateOutput(8);
  HSELib::setWarningStateOutput(9);
  // Blink duration
  HSELib::setToggleDuration(500,true);
}

void loop()
{
  HSELib::update();
}