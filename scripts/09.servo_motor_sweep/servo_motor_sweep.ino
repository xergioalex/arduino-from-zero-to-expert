/*
 * Project: Servo Motor Sweep
 * Description: Automatic back-and-forth sweeping motion of a servo motor
 * Author: XergioAleX
 * Date: 2025
 */

// Include the Servo library
#include <Servo.h>

// Pin definitions
const int SERVO_PIN = 9;  // Servo control pin (PWM-capable)

// Create servo object
Servo myServo;

// Variables
int servoAngle = 0;        // Current servo position (0-180 degrees)
int angleStep = 1;         // How many degrees to move each step
const int MIN_ANGLE = 0;    // Minimum servo angle
const int MAX_ANGLE = 180;  // Maximum servo angle
const int DELAY_MS = 15;    // Delay between movements (milliseconds)

void setup() {
  // Attach servo to pin 9
  myServo.attach(SERVO_PIN);
  
  // Set initial servo position to minimum angle
  myServo.write(servoAngle);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("Servo Motor Sweep Started");
  Serial.println("Servo will sweep from 0 to 180 degrees and back");
}

void loop() {
  // Move servo from MIN_ANGLE to MAX_ANGLE
  for (servoAngle = MIN_ANGLE; servoAngle <= MAX_ANGLE; servoAngle += angleStep) {
    myServo.write(servoAngle);
    Serial.print("Angle: ");
    Serial.println(servoAngle);
    delay(DELAY_MS);
  }
  
  // Move servo from MAX_ANGLE back to MIN_ANGLE
  for (servoAngle = MAX_ANGLE; servoAngle >= MIN_ANGLE; servoAngle -= angleStep) {
    myServo.write(servoAngle);
    Serial.print("Angle: ");
    Serial.println(servoAngle);
    delay(DELAY_MS);
  }
  
  // The loop repeats, creating continuous back-and-forth motion
}

