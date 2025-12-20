/*
 * Project: Servo Motor Control with Potentiometer
 * Description: Control a servo motor position using a potentiometer
 * Author: XergioAleX
 * Date: 2025
 */

// Include the Servo library
#include <Servo.h>

// Pin definitions
const int SERVO_PIN = 9;           // Servo control pin (PWM-capable)
const int POTENTIOMETER_PIN = A0;   // Analog input pin for potentiometer

// Create servo object
Servo myServo;

// Variables
int potValue = 0;        // Raw reading from potentiometer (0-1023)
int servoAngle = 0;      // Servo position angle (0-180 degrees)

void setup() {
  // Attach servo to pin 9
  // This tells the servo library which pin controls the servo
  myServo.attach(SERVO_PIN);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("Servo Motor Control Started");
  Serial.println("Rotate the potentiometer to control servo position");
}

void loop() {
  // Read the analog value from the potentiometer
  // analogRead() returns a value from 0 to 1023
  potValue = analogRead(POTENTIOMETER_PIN);
  
  // Map the potentiometer value (0-1023) to servo angle (0-180 degrees)
  // This scales the analog input range to the servo position range
  servoAngle = map(potValue, 0, 1023, 0, 180);
  
  // Set the servo position to the calculated angle
  // write() accepts values from 0 to 180 degrees
  myServo.write(servoAngle);
  
  // Print values to Serial Monitor for debugging
  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" | Servo Angle: ");
  Serial.print(servoAngle);
  Serial.println(" degrees");
  
  // Small delay for stability and smooth movement
  delay(15);  // 15ms delay provides smooth servo movement
}



