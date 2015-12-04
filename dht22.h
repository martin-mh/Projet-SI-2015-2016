#ifndef DHT22_H
#define DHT22_H

#include "parameters.h"

#include "DHT.h"

class DhtManager
{
public:
  DhtManager();

  void update();
  float getTemperature();
  float getHumidity();
  bool isErrored();
  
private:
  DHT dht;

  float temperature;
  float humidity;

  bool errored;
};

#endif
