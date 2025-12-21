/*
 * Project: Buzzer Basic - Simple Sound Generation
 * Description: Generate basic sounds and single notes using a buzzer
 * Author: XergioAleX
 * Date: 2025
 */

// Pin definitions
const int BUZZER_PIN = 9;  // Buzzer connected to PWM-capable pin

// Musical note frequencies (in Hz)
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("Buzzer Basic - Simple Sound Generation Started");
  Serial.println("Playing individual notes...");
}

void loop() {
  // Play individual notes one at a time
  // Each note plays for 500ms
  
  Serial.println("Playing C4...");
  tone(BUZZER_PIN, NOTE_C4);
  delay(500);
  noTone(BUZZER_PIN);
  delay(200);
  
  Serial.println("Playing D4...");
  tone(BUZZER_PIN, NOTE_D4);
  delay(500);
  noTone(BUZZER_PIN);
  delay(200);
  
  Serial.println("Playing E4...");
  tone(BUZZER_PIN, NOTE_E4);
  delay(500);
  noTone(BUZZER_PIN);
  delay(200);
  
  Serial.println("Playing F4...");
  tone(BUZZER_PIN, NOTE_F4);
  delay(500);
  noTone(BUZZER_PIN);
  delay(200);
  
  Serial.println("Playing G4...");
  tone(BUZZER_PIN, NOTE_G4);
  delay(500);
  noTone(BUZZER_PIN);
  delay(200);
  
  Serial.println("Playing A4...");
  tone(BUZZER_PIN, NOTE_A4);
  delay(500);
  noTone(BUZZER_PIN);
  delay(200);
  
  Serial.println("Playing B4...");
  tone(BUZZER_PIN, NOTE_B4);
  delay(500);
  noTone(BUZZER_PIN);
  delay(200);
  
  Serial.println("Playing C5...");
  tone(BUZZER_PIN, NOTE_C5);
  delay(500);
  noTone(BUZZER_PIN);
  
  // Longer pause before repeating
  Serial.println("---");
  delay(2000);
}

