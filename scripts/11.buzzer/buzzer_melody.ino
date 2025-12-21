/*
 * Project: Buzzer Melody - Play Complete Melodies
 * Description: Play complete melodies using arrays of notes and durations
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
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988
#define NOTE_C6  1047

// Note duration constants
#define WHOLE_NOTE    2000
#define HALF_NOTE     1000
#define QUARTER_NOTE  500
#define EIGHTH_NOTE   250
#define SIXTEENTH_NOTE 125

// Melody: "Twinkle Twinkle Little Star"
// Notes: C C G G A A G
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4
};

// Note durations (in milliseconds)
int noteDurations[] = {
  QUARTER_NOTE, QUARTER_NOTE, QUARTER_NOTE, QUARTER_NOTE, QUARTER_NOTE, QUARTER_NOTE, HALF_NOTE,
  QUARTER_NOTE, QUARTER_NOTE, QUARTER_NOTE, QUARTER_NOTE, QUARTER_NOTE, QUARTER_NOTE, HALF_NOTE
};

// Number of notes in the melody
const int MELODY_LENGTH = sizeof(melody) / sizeof(melody[0]);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("Buzzer Melody - Play Complete Melodies Started");
  Serial.print("Playing melody: Twinkle Twinkle Little Star (");
  Serial.print(MELODY_LENGTH);
  Serial.println(" notes)");
  Serial.println("---");
}

void loop() {
  // Play the complete melody
  for (int i = 0; i < MELODY_LENGTH; i++) {
    // Calculate note duration
    int noteDuration = noteDurations[i];
    
    // Play the note
    tone(BUZZER_PIN, melody[i], noteDuration);
    
    // Wait for the note duration plus a small pause between notes
    // This creates a staccato effect (notes don't overlap)
    delay(noteDuration * 1.3);  // 1.3 = note duration + 30% pause
    
    // Stop the tone (though tone() with duration parameter stops automatically)
    noTone(BUZZER_PIN);
    
    // Small pause between notes
    delay(50);
  }
  
  // Longer pause before repeating the melody
  Serial.println("Melody finished. Repeating...");
  delay(2000);
}

