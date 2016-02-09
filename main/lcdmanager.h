#ifndef LCDMANAGER_H
#define LCDMANAGER_H

#include <LiquidCrystal.h>
#include <Ethernet.h>

#include <StandardCplusplus.h>
#include <vector>

#include "datas.h"
#include "menu.h"
#include "parameters.h"

#include "loading.h"
#include "home.h"
#include "settings.h"

class LcdManager : public LiquidCrystal
{
public:
  LcdManager(Datas * data);

  void registerMenu(Menu * id);

  void setup();
  void loop();

  void changeMenu(int menuId);
  int findMenu(char * name);

  Datas * datas;
  
private:
  std::vector<Menu*> menus;
  int activeMenuId;
};

#endif
