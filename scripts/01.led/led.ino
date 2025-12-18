/*
 * Project: LED ON Example
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
  Serial.println("LED ON Example Started");

  // Turn LED on
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED ON");
}

void loop() {
  // Nothing is needed here because the LED remains ON after setup
}
