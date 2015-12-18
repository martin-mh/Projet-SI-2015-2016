#include "parameters.h"

#include "debug.h"

#include "dht22.h"
#include "webserver.h"
#include "lcdmanager.h"

byte mac[] = { MAC };  

DhtManager * dht;
WebServer * ws;
LcdManager * lcd;

void setup() 
{
  lcd = new LcdManager();
  lcd->beginLoadingState();
    
    Serial.begin(9600);
    Serial.println();
    Debug::setup(&Serial);

    dht = new DhtManager();
    
    ws = new WebServer();
    Debug::println("WebServer created");
    ws->init(mac);
    Debug::println("WebServer inited");

    lcd->setIp(ws->getLocalIp());
    lcd->setAmbientDatas(dht->getHumidity(), dht->getTemperature());
    lcd->beginHomeState();
    
    ws->setDatas(dht->getHumidity(), dht->getTemperature());
}

void loop() 
{
    dht->update();
    ws->loop();
    lcd->loop();
    
    Serial.print("Humidity: "); 
    Serial.print(*dht->getHumidity());
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(*dht->getTemperature());
    Serial.println(" *C");
}
