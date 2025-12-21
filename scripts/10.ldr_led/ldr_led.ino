/*
 * Project: LDR Light Sensor - Automatic LED Control
 * Description: Turn on LED automatically when it gets dark using LDR (Light Dependent Resistor)
 * Author: XergioAleX
 * Date: 2025
 */

// Pin definitions
const int LED_PIN = 12;          // LED output pin
const int LDR_PIN = A0;          // LDR analog input pin

// Variables
int ldrValue = 0;                // Raw reading from LDR (0-1023)
const int DARK_THRESHOLD = 500;  // Threshold value - adjust this to change sensitivity
                                  // Lower value = LED turns on in brighter conditions
                                  // Higher value = LED turns on only in darker conditions

void setup() {
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  // Note: Analog pins (A0-A5) don't need pinMode() for input
  // They are inputs by default
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("LDR Light Sensor - Automatic LED Control Started");
  Serial.println("LED will turn ON when it gets dark");
  Serial.print("Dark threshold: ");
  Serial.println(DARK_THRESHOLD);
  Serial.println("Cover the LDR to see the LED turn on");
}

void loop() {
  // Read the analog value from the LDR
  // analogRead() returns a value from 0 to 1023
  // Lower values = more light (brighter)
  // Higher values = less light (darker)
  ldrValue = analogRead(LDR_PIN);
  
  // Check if it's dark (LDR value is above threshold)
  // When dark, LDR resistance increases, voltage increases, reading increases
  if (ldrValue > DARK_THRESHOLD) {
    // It's dark - turn LED ON
    digitalWrite(LED_PIN, HIGH);
    Serial.print("Dark detected (LDR: ");
    Serial.print(ldrValue);
    Serial.println(") - LED ON");
  } else {
    // It's bright - turn LED OFF
    digitalWrite(LED_PIN, LOW);
    Serial.print("Bright (LDR: ");
    Serial.print(ldrValue);
    Serial.println(") - LED OFF");
  }
  
  // Small delay for stability and readable serial output
  delay(100);
}

