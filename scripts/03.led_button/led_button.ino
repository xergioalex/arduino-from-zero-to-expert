/*
 * Project: LED Button Control
 * Description: Control an LED with a push button - press to toggle LED on/off
 * Author: XergioAleX
 * Date: 2025
 */

// Pin definitions
const int LED_PIN = 12;        // LED connected to pin 12
const int BUTTON_PIN = 2;      // Button connected to pin 2

// Button state variables
int buttonState = 0;            // Current reading from the button
int lastButtonState = 0;         // Previous reading from the button
int ledState = LOW;              // Current state of the LED

void setup() {
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  // Initialize the button pin as an input with internal pull-up resistor
  // When button is not pressed, pin reads HIGH (due to pull-up)
  // When button is pressed, pin reads LOW (connected to GND)
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("LED Button Control Started");
  Serial.println("Press the button to toggle the LED");
}

void loop() {
  // Read the current state of the button
  buttonState = digitalRead(BUTTON_PIN);
  
  // Check if button state changed from HIGH to LOW (button pressed)
  // This detects the moment the button is pressed (edge detection)
  if (buttonState == LOW && lastButtonState == HIGH) {
    // Toggle the LED state
    ledState = !ledState;
    
    // Update the LED
    digitalWrite(LED_PIN, ledState);
    
    // Print status to Serial Monitor
    if (ledState == HIGH) {
      Serial.println("LED turned ON");
    } else {
      Serial.println("LED turned OFF");
    }
    
    // Small delay to avoid multiple toggles from button bounce
    delay(50);
  }
  
  // Save the current button state for the next loop iteration
  lastButtonState = buttonState;
}

