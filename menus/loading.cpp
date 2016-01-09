#include "loading.h"
#include "lcdmanager.h"

void Loading::setup()
{
	lcd->home();
	lcd->print("Chargement...");
	lcd->blink();
}

void Loading::loop(){}

Loading::Loading(LcdManager * lcd) : Menu(lcd), name("LOADING")
{
	lcd->registerMenu(this);
}