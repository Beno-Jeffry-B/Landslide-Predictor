#include <ESP8266WiFi.h>
#include <DHT.h>

// DHT Sensor setup
#define DHTPIN 4  // DHT sensor is connected to GPIO 4 (D2 on NodeMCU)
#define DHTTYPE DHT11  // DHT 11 sensor type
DHT dht(DHTPIN, DHTTYPE);

// Variables for timing the interval
unsigned long previousMillis = 0;  
const long interval = 10000;  // Interval set to 10 seconds

void setup() {
  Serial.begin(9600);
  
  // Initialize DHT sensor
  dht.begin();
}

void sendSensorData() {
  float temperature = dht.readTemperature();  // Reading temperature
  float humidity = dht.readHumidity();  // Reading humidity
  int soilMoistureValue = analogRead(A0);  // Reading soil moisture
  soilMoistureValue = map(soilMoistureValue, 400, 1023, 100, 0);  // Adjust the range to 0-100%

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print values to Serial Monitor
  Serial.println("====================================");
  Serial.print("Soil Moisture: ");
  Serial.print(soilMoistureValue);
  Serial.println("%");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  Serial.println("====================================");
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if 10 seconds have passed
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Save the last time sensor data was sent
    
    // Call the function to print sensor data to Serial Monitor
    sendSensorData();
  }
}