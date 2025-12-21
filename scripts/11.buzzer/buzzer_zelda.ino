/*
 * Project: Buzzer Zelda - Saria's Song
 * Description: Play Saria's Song from The Legend of Zelda: Ocarina of Time
 * Author: XergioAleX
 * Date: 2025
 */

// Pin definitions
const int BUZZER_PIN = 9;  // Buzzer connected to PWM-capable pin

// Musical note frequencies (in Hz)
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_D6  1175
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_G6  1568
#define NOTE_A6  1760
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_D7  2349
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_G7  3136
#define NOTE_A7  3520

// Note duration constants
#define WHOLE_NOTE    2000
#define HALF_NOTE     1000
#define QUARTER_NOTE  500
#define EIGHTH_NOTE   250
#define SIXTEENTH_NOTE 125

// Melody: "Saria's Song" from The Legend of Zelda: Ocarina of Time
// One of the most recognizable and beloved songs from the game
// Pattern: D-F-A ascending in different octaves
int melody[] = {
  NOTE_D4, NOTE_F4, NOTE_A4, NOTE_D5, NOTE_F5, NOTE_A5,  // First phrase - ascending
  NOTE_D5, NOTE_F5, NOTE_A5, NOTE_D6, NOTE_F6, NOTE_A6,  // Second phrase - higher octave
  NOTE_D6, NOTE_F6, NOTE_A6, NOTE_D7, NOTE_F7, NOTE_A7,  // Third phrase - highest octave
  NOTE_D7, NOTE_F7, NOTE_A7, NOTE_D6, NOTE_F6, NOTE_A6,  // Descending back
  NOTE_D6, NOTE_F6, NOTE_A6, NOTE_D5, NOTE_F5, NOTE_A5,  // Continue descending
  NOTE_D5, NOTE_F5, NOTE_A5, NOTE_D4, NOTE_F4, NOTE_A4   // Final phrase - back to start
};

// Note durations (in milliseconds) - eighth notes for short notes, quarter notes for longer
int noteDurations[] = {
  EIGHTH_NOTE, EIGHTH_NOTE, QUARTER_NOTE, EIGHTH_NOTE, EIGHTH_NOTE, QUARTER_NOTE,  // First phrase
  EIGHTH_NOTE, EIGHTH_NOTE, QUARTER_NOTE, EIGHTH_NOTE, EIGHTH_NOTE, QUARTER_NOTE,  // Second phrase
  EIGHTH_NOTE, EIGHTH_NOTE, QUARTER_NOTE, EIGHTH_NOTE, EIGHTH_NOTE, QUARTER_NOTE,  // Third phrase
  EIGHTH_NOTE, EIGHTH_NOTE, QUARTER_NOTE, EIGHTH_NOTE, EIGHTH_NOTE, QUARTER_NOTE,  // Descending
  EIGHTH_NOTE, EIGHTH_NOTE, QUARTER_NOTE, EIGHTH_NOTE, EIGHTH_NOTE, QUARTER_NOTE,  // Continue descending
  EIGHTH_NOTE, EIGHTH_NOTE, QUARTER_NOTE, EIGHTH_NOTE, EIGHTH_NOTE, QUARTER_NOTE   // Final phrase
};

// Number of notes in the melody
const int MELODY_LENGTH = sizeof(melody) / sizeof(melody[0]);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("Buzzer Zelda - Saria's Song Started");
  Serial.print("Playing melody: Saria's Song (");
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
  delay(3000);  // 3 second pause before repeating
}

