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

  void setIp(IPAddress ip);
  void setAmbientDatas(float * humidity, float * temperature);

private:
  void loopHomeState();

  LiquidCrystal * lcd;
  IPAddress ip;
  float * temperature;
  float * humidity;

  /* Actual state representing the content of the LCD */
  String state; // keywords : EMPTY or LOADING or HOME
};

#endif
