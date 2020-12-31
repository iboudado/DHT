#include <Arduino.h>
#include "DHTesp.h"

#define DHTPIN 13
DHTesp dht;

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHT22 test!"));
  dht.setup(DHTPIN, dht.DHT22);
  //dht.begin();
}

void loop() {
  delay(2000);
  // Reading temperature or humidity takes about 250 milliseconds! Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  
  float h = dht.getHumidity();
  float t = dht.getTemperature(); // in C (default)
  float f = dht.toFahrenheit(t); // Read temperature as Fahrenheit (isFahrenheit = true)
  // f = toCelsius(f);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}