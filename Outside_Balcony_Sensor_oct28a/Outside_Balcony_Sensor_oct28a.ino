#include "arduino_secrets.h"
#include "thingProperties.h"
#include <Arduino_MKRENV.h>

float newPrecision(float n, float i)
{
  return floor(pow(10,i)*n)/pow(10,i);
}

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  
  while(!Serial);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(3);
  ArduinoCloud.printDebugInfo();
  
  if (!ENV.begin()) {
    Serial.println("Failed to initialize MKR ENV shield!");
    while (1);
  }
  
}

void loop() {
  temperature = newPrecision(ENV.readTemperature(FAHRENHEIT),2);
  humidity    = newPrecision(ENV.readHumidity(), 2);
  pressure    = newPrecision(ENV.readPressure(), 2);
  illuminance = newPrecision(ENV.readIlluminance(), 2);
  
  // Print each of the sensor values
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °F");

  Serial.print("Humidity    = ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Pressure    = ");
  Serial.print(pressure);
  Serial.println(" kPa");

  Serial.print("Illuminance = ");
  Serial.print(illuminance);
  Serial.println(" lx");

  // Print an empty line
  Serial.println();

  // Update to the cloud
  ArduinoCloud.update();

  // Wait 1 second
  delay(1000);
}