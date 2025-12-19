/*
 * Project: LED Fade Effect
 * Description: Create a smooth fade in/out effect on an LED using PWM (Pulse Width Modulation)
 * Author: XergioAleX
 * Date: 2025
 */

// Pin definitions
const int LED_PIN = 9;  // Must be a PWM-capable pin (marked with ~ on Arduino Uno: 3, 5, 6, 9, 10, 11)

// Fade variables
int brightness = 0;     // Current LED brightness (0-255)
int fadeAmount = 5;     // Amount to fade by each step (change this to speed up/slow down)

void setup() {
  // Initialize the LED pin as an output
  // Note: PWM pins don't need special setup, just use pinMode as OUTPUT
  pinMode(LED_PIN, OUTPUT);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("LED Fade Effect Started");
  Serial.println("Watch the LED fade in and out smoothly");
}

void loop() {
  // Set the brightness of the LED using PWM
  // analogWrite() accepts values from 0 (fully off) to 255 (fully on)
  analogWrite(LED_PIN, brightness);
  
  // Print current brightness to Serial Monitor
  Serial.print("Brightness: ");
  Serial.println(brightness);
  
  // Change the brightness for next time through the loop
  brightness = brightness + fadeAmount;
  
  // Reverse the direction of fading at the ends of the fade
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;  // Reverse direction
  }
  
  // Wait for 30 milliseconds to see the dimming effect
  // Adjust this value to change fade speed (lower = faster, higher = slower)
  delay(30);
}

