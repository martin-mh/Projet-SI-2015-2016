#ifndef HOME_H
#define HOME_H

#include "../parameters.h"

#include "../menu.h"

class LcdManager;

class Home : public Menu
{
public:
  Home(LcdManager*);
  virtual void setup();
  virtual void loop();
};

#endif