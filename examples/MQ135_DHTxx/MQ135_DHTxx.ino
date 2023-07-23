#include <MQ135.h>
#include <DHT.h>

/* MQ135 + DHT Temp Sensor

   Combination of the MQ135 air quality sensor and a DHT11/22 temperature sensor to accurately measure ppm values through the library correction.
   Uses the Adafruit DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library

   Written by: https://github.com/NuclearPhoenixx/MQ135
*/

#define PIN_MQ135 A2 // MQ135 Analog Input Pin
#define DHTPIN 2 // DHT Digital Input Pin
#define DHTTYPE DHT11 // DHT11 or DHT22, depends on your sensor

MQ135 mq135_sensor(PIN_MQ135);
DHT dht(DHTPIN, DHTTYPE);

float temperature, humidity; // Temp and Humid floats, will be measured by the DHT

void setup() {
  Serial.begin(9600);

  dht.begin();
}

void loop() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float rzero = mq135_sensor.getRZero();
  float correctedRZero = mq135_sensor.getCorrectedRZero(temperature, humidity);
  float resistance = mq135_sensor.getResistance();
  float ppm = mq135_sensor.getPPM();
  float correctedPPM = mq135_sensor.getCorrectedPPM(temperature, humidity);

  Serial.print("MQ135 RZero: ");
  Serial.print(rzero);
  Serial.print("\t Corrected RZero: ");
  Serial.print(correctedRZero);
  Serial.print("\t Resistance: ");
  Serial.print(resistance);
  Serial.print("\t PPM: ");
  Serial.print(ppm);
  Serial.print("ppm");
  Serial.print("\t Corrected PPM: ");
  Serial.print(correctedPPM);
  Serial.println("ppm");

  delay(300);
}
