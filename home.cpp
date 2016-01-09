#include "home.h"
#include "lcdmanager.h"

void Home::setup()
{
  lcd->home();
  lcd->noBlink();
  lcd->print(lcd->datas->localIp);
}

void Home::loop()
{
  if(digitalRead(RIGHT_PIN) == LOW)
  {
    lcd->setCursor(0, 1);
    lcd->print(*lcd->datas->temperature);
    lcd->print(" *C ");
    lcd->print(*lcd->datas->humidity);
    lcd->print("%");
  } else 
  {
    lcd->changeMenu(lcd->findMenu("SETTINGS"));
  }
}

Home::Home(LcdManager * lcd) : Menu(lcd, "HOME")
{
	lcd->registerMenu(this);
}