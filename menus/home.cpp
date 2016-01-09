#include "home.h"
#include "../lcdmanager.h"

void Home::begin()
{
  lcd->home();
  lcd->noBlink();
  lcd->print(lcd->data("IP"));
}

void Home::loop()
{
  if(digitalRead(RIGHT_PIN) == LOW)
  {
    lcd->setCursor(0, 1);
    lcd->print(lcd->data("TEMPERATURE"));
    lcd->print(" *C ");
    lcd->print(lcd->data("HUMIDITY"));
    lcd->print("%");
  } else 
  {
    lcd->changeMenu(lcd->findMenu("SETTINGS"));
  }
}

Home::Home(LcdManager * lcd) : Menu(lcd), name("HOME")
{
	lcd->registerMenu(this);
}