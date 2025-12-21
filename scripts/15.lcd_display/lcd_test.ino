/*
 * LCD Test - Simple test to verify connections
 * This will help identify if pins are connected correctly
 */

#include <LiquidCrystal.h>

// Try this configuration first (as per README)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  
  // Wait a bit for LCD to power up
  delay(100);
  
  // Initialize LCD
  lcd.begin(16, 2);
  
  // Wait for LCD to initialize
  delay(100);
  
  // Clear display
  lcd.clear();
  delay(50);
  
  // Show simple test on first line
  lcd.setCursor(0, 0);
  lcd.print("Hello!");
  
  // Show test on second line
  lcd.setCursor(0, 1);
  lcd.print("LCD Works!");
  
  Serial.println("LCD Test Started");
  Serial.println("Test text displayed");
}

void loop() {
  // Just keep displaying - no need to clear in loop
  delay(1000);
}

