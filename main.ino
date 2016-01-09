#include <StandardCplusplus.h>
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
  lcd->setup();
    
  Serial.begin(9600);
  Debug::setup(&Serial);

  dht = new DhtManager();
    
  ws = new WebServer();
  Debug::println("WebServer created");
  ws->init(mac);
  Debug::println("WebServer inited");

  lcd->setData("IP", ws->getLocalIp());
  lcd->setData("HUMIDITY", *dht->getHumidity());
  lcd->setData("TEMPERATURE", *dht->getTemperature());
    
  lcd->changeMenu(0);

  ws->setDatas(dht->getHumidity(), dht->getTemperature());
}

void loop() 
{
  dht->update();
  
  lcd->setData("HUMIDITY", *dht->getHumidity());
  lcd->setData("TEMPERATURE", *dht->getTemperature());

  ws->loop();
  lcd->loop();
    
  Serial.print("Humidity: "); 
  Serial.print(*dht->getHumidity());
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(*dht->getTemperature());
  Serial.println(" *C");
}
