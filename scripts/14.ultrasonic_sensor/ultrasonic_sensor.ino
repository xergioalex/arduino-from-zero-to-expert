/*
 * Project: Ultrasonic Sensor - HC-SR04
 * Description: Measure distance using HC-SR04 ultrasonic sensor
 * Author: XergioAleX
 * Date: 2025
 */

// Pin definitions
const int TRIG_PIN = 9;   // Trigger pin (output)
const int ECHO_PIN = 10;   // Echo pin (input)

// Sensor specifications
const float SOUND_SPEED = 0.0343;  // Speed of sound in cm/microsecond
const int MIN_DISTANCE = 2;        // Minimum valid distance (cm)
const int MAX_DISTANCE = 400;      // Maximum valid distance (cm)
const unsigned long TIMEOUT = 30000; // Timeout for pulseIn in microseconds (30ms)

// Variables
long duration = 0;         // Duration of pulse in microseconds
float distance = 0.0;     // Distance in centimeters

void setup() {
  // Initialize trigger pin as output
  pinMode(TRIG_PIN, OUTPUT);
  
  // Initialize echo pin as input
  pinMode(ECHO_PIN, INPUT);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor (HC-SR04) Started");
  Serial.println("Measuring distance...");
  Serial.println("---");
}

void loop() {
  // Clear the trigger pin (set to LOW)
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  // Send ultrasonic pulse: set trigger pin HIGH for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Read the echo pin: pulseIn() returns the duration of the pulse in microseconds
  // pulseIn() waits for the pin to go HIGH, then measures how long it stays HIGH
  // Added timeout to prevent hanging on invalid readings
  duration = pulseIn(ECHO_PIN, HIGH, TIMEOUT);
  
  // Check if we got a valid reading (pulseIn returns 0 on timeout)
  if (duration == 0) {
    // No echo received - object too far or no object detected
    Serial.println("No echo received - object out of range or no object detected");
    delay(500);
    return;
  }
  
  // Calculate distance
  // Speed of sound: 343 m/s = 0.0343 cm/microsecond
  // Distance = (duration * speed of sound) / 2
  distance = duration * SOUND_SPEED / 2.0;
  
  // Validate distance is within sensor range
  if (distance < MIN_DISTANCE || distance > MAX_DISTANCE) {
    // Distance out of valid range - likely noise or invalid reading
    Serial.print("Invalid reading: ");
    Serial.print(distance, 2);
    Serial.println(" cm (out of range 2-400 cm)");
    delay(500);
    return;
  }
  
  // Print valid distance to Serial Monitor
  Serial.print("Duration: ");
  Serial.print(duration);
  Serial.print(" microseconds | Distance: ");
  Serial.print(distance, 2);  // 2 decimal places
  Serial.println(" cm");
  
  // Wait 500ms before next measurement
  delay(500);
}

