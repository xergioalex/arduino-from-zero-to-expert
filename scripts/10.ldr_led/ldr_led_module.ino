/*
 * Project: LDR Module - Automatic LED Control (Using Digital Output)
 * Description: Turn on LED automatically when it gets dark using LDR Module with digital output
 * Author: XergioAleX
 * Date: 2025
 * 
 * This version uses the LDR Module's digital output (DO) pin
 * The module has a built-in comparator (LM393) and potentiometer for threshold adjustment
 */

// Pin definitions
const int LED_PIN = 12;          // LED output pin
const int LDR_DO_PIN = 2;        // LDR Module Digital Output pin (DO)
                                  // DO goes LOW when dark, HIGH when bright

// Variables to track state changes
int lastLdrState = HIGH;         // Previous LDR reading
int currentLedState = LOW;        // Current LED state

void setup() {
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  // Initialize the LDR module digital output pin as an input
  // The module's DO pin outputs digital signal (LOW/HIGH)
  pinMode(LDR_DO_PIN, INPUT_PULLUP);
  
  // Set initial LED state
  digitalWrite(LED_PIN, LOW);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("LDR Module - Automatic LED Control Started");
  Serial.println("Using Digital Output (DO) from LDR Module");
  Serial.println("LED will turn ON when it gets dark");
  Serial.println("Adjust module potentiometer to set sensitivity");
  Serial.println("---");
}

void loop() {
  // Read the digital output from LDR module
  // When dark: DO = LOW (0)
  // When bright: DO = HIGH (1)
  // Note: Using INPUT_PULLUP, so logic is inverted
  // LOW = dark detected, HIGH = bright
  
  int ldrDigital = digitalRead(LDR_DO_PIN);
  
  // Only update and print when state changes (prevents constant serial output)
  if (ldrDigital != lastLdrState) {
    // State changed - update LED and print message
    // Note: Logic may be inverted depending on module configuration
    // If LED turns on with light, invert the condition below
    
    if (ldrDigital == HIGH) {
      // It's dark - turn LED ON
      digitalWrite(LED_PIN, HIGH);
      currentLedState = HIGH;
      Serial.println("Dark detected - LED ON");
    } else {
      // It's bright - turn LED OFF
      digitalWrite(LED_PIN, LOW);
      currentLedState = LOW;
      Serial.println("Bright - LED OFF");
    }
    
    // Update last state
    lastLdrState = ldrDigital;
  }
  
  // Small delay for stability (reduced serial output means less TX activity)
  delay(50);
}

