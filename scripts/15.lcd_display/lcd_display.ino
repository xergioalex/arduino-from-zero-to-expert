/*
 * Project: LCD Display 16x2
 * Description: Display text on a 16x2 LCD display using parallel connection
 * Author: XergioAleX
 * Date: 2025
 */

// Include the LiquidCrystal library (built-in Arduino library)
#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
// LiquidCrystal(RS, E, D4, D5, D6, D7)
// Using 4-bit mode (only D4-D7 connected, D0-D3 not used)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Wait a bit for LCD to power up
  delay(100);
  
  // Initialize the LCD with number of columns and rows
  lcd.begin(16, 2);
  
  // Wait for LCD to initialize properly
  delay(100);
  
  // Clear display
  lcd.clear();
  delay(50);
  
  // Print welcome message on first line
  lcd.setCursor(0, 0);  // Column 0, Row 0 (first line)
  lcd.print("Hello, Arduino!");
  
  // Print message on second line
  lcd.setCursor(0, 1);  // Column 0, Row 1 (second line)
  lcd.print("LCD 16x2 Works!");
  
  Serial.println("LCD Display 16x2 Started");
  Serial.println("LCD initialized and text displayed");
  delay(2000);  // Wait 2 seconds
}

void loop() {
  // Clear the display
  lcd.clear();
  
  // Display current time (milliseconds since start)
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  lcd.print(millis() / 1000);  // Convert to seconds
  lcd.print(" seconds");
  
  // Display counter
  static int counter = 0;
  counter++;
  lcd.setCursor(0, 1);
  lcd.print("Counter: ");
  lcd.print(counter);
  
  // Print to Serial Monitor as well
  Serial.print("Time: ");
  Serial.print(millis() / 1000);
  Serial.print("s | Counter: ");
  Serial.println(counter);
  
  // Update every 1 second
  delay(1000);
}

