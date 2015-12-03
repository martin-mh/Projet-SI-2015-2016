/* Parameters start here */
#define DEBUG_MODE 1
/* Parameters end here */

#include "dht22.h"

DhtManager* dht;

void setup() 
{
    Serial.begin(9600); 
    Serial.println();

    dht = new DhtManager();
}

void loop() 
{
    dht->update();
    
    Serial.print("Humidity: "); 
    Serial.print(dht->getHumidity());
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(dht->getTemperature());
    Serial.println(" *C");
}
