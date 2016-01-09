#ifndef LCDMANAGER_H
#define LCDMANAGER_H
#include <StandardCplusplus.h>
#include <LiquidCrystal.h>
#include <Ethernet.h>

#include <serstream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <new.cpp>

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
  const char * data(char * name);

  void setup();
  void loop();

  void changeMenu(int menuId);
  int findMenu(char * name);
  
private:
  std::vector<Menu*> menus;
  int activeMenuId;
  std::map<std::string, std::string> datas;

  LiquidCrystal * lcd;
};

#endif
