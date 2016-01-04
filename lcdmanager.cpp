#include "lcdmanager.h"

/* LOOPS */

void LcdManager::loop()
{
  if(state == "HOME")
    loopHomeState();
  else if(state == "SETTINGS")
    loopSettingsState();
  return;
}

void LcdManager::loopHomeState()
{
  if(digitalRead(right) == LOW)
  {
    lcd->setCursor(0, 1);
    lcd->print(*temperature);
    lcd->print(" *C ");
    lcd->print(*humidity);
    lcd->print("%");
  } else {
    beginSettingsState();
  }
}

void LcdManager::loopSettingsState()
{
  if(digitalRead(left) == HIGH)
  {
    beginHomeState();
    return;
  }

  if(digitalRead(down) == HIGH)
  {
    if(menu == 1)
      return;

    lcd->setCursor(10, 1);
    menu = 1;
  }
  else if(digitalRead(up) == HIGH)
  {
    if(menu == 0)
      return;

    lcd->setCursor(11, 0);
    menu = 0;
  }
  else if(digitalRead(right) == HIGH)
  {
    if(menu == 1)
      restart();
    return;
  }
}

/* STATES */

void LcdManager::beginLoadingState()
{
  lcd->clear();
  lcd->blink();
  lcd->print("Chargement...");

  state = "LOADING";
}

void LcdManager::beginHomeState()
{
  lcd->noBlink();
  lcd->home();
  lcd->noBlink();
  lcd->print(ip);

  state = "HOME";  
}

void LcdManager::beginSettingsState()
{
  lcd->clear();
  lcd->print("Temperature");
  lcd->setCursor(0, 1);
  lcd->print("Redemarrer");
  lcd->setCursor(11, 0);
  lcd->blink();
  menu = 0;
  state = "SETTINGS";
}

/* DATAS */

void LcdManager::setIp(IPAddress ip)
{
  this->ip = ip;  
}

void LcdManager::setAmbientDatas(float * humidity, float * temperature)
{
  this->humidity = humidity;
  this->temperature = temperature;
}

void inline LcdManager::restart()
{
  digitalWrite(restart_pin, HIGH);
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

    pinMode(up, INPUT);
    pinMode(left, INPUT);
    pinMode(down, INPUT);
    pinMode(right, INPUT);
    pinMode(restart_pin, OUTPUT);
    digitalWrite(restart_pin, LOW);
}

