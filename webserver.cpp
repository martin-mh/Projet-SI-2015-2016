#include "webserver.h"

WebServer::WebServer() : jsonRoot(jsonBuffer.createObject())
{
}

void WebServer::loop()
{
  EthernetClient client = server->available();
  if (client) 
  {
    Serial.println("new client");

    jsonRoot["temperature"] = *temperature;
    jsonRoot["humidity"] = *humidity;

    boolean currentLineIsBlank = true;
    
    while (client.connected())
    {
      if (client.available()) 
      {
        char c = client.read();
        
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        
        if (c == '\n' && currentLineIsBlank) 
        {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close"); 
          client.println("Refresh: 5");
          client.println();
          jsonRoot.printTo(client);
          break;
        }
        if (c == '\n') 
        {
          currentLineIsBlank = true;
        } else if (c != '\r') 
        {
          currentLineIsBlank = false;
        }
      }
    }
    
    delay(1);
    client.stop();
    Serial.println("client disconnected");
    Ethernet.maintain();
  }
}

void WebServer::init(byte * mac)
{  
  Ethernet.begin(mac);
  server = new EthernetServer(80);
}

void WebServer::setDatas(float * humidity, float * temperature)
{
  this->humidity = humidity;
  this->temperature = temperature;
}

IPAddress WebServer::getLocalIp()
{
  return Ethernet.localIP();
}

