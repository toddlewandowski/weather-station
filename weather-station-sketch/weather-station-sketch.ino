/*
  MKR ENV Shield - Read Sensors

  This example reads the sensors on-board the MKR ENV Shield
  and prints them to the Serial Monitor once a second.

  The circuit:
  - Arduino MKR board
  - Arduino MKR ENV Shield attached

  This example code is in the public domain.
*/

#include <Arduino_MKRENV.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!ENV.begin()) {
    Serial.println("Failed to initialize MKR ENV Shield!");
    while (1);
  }
}

void loop() {
  // read all the sensor values
  float temperature = ENV.readTemperature(FAHRENHEIT);
  float humidity    = ENV.readHumidity();
  float pressure    = ENV.readPressure(MILLIBAR);
  float illuminance = ENV.readIlluminance();

  // print each of the sensor values
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °F");

  Serial.print("Humidity    = ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Pressure    = ");
  Serial.print(pressure);
  Serial.println(" millibar");

  Serial.print("Illuminance = ");
  Serial.print(illuminance);
  Serial.println(" lx");

  // print an empty line
  Serial.println();

  // wait 1 second to print again
  delay(1000);
}
