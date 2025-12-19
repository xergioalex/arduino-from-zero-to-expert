/*
 * Project: LED Brightness Control with Potentiometer
 * Description: Control LED brightness using a potentiometer (analog input)
 * Author: XergioAleX
 * Date: 2025
 */

// Pin definitions
const int LED_PIN = 9;           // PWM-capable pin for LED (marked with ~ on Arduino Uno)
const int POTENTIOMETER_PIN = A0; // Analog input pin for potentiometer

// Variables
int potValue = 0;        // Raw reading from potentiometer (0-1023)
int ledBrightness = 0;   // LED brightness value (0-255)

void setup() {
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  // Note: Analog pins (A0-A5) don't need pinMode() for input
  // They are inputs by default
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("LED Potentiometer Control Started");
  Serial.println("Rotate the potentiometer to control LED brightness");
}

void loop() {
  // Read the analog value from the potentiometer
  // analogRead() returns a value from 0 to 1023
  // 0 = 0V (one end of potentiometer)
  // 1023 = 5V (other end of potentiometer)
  potValue = analogRead(POTENTIOMETER_PIN);
  
  // Map the potentiometer value (0-1023) to LED brightness (0-255)
  // This scales the analog input range to the PWM output range
  ledBrightness = map(potValue, 0, 1023, 0, 255);
  
  // Set the LED brightness using PWM
  // analogWrite() accepts values from 0 (off) to 255 (fully on)
  analogWrite(LED_PIN, ledBrightness);
  
  // Print values to Serial Monitor for debugging
  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" | LED Brightness: ");
  Serial.println(ledBrightness);
  
  // Small delay for stability (optional, but helps with serial output)
  delay(10);
}

