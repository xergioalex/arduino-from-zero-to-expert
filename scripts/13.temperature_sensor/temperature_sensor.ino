/*
 * Project: Temperature Sensor - LM35
 * Description: Read temperature from LM35 temperature sensor and display it
 * Author: XergioAleX
 * Date: 2025
 */

// Pin definitions
const int TEMP_SENSOR_PIN = A0;  // LM35 analog input pin

// Variables
int sensorValue = 0;        // Raw reading from sensor (0-1023)
float voltage = 0.0;        // Voltage reading in volts
float temperature = 0.0;    // Temperature in Celsius

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("Temperature Sensor (LM35) Started");
  Serial.println("Reading temperature...");
  Serial.println("---");
}

void loop() {
  // Read the analog value from the temperature sensor
  // analogRead() returns a value from 0 to 1023
  sensorValue = analogRead(TEMP_SENSOR_PIN);
  
  // Convert the analog reading to voltage
  // Arduino analog input: 0-1023 maps to 0-5V
  // Formula: voltage = (sensorValue / 1023.0) * 5.0
  voltage = (sensorValue / 1023.0) * 5.0;
  
  // Convert voltage to temperature
  // LM35: 10mV per degree Celsius
  // Formula: temperature = voltage * 100
  // Example: 0.25V = 25°C, 0.30V = 30°C
  temperature = voltage * 100.0;
  
  // Print temperature to Serial Monitor
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 2);  // 2 decimal places
  Serial.print("V | Temperature: ");
  Serial.print(temperature, 1);  // 1 decimal place
  Serial.println("°C");
  
  // Wait 1 second before next reading
  delay(1000);
}

