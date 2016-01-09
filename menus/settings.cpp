#include "settings.h"
#include "../lcdmanager.h"

void Settings::setup()
{
  menu = 0;
  
  lcd->home();
  lcd->print("Temperature");
  lcd->setCursor(0, 1);
  lcd->print("Serveur web");
  lcd->setCursor(11, 0);
  lcd->blink();
}

void Settings::loop()
{
  if(digitalRead(LEFT_PIN) == HIGH)
  {
    lcd->changeMenu(lcd->findMenu("HOME"));
  }
  else if(digitalRead(DOWN_PIN) == HIGH)
  {
    if(menu == 1)
      return;

    lcd->setCursor(11, 1);
    menu = 1;
  }
  else if(digitalRead(UP_PIN) == HIGH)
  {
    if(menu == 0)
      return;

    lcd->setCursor(11, 0);
    menu = 0;
  }
  else if(digitalRead(RIGHT_PIN) == HIGH)
  {
    if(menu == 1)
    	return; //TODO
  }
}

Settings::Settings(LcdManager * lcd) : Menu(lcd), name("SETTINGS")
{
  lcd->registerMenu(this);
}