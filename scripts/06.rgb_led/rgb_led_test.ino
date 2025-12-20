/*
 * Project: RGB LED Diagnostic Test
 * Description: Test each RGB LED channel individually to diagnose problems
 * Author: XergioAleX
 * Date: 2025
 * 
 * USE THIS CODE TO DIAGNOSE YOUR RGB LED PROBLEM
 */

// Pin definitions for RGB LED (must be PWM-capable pins)
const int RED_PIN = 9;     // Red channel (PWM pin)
const int GREEN_PIN = 10;  // Green channel (PWM pin)
const int BLUE_PIN = 11;   // Blue channel (PWM pin)

void setup() {
  // Initialize all RGB pins as outputs
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("========================================");
  Serial.println("RGB LED DIAGNOSTIC TEST");
  Serial.println("========================================");
  Serial.println("This test will check each channel individually");
  Serial.println("Watch the LED and note which colors work");
  Serial.println("========================================");
  delay(2000);
}

void loop() {
  // Test 1: Turn OFF all channels
  Serial.println("\n>>> TEST 1: All OFF");
  setColor(0, 0, 0);
  delay(2000);
  
  // Test 2: RED channel only (FULL brightness)
  Serial.println(">>> TEST 2: RED channel (255) - Should see RED");
  setColor(255, 0, 0);
  delay(3000);
  
  // Test 3: RED channel (MEDIUM brightness)
  Serial.println(">>> TEST 3: RED channel (128) - Should see dim RED");
  setColor(128, 0, 0);
  delay(2000);
  
  // Test 4: GREEN channel only (FULL brightness)
  Serial.println(">>> TEST 4: GREEN channel (255) - Should see GREEN");
  setColor(0, 255, 0);
  delay(3000);
  
  // Test 5: GREEN channel (MEDIUM brightness)
  Serial.println(">>> TEST 5: GREEN channel (128) - Should see dim GREEN");
  setColor(0, 128, 0);
  delay(2000);
  
  // Test 6: BLUE channel only (FULL brightness)
  Serial.println(">>> TEST 6: BLUE channel (255) - Should see BLUE");
  setColor(0, 0, 255);
  delay(3000);
  
  // Test 7: BLUE channel (MEDIUM brightness)
  Serial.println(">>> TEST 7: BLUE channel (128) - Should see dim BLUE");
  setColor(0, 0, 128);
  delay(2000);
  
  // Test 8: Try COMMON ANODE mode (inverted values)
  Serial.println(">>> TEST 8: COMMON ANODE test - RED (inverted)");
  setColorAnode(255, 0, 0);
  delay(3000);
  
  Serial.println(">>> TEST 9: COMMON ANODE test - GREEN (inverted)");
  setColorAnode(0, 255, 0);
  delay(3000);
  
  Serial.println(">>> TEST 10: COMMON ANODE test - BLUE (inverted)");
  setColorAnode(0, 0, 255);
  delay(3000);
  
  Serial.println("\n========================================");
  Serial.println("DIAGNOSTIC COMPLETE");
  Serial.println("Check which tests showed colors");
  Serial.println("========================================\n");
  delay(5000);
}

/*
 * Function: setColor (Common Cathode)
 * For common cathode RGB LED
 */
void setColor(int red, int green, int blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

/*
 * Function: setColorAnode (Common Anode)
 * For common anode RGB LED - inverts the values
 */
void setColorAnode(int red, int green, int blue) {
  analogWrite(RED_PIN, 255 - red);
  analogWrite(GREEN_PIN, 255 - green);
  analogWrite(BLUE_PIN, 255 - blue);
}



