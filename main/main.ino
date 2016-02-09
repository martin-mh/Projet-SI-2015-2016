#include <StandardCplusplus.h>
#include "parameters.h"

#include "debug.h"

#include "dht22.h"
#include "webserver.h"
#include "lcdmanager.h"
#include "datas.h"

byte mac[] = { MAC };  

DhtManager * dht;
WebServer * ws;
LcdManager * lcd;
Datas * datas;

void setup() 
{
  datas = new Datas();

  lcd = new LcdManager(datas);
  lcd->setup();
    
  Serial.begin(9600);
  Debug::setup(&Serial);

  dht = new DhtManager();
    
  ws = new WebServer();
  Debug::println("WebServer created");
  //ws->init(mac);
  Debug::println("WebServer inited");

  datas->localIp = IPAddress();
  datas->humidity = dht->getHumidity();
  datas->temperature = dht->getTemperature();

  lcd->changeMenu(1);

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
