#include <LiquidCrystal.h>

#include "parameters.h"

#include "debug.h"

#include "dht22.h"
#include "webserver.h"

LiquidCrystal lcd(12,11,5,4,3,2);
const int lcdCol = 16;
const int lcdRow = 2;

byte mac[] = { MAC };  

DhtManager * dht;
WebServer * ws;

void setup() 
{
    lcd.begin(lcdCol, lcdRow);
    lcd.blink();
    lcd.print("Chargement...");
    
    Serial.begin(9600);
    Serial.println();
    Debug::setup(&Serial);

    dht = new DhtManager();
    
    ws = new WebServer();
    Debug::println("WebServer created");
    ws->init(mac);
    Debug::println("WebServer inited");

    lcd.clear();
    lcd.noBlink();
    lcd.setCursor(0, 0);
    lcd.print(ws->getLocalIp());
    ws->setDatas(dht->getHumidity(), dht->getTemperature());
}

void loop() 
{
    dht->update();
    ws->loop();
    
    Serial.print("Humidity: "); 
    Serial.print(*dht->getHumidity());
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(*dht->getTemperature());
    Serial.println(" *C");

    lcd.setCursor(0, 1);
    lcd.print(*dht->getTemperature());
    lcd.print(" *C ");
    lcd.print(*dht->getHumidity());
    lcd.print(" %     ");

    //delay(1000);
}
