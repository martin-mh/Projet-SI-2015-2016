#ifndef LOADING_H
#define LOADING_H

#include "parameters.h"

#include "menu.h"

class LcdManager;

class Loading : public Menu
{
public:
  Loading(LcdManager*);
  virtual void setup();
  virtual void loop();
};

#endif