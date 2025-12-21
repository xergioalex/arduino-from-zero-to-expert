/*
 * Project: Buzzer Button - Control Sounds with Buttons
 * Description: Play different sounds when buttons are pressed
 * Author: XergioAleX
 * Date: 2025
 */

// Pin definitions
const int BUZZER_PIN = 9;        // Buzzer connected to PWM-capable pin
const int BUTTON1_PIN = 2;        // Button 1 - Play note C
const int BUTTON2_PIN = 3;        // Button 2 - Play note E
const int BUTTON3_PIN = 4;        // Button 3 - Play note G
const int BUTTON4_PIN = 5;        // Button 4 - Play melody

// Musical note frequencies (in Hz)
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

// Button state variables
int button1State = 0;
int button2State = 0;
int button3State = 0;
int button4State = 0;
int lastButton1State = 0;
int lastButton2State = 0;
int lastButton3State = 0;
int lastButton4State = 0;

// Melody for button 4
int melody[] = {NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5};
int melodyDurations[] = {200, 200, 200, 400};

void setup() {
  // Initialize buzzer pin as output (not strictly necessary, but good practice)
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Initialize button pins as inputs with internal pull-up resistors
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);
  pinMode(BUTTON4_PIN, INPUT_PULLUP);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("Buzzer Button Control Started");
  Serial.println("Button 1: Play C note");
  Serial.println("Button 2: Play E note");
  Serial.println("Button 3: Play G note");
  Serial.println("Button 4: Play melody");
  Serial.println("---");
}

void loop() {
  // Read the current state of all buttons
  button1State = digitalRead(BUTTON1_PIN);
  button2State = digitalRead(BUTTON2_PIN);
  button3State = digitalRead(BUTTON3_PIN);
  button4State = digitalRead(BUTTON4_PIN);
  
  // Check if Button 1 was just pressed (edge detection)
  if (button1State == LOW && lastButton1State == HIGH) {
    Serial.println("Button 1 pressed - Playing C note");
    tone(BUZZER_PIN, NOTE_C4, 300);
    delay(50);  // Small delay to avoid multiple triggers
  }
  
  // Check if Button 2 was just pressed
  if (button2State == LOW && lastButton2State == HIGH) {
    Serial.println("Button 2 pressed - Playing E note");
    tone(BUZZER_PIN, NOTE_E4, 300);
    delay(50);
  }
  
  // Check if Button 3 was just pressed
  if (button3State == LOW && lastButton3State == HIGH) {
    Serial.println("Button 3 pressed - Playing G note");
    tone(BUZZER_PIN, NOTE_G4, 300);
    delay(50);
  }
  
  // Check if Button 4 was just pressed
  if (button4State == LOW && lastButton4State == HIGH) {
    Serial.println("Button 4 pressed - Playing melody");
    playMelody();
    delay(50);
  }
  
  // Save the current button states for the next loop iteration
  lastButton1State = button1State;
  lastButton2State = button2State;
  lastButton3State = button3State;
  lastButton4State = button4State;
}

/*
 * Function: playMelody
 * Description: Plays a short melody (C-E-G-C chord)
 */
void playMelody() {
  for (int i = 0; i < 4; i++) {
    tone(BUZZER_PIN, melody[i], melodyDurations[i]);
    delay(melodyDurations[i] * 1.2);
    noTone(BUZZER_PIN);
    delay(50);
  }
}

