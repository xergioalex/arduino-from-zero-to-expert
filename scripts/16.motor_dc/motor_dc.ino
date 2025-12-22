/*
 * Project: Motor DC Control with L298N
 * Description: Control a DC motor speed and direction using L298N motor driver
 * Author: XergioAleX
 * Date: 2025
 */

// Pin definitions for L298N Motor Driver
const int ENA_PIN = 9;    // Enable pin A (PWM for speed control)
const int IN1_PIN = 8;    // Input 1 (direction control)
const int IN2_PIN = 7;    // Input 2 (direction control)

// Motor speed (0-255, PWM value)
int motorSpeed = 200;     // Start at medium speed

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("Motor DC Control with L298N Started");
  Serial.println("---");
  
  // Configure pins as outputs
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  
  // Stop motor initially
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
  analogWrite(ENA_PIN, 0);
  
  Serial.println("Motor stopped. Starting sequence...");
  delay(1000);
}

void loop() {
  // Forward direction
  Serial.println("Motor: FORWARD");
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);
  analogWrite(ENA_PIN, motorSpeed);
  Serial.print("Speed: ");
  Serial.println(motorSpeed);
  delay(3000);
  
  // Stop
  Serial.println("Motor: STOP");
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
  analogWrite(ENA_PIN, 0);
  delay(1000);
  
  // Reverse direction
  Serial.println("Motor: REVERSE");
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);
  analogWrite(ENA_PIN, motorSpeed);
  Serial.print("Speed: ");
  Serial.println(motorSpeed);
  delay(3000);
  
  // Stop
  Serial.println("Motor: STOP");
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
  analogWrite(ENA_PIN, 0);
  delay(1000);
  
  // Speed ramp up (forward)
  Serial.println("Motor: Speed ramp UP (forward)");
  for (int speed = 0; speed <= 255; speed += 10) {
    digitalWrite(IN1_PIN, HIGH);
    digitalWrite(IN2_PIN, LOW);
    analogWrite(ENA_PIN, speed);
    Serial.print("Speed: ");
    Serial.println(speed);
    delay(100);
  }
  
  // Speed ramp down
  Serial.println("Motor: Speed ramp DOWN");
  for (int speed = 255; speed >= 0; speed -= 10) {
    analogWrite(ENA_PIN, speed);
    Serial.print("Speed: ");
    Serial.println(speed);
    delay(100);
  }
  
  // Stop
  Serial.println("Motor: STOP");
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
  analogWrite(ENA_PIN, 0);
  delay(2000);
  
  Serial.println("--- Cycle complete, repeating...");
}

