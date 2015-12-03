#include "DHT.h"

#define DHTPIN A0
#define DHTTYPE DHT22

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
