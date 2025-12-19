/*
 * Project: RGB LED Color Control
 * Description: Control an RGB LED to display different colors
 * Author: XergioAleX
 * Date: 2025
 */

// Pin definitions for RGB LED (must be PWM-capable pins)
const int RED_PIN = 9;     // Red channel (PWM pin)
const int GREEN_PIN = 10;  // Green channel (PWM pin)
const int BLUE_PIN = 11;   // Blue channel (PWM pin)

// Color delay (time each color is displayed)
const int COLOR_DELAY = 1000;  // 1 second per color

void setup() {
  // Initialize all RGB pins as outputs
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("RGB LED Color Control Started");
  Serial.println("Displaying different colors...");
}

void loop() {
  // Display different colors in sequence
  
  // Red
  setColor(255, 0, 0);
  Serial.println("Color: RED");
  delay(COLOR_DELAY);
  
  // Green
  setColor(0, 255, 0);
  Serial.println("Color: GREEN");
  delay(COLOR_DELAY);
  
  // Blue
  setColor(0, 0, 255);
  Serial.println("Color: BLUE");
  delay(COLOR_DELAY);
  
  // Yellow (Red + Green)
  setColor(255, 255, 0);
  Serial.println("Color: YELLOW");
  delay(COLOR_DELAY);
  
  // Magenta (Red + Blue)
  setColor(255, 0, 255);
  Serial.println("Color: MAGENTA");
  delay(COLOR_DELAY);
  
  // Cyan (Green + Blue)
  setColor(0, 255, 255);
  Serial.println("Color: CYAN");
  delay(COLOR_DELAY);
  
  // White (Red + Green + Blue)
  setColor(255, 255, 255);
  Serial.println("Color: WHITE");
  delay(COLOR_DELAY);
  
  // Off (all channels off)
  setColor(0, 0, 0);
  Serial.println("Color: OFF");
  delay(COLOR_DELAY);
}

/*
 * Function: setColor
 * Description: Sets the RGB LED to a specific color
 * Parameters:
 *   red: Red channel brightness (0-255)
 *   green: Green channel brightness (0-255)
 *   blue: Blue channel brightness (0-255)
 */
void setColor(int red, int green, int blue) {
  // Write PWM values to each color channel
  // For common cathode RGB LED, higher value = brighter
  // For common anode RGB LED, you would invert: 255 - value
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

