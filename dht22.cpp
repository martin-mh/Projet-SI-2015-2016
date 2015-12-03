#include "dht22.h"

DhtManager::DhtManager()
  : dht(DHTPIN, DHTTYPE),
    temperature(0),
    humidity(0)
{
  dht.begin();

#if DEBUG_MODE
  Serial.println("DhtManager initialized");
#endif
}

void DhtManager::update()
{
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  if(isnan(temperature) || isnan(humidity))
    errored = true;
  else
    errored = false;
}

bool DhtManager::isErrored()
{
  return errored;
}

float DhtManager::getTemperature()
{
  return temperature;
}

float DhtManager::getHumidity()
{
  return humidity;
}

