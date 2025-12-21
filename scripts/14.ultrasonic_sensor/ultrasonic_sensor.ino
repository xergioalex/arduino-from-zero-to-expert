/*
 * Project: Ultrasonic Sensor - HC-SR04
 * Description: Measure distance using HC-SR04 ultrasonic sensor
 * Author: XergioAleX
 * Date: 2025
 */

// Pin definitions
const int TRIG_PIN = 9;   // Trigger pin (output)
const int ECHO_PIN = 10;   // Echo pin (input)

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
  // The sound wave travels to the object and back, so we divide by 2
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate distance
  // Speed of sound: 343 m/s = 0.0343 cm/microsecond
  // Distance = (duration * speed of sound) / 2
  // Formula: distance = (duration * 0.0343) / 2 = duration * 0.01715
  // Simplified: distance = duration / 58.2 (approximately)
  distance = duration * 0.0343 / 2.0;
  
  // Print distance to Serial Monitor
  Serial.print("Duration: ");
  Serial.print(duration);
  Serial.print(" microseconds | Distance: ");
  Serial.print(distance, 2);  // 2 decimal places
  Serial.println(" cm");
  
  // Wait 500ms before next measurement
  delay(500);
}

