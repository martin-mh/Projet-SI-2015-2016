#ifndef LCDMANAGER_H
#define LCDMANAGER_H

#include <LiquidCrystal.h>
#include <Ethernet.h>

#include <StandardCplusplus.h>
#include <vector>
#include <map>

#include "menu.h"
#include "parameters.h"

#include "menus/loading.h"
#include "menus/home.h"
#include "menus/settings.h"

class LcdManager
{
public:
  LcdManager();

  void registerMenu(Menu * id);

  void setData(char * name, char * value);
  char * data(char * name);

  void setup();
  void loop();

  void changeMenu(int menuId);
  int findMenu(char * name);
  
private:
  std::vector<Menu*> menus;
  int activeMenuId;
  std::map<char*, char*> datas;

  LiquidCrystal * lcd;
};

#endif
