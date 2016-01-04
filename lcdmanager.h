#ifndef LCDMANAGER_H
#define LCDMANAGER_H

#include <LiquidCrystal.h>
#include <Ethernet.h>
#include "parameters.h"

class LcdManager
{
public:
  LcdManager();

  void loop();

  void beginLoadingState();
  void beginHomeState();
  void beginSettingsState();

  void setIp(IPAddress ip);
  void setAmbientDatas(float * humidity, float * temperature);

private:
  void loopHomeState();
  void loopSettingsState();

  void inline restart(); // Emit a signal in order to restart the Arduino Board

  LiquidCrystal * lcd;
  IPAddress ip;
  float * temperature;
  float * humidity;

  /* Button's pins */
  const int up = UP_PIN;
  const int left = LEFT_PIN;
  const int down = DOWN_PIN;
  const int right = RIGHT_PIN;
  const int restart_pin = RESTART_PIN;

  /* Actual state representing the content of the LCD */
  String state; // keywords : EMPTY or LOADING or HOME or SETTINGS
  short menu; // Represent the actual menu choice
};

#endif
