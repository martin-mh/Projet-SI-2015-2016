#include "lcdmanager.h"

/* NEW */

void LcdManager::setup()
{
  menus.push_back(new Loading(this));
  menus.push_back(new Home(this));
  menus.push_back(new Settings(this));

  activeMenuId = 0;
}

void LcdManager::loop()
{
  menus[activeMenuId]->loop();
}

void LcdManager::changeMenu(int menuId)
{
  activeMenuId = menuId;
  menus[menuId]->setup();
}

void LcdManager::registerMenu(Menu * menu)
{
  menus.push_back(menu);
  menu->id = menus.size() - 1;
}

void LcdManager::setData(char * name, char * value)
{
  datas[name] = value;
}

char * LcdManager::data(char * name)
{
  return datas[name];
}

int LcdManager::findMenu(char * name)
{
  for(unsigned int i = 0; i < menus.size(); ++i)
  {
    if(menus[i]->name == name)
    {
      return menus[i]->id;
    }
  }
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

  /* Setup buttons */
  pinMode(UP_PIN, INPUT);
  pinMode(LEFT_PIN, INPUT);
  pinMode(DOWN_PIN, INPUT);
  pinMode(RIGHT_PIN, INPUT);
}
