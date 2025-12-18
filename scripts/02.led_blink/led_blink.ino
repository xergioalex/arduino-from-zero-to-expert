/*
 * Project: LED Blink Example
 * Description: Simple example to turn on an LED (built-in or external)
 * Author: XergioAleX
 * Date: 2025
 */

// Pin definitions
const int LED_PIN = 12;
// For external LED, connect: LED anode -> resistor (330Ω) -> pin 12, LED cathode -> GND

void setup() {
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  // Optional: Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("LED Blink Example Started");
}

void loop() {
  // Turn LED on
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED ON");
  delay(1000);  // Wait for 1 second (1000 milliseconds)
  
  // Turn LED off
  digitalWrite(LED_PIN, LOW);
  Serial.println("LED OFF");
  delay(1000);  // Wait for 1 second
  
  // The loop continues indefinitely, creating a blinking effect
}
