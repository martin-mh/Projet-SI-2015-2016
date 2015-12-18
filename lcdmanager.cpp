#include "lcdmanager.h"

void LcdManager::loop()
{
  if(state == "HOME")
    loopHomeState();
  return;
}

void LcdManager::beginLoadingState()
{
  lcd->clear();
  lcd->blink();
  lcd->print("Chargement...");

  state = "LOADING";
}

void LcdManager::loopHomeState()
{
  lcd->setCursor(0, 1);
  lcd->print(*temperature);
  lcd->print(" *C ");
  lcd->print(*humidity);
  lcd->print("%");
}

void LcdManager::beginHomeState()
{
  lcd->clear();
  lcd->noBlink();
  lcd->setCursor(0, 0);
  lcd->print(ip);

  state = "HOME";  
}

void LcdManager::setIp(IPAddress ip)
{
  this->ip = ip;  
}

void LcdManager::setAmbientDatas(float * humidity, float * temperature)
{
  this->humidity = humidity;
  this->temperature = temperature;
}

LcdManager::LcdManager()
{
  lcd = new LiquidCrystal(LCD_RS,
    LCD_ENABLE,
    LCD_D0,
    LCD_D1,
    LCD_D2,
    LCD_D3);
    lcd->begin(LCD_WIDTH, LCD_HEIGHT);

    state = "EMPTY";
}

