/*
 * Project: Servo Motor Control with Buttons
 * Description: Control a servo motor position using push buttons (left/right)
 * Author: XergioAleX
 * Date: 2025
 */

// Include the Servo library
#include <Servo.h>

// Pin definitions
const int SERVO_PIN = 9;           // Servo control pin (PWM-capable)
const int LEFT_BUTTON_PIN = 2;      // Button to move servo left (counterclockwise)
const int RIGHT_BUTTON_PIN = 3;     // Button to move servo right (clockwise)

// Create servo object
Servo myServo;

// Variables
int leftButtonState = 0;      // Current reading from left button
int rightButtonState = 0;    // Current reading from right button
int lastLeftButtonState = 0;  // Previous reading from left button
int lastRightButtonState = 0; // Previous reading from right button
int servoAngle = 90;          // Current servo position (starts at center: 90°)
const int ANGLE_STEP = 5;     // How many degrees to move per button press
const int MIN_ANGLE = 0;       // Minimum servo angle
const int MAX_ANGLE = 180;     // Maximum servo angle

void setup() {
  // Attach servo to pin 9
  myServo.attach(SERVO_PIN);
  
  // Initialize button pins as inputs with internal pull-up resistors
  pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP);
  
  // Set initial servo position to center (90 degrees)
  myServo.write(servoAngle);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("Servo Motor Button Control Started");
  Serial.println("Press LEFT button to move counterclockwise");
  Serial.println("Press RIGHT button to move clockwise");
  Serial.print("Initial position: ");
  Serial.print(servoAngle);
  Serial.println(" degrees");
}

void loop() {
  // Read the current state of both buttons
  leftButtonState = digitalRead(LEFT_BUTTON_PIN);
  rightButtonState = digitalRead(RIGHT_BUTTON_PIN);
  
  // Check if LEFT button was just pressed (edge detection)
  // Button reads LOW when pressed (due to pull-up configuration)
  if (leftButtonState == LOW && lastLeftButtonState == HIGH) {
    // Move servo left (decrease angle)
    servoAngle = servoAngle - ANGLE_STEP;
    
    // Limit to minimum angle
    if (servoAngle < MIN_ANGLE) {
      servoAngle = MIN_ANGLE;
    }
    
    // Update servo position
    myServo.write(servoAngle);
    
    // Print status
    Serial.print("LEFT pressed - Angle: ");
    Serial.print(servoAngle);
    Serial.println(" degrees");
    
    // Small delay to avoid multiple triggers from button bounce
    delay(50);
  }
  
  // Check if RIGHT button was just pressed (edge detection)
  if (rightButtonState == LOW && lastRightButtonState == HIGH) {
    // Move servo right (increase angle)
    servoAngle = servoAngle + ANGLE_STEP;
    
    // Limit to maximum angle
    if (servoAngle > MAX_ANGLE) {
      servoAngle = MAX_ANGLE;
    }
    
    // Update servo position
    myServo.write(servoAngle);
    
    // Print status
    Serial.print("RIGHT pressed - Angle: ");
    Serial.print(servoAngle);
    Serial.println(" degrees");
    
    // Small delay to avoid multiple triggers from button bounce
    delay(50);
  }
  
  // Save the current button states for the next loop iteration
  lastLeftButtonState = leftButtonState;
  lastRightButtonState = rightButtonState;
}

