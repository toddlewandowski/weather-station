// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)


float humidity;
float illuminance;
float pressure;
float temperature;

void initProperties(){

  ArduinoCloud.addProperty(humidity, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(illuminance, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(pressure, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(temperature, READ, 1 * SECONDS, NULL);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);