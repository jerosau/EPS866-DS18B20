#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// GPIO where the temperature sensor is connected
#define ONE_WIRE_BUS 4

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature sensors(&oneWire);

void setup()
{
  // Start the Serial Monitor
  Serial.begin(9600);
  // Activate internal PULL UP resistor
  pinMode(ONE_WIRE_BUS, INPUT_PULLUP);
  // Start the DS18B20 sensor
  sensors.begin();
  delay(1000);

  Serial.println("Hello, ESP8266!");

  // Grab a count of devices on the wire
  int numberOfDevices = sensors.getDeviceCount();

  // locate devices on the bus
  Serial.print("Locating devices...");
  Serial.print("Found ");
  Serial.print(numberOfDevices, DEC);
  Serial.println(" devices.");
}

void loop()
{
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);
  // Output Teleplot Console
  Serial.print(">temperature: ");
  Serial.println(temperatureC);
  // Output Console
  Serial.print(temperatureC);
  Serial.println("ºC");
  delay(2000);
}
