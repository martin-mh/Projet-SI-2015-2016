#ifndef MENU_H
#define MENU_H

class LcdManager;

class Menu
{
public:
  Menu(LcdManager*);
  virtual void setup() = 0;
  virtual void loop() = 0;

  char * name;
  int id;

protected:
  LcdManager * lcd;
};

#endif
