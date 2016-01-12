#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <SPI.h>
#include <Ethernet.h>
#include <ArduinoJson.h>

#include "parameters.h"

const int BUFFER_SIZE = JSON_OBJECT_SIZE(2);

class WebServer
{
public:
  WebServer();

  void init(byte * mac);
  IPAddress getLocalIp();

  void loop();

  void setDatas(float * humidity, float * temperature);
  
private:
  EthernetServer * server;

  float * humidity;
  float * temperature;

  StaticJsonBuffer<BUFFER_SIZE> jsonBuffer;
  JsonObject& jsonRoot;
};

#endif
