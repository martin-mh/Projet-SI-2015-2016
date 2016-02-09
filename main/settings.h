/* 
  This file has the class Settings who's not any kind of settings
  but is the settings menu.
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include "parameters.h"

#include "menu.h"

class LcdManager;

class Settings : public Menu
{
public:
  Settings(LcdManager*);
  virtual void setup();
  virtual void loop();

private:
	int menu;
};

#endif