#include <DHT.h>  // Added missing angle brackets for include

#define DHT_SENSOR_PIN  4 // ESP32 pin GPIO14 connected to DHT22 sensor
#define DHT_SENSOR_TYPE DHT22

DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

void setup() {
  
  Serial.begin(9600);
  dht_sensor.begin(); // initialize the DHT sensor
}

void loop() {
  // read humidity
  float humi  = dht_sensor.readHumidity();
  // read temperature in Celsius
  float tempC = dht_sensor.readTemperature();
  
  // read temperature in Fahrenheit
  float tempF = dht_sensor.readTemperature(true);
  uint8_t tempC_int = uint8_t(tempC);
  uint8_t humi_int = uint8_t(humi);
  // check whether the reading is successful or not
  if ( isnan(tempC) || isnan(tempF) || isnan(humi)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(humi_int);
    Serial.print("%");

    Serial.print("  |  ");
    Serial.print("Temperature: ");
    Serial.print(tempC_int);
      
    Serial.print("°C ");
    Serial.println();
    
  }

  // wait 1 second between readings
  delay(1000);
}