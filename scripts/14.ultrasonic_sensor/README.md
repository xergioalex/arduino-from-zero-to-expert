# Ultrasonic Sensor - HC-SR04

Measure distance using an HC-SR04 ultrasonic sensor. This project demonstrates how to use ultrasonic sensors to detect objects and measure distances, useful for robotics, obstacle detection, and proximity sensing.

## 📋 Project Description

This project measures distance using an HC-SR04 ultrasonic sensor. The sensor sends out ultrasonic sound waves and measures how long they take to bounce back, calculating distance based on the speed of sound. This demonstrates advanced sensor reading, timing measurements, and distance calculations.

**Difficulty Level:** Beginner  
**Learning Objectives:**
- Understanding ultrasonic sensors (HC-SR04)
- Using `pulseIn()` function for timing
- Measuring distance with sound waves
- Calculating distance from time measurements
- Trigger and echo signal handling
- Real-world distance measurement

## 🔧 Components Required

- **Arduino Board** (Uno, Nano, Mega, or compatible)
- **USB Cable** (to connect Arduino to computer)
- **HC-SR04 Ultrasonic Sensor**
- **Breadboard** (for easy connections)
- **Jumper Wires** (for connections)
- **Resistors** (optional: 1kΩ and 2kΩ for voltage divider if needed)

## 🔌 Circuit Connections

**Circuit Connections:**

```
HC-SR04 Ultrasonic Sensor:
  VCC → 5V
  Trig → Pin 9
  Echo → Pin 10
  GND → GND
```

**Visual Connection Guide:**
```
Arduino Board:
    5V ───────────────────────────[HC-SR04 VCC]
    Pin 9 ────────────────────────[HC-SR04 Trig]
    Pin 10 ───────────────────────[HC-SR04 Echo]
    GND ──────────────────────────[HC-SR04 GND]
```

**Important Notes:**
- **HC-SR04 has 4 pins:** VCC, Trig, Echo, GND
- **VCC** connects to 5V (power)
- **Trig** (Trigger) connects to digital pin (output)
- **Echo** connects to digital pin (input)
- **GND** connects to GND (ground)
- Some Arduino boards may need voltage divider for Echo (5V to 3.3V)
- Measurement range: 2cm to 400cm
- Accuracy: ±3mm

### HC-SR04 Pin Configuration

**HC-SR04 Ultrasonic Sensor:**
- **VCC** - Power supply (5V)
- **Trig** - Trigger pin (input, sends ultrasonic pulse)
- **Echo** - Echo pin (output, receives reflected pulse)
- **GND** - Ground

**How It Works:**
1. Arduino sends trigger pulse (10µs HIGH) to Trig pin
2. Sensor sends ultrasonic sound wave (40kHz)
3. Sound bounces off object and returns
4. Sensor sends echo pulse (duration = time for round trip)
5. Arduino measures echo pulse duration
6. Calculate distance: distance = (duration × speed of sound) / 2

## 💻 Code Explanation

### Key Concepts

**Ultrasonic Measurement:**
- Sensor sends ultrasonic sound waves (40kHz, inaudible to humans)
- Sound travels at 343 m/s (speed of sound)
- Time for round trip = 2 × distance / speed
- Distance = (time × speed) / 2

**Trigger and Echo:**
- **Trigger (Trig):** Arduino sends 10µs pulse to start measurement
- **Echo:** Sensor returns pulse with duration = round trip time
- `pulseIn()` measures how long echo pin stays HIGH

**Distance Calculation:**
- Speed of sound: 343 m/s = 0.0343 cm/µs
- Formula: `distance = (duration × 0.0343) / 2`
- Simplified: `distance = duration / 58.2` (approximately)

### Key Functions

**`digitalWrite(TRIG_PIN, HIGH/LOW)`**
- Controls trigger pin
- Sends 10µs HIGH pulse to start measurement
- Must be cleared (LOW) before each measurement

**`pulseIn(ECHO_PIN, HIGH)`**
- Measures duration of pulse on echo pin
- Waits for pin to go HIGH, then measures time until LOW
- Returns duration in microseconds
- Times out after 1 second if no pulse

**Distance Calculation:**
```cpp
distance = duration * 0.0343 / 2.0;
```
- Converts time to distance
- Divides by 2 (round trip, we want one-way distance)
- Result in centimeters

### Program Flow

1. **`setup()`** - Runs once when Arduino starts:
   - Configures Trig pin as output
   - Configures Echo pin as input
   - Initializes serial communication

2. **`loop()`** - Runs continuously:
   - Clear trigger pin (set LOW)
   - Send 10µs trigger pulse (HIGH)
   - Clear trigger pin (set LOW)
   - Measure echo pulse duration
   - Calculate distance from duration
   - Print distance to Serial Monitor
   - Wait 500ms
   - Repeat

**Measurement Process:**
```
Send Trigger Pulse (10µs)
    ↓
Sensor Sends Ultrasonic Wave
    ↓
Wave Bounces Off Object
    ↓
Sensor Receives Echo
    ↓
Echo Pin Goes HIGH
    ↓
Measure Duration (pulseIn)
    ↓
Calculate Distance
    ↓
Display Result
```

## 🚀 Usage Instructions

### Step 1: Build the Circuit

1. **Connect HC-SR04 Sensor:**
   - VCC → 5V
   - Trig → Pin 9
   - Echo → Pin 10
   - GND → GND

**Important:** 
- Check sensor pin labels (VCC, Trig, Echo, GND)
- Make sure connections are secure
- Sensor has 4 pins - all must be connected

### Step 2: Open and Upload Code

1. Open Arduino IDE
2. Open the file `ultrasonic_sensor.ino` from this folder
3. Connect your Arduino board
4. Select the correct board and port in Arduino IDE
5. Click **Upload** button

### Step 3: Measure Distance

1. After uploading, open Serial Monitor (9600 baud)
2. Place an object in front of the sensor
3. Watch distance readings in Serial Monitor
4. Move object closer/farther - distance should change
5. Readings update every 500ms

## 🔍 Expected Behavior

- Serial Monitor shows distance readings every 500ms
- Display format: "Duration: XXX microseconds | Distance: XX.XX cm"
- Distance should match actual distance to object
- Moving object closer decreases distance
- Moving object farther increases distance
- No object = very large distance or timeout
- Measurement range: 2cm to 400cm

## 🛠️ Troubleshooting

### No Distance Reading

**Problem:** Always shows 0 or very large distance
- **Solution:** Check all 4 sensor connections (VCC, Trig, Echo, GND)
- **Solution:** Verify Trig pin connects to pin 9 (check `TRIG_PIN` constant)
- **Solution:** Verify Echo pin connects to pin 10 (check `ECHO_PIN` constant)
- **Solution:** Make sure object is within range (2-400cm)
- **Solution:** Check sensor orientation (transducers face forward)

### Distance is Always the Same

**Problem:** Distance doesn't change when moving object
- **Solution:** Check Echo pin connection
- **Solution:** Verify `pulseIn()` is working (check Serial Monitor for duration values)
- **Solution:** Object may be too close or too far (out of range)
- **Solution:** Sensor may be damaged - try different sensor

### Distance is Inaccurate

**Problem:** Distance readings don't match actual distance
- **Solution:** This is normal - accuracy is ±3mm
- **Solution:** Check calculation formula is correct
- **Solution:** Speed of sound varies with temperature/humidity
- **Solution:** Object surface affects reflection (soft surfaces absorb sound)

### Sensor Doesn't Respond

**Problem:** No readings at all
- **Solution:** Check VCC connection (must be 5V)
- **Solution:** Verify GND connection
- **Solution:** Check Trig and Echo pin connections
- **Solution:** Test sensor by connecting directly to 5V and GND
- **Solution:** Sensor may need voltage divider for Echo (if using 3.3V board)

### Readings Jump Around

**Problem:** Distance values are unstable
- **Solution:** This is normal - small variations expected
- **Solution:** Add averaging (read multiple times and average)
- **Solution:** Increase delay between measurements
- **Solution:** Check for loose connections
- **Solution:** Object may be moving or vibrating

## 🎓 Learning Concepts

This project teaches:
- **Ultrasonic Sensors:** How HC-SR04 works
- **Timing Measurements:** Using `pulseIn()` for precise timing
- **Distance Calculation:** Converting time to distance
- **Trigger/Echo Signals:** Understanding sensor communication
- **Speed of Sound:** Physics of sound wave propagation
- **Real-World Sensing:** Practical distance measurement

## 🔄 Next Steps

After mastering this project, try:
- **Distance Display:** Show distance on LCD display
- **Obstacle Detection:** Trigger LED/buzzer when object is too close
- **Distance Alarm:** Alert when object enters/leaves range
- **Multiple Sensors:** Use multiple sensors for 360° detection
- **Servo Scanning:** Use servo to scan area with sensor
- **Robot Navigation:** Use sensor for robot obstacle avoidance
- **Parking Assistant:** Create parking distance indicator

## 📝 Notes

- This project uses **Pin 9** for Trig and **Pin 10** for Echo
- Measurement range: 2cm to 400cm (4 meters)
- Accuracy: ±3mm
- Update rate: Every 500ms (adjustable)
- Speed of sound: 343 m/s (varies with temperature)
- You can change pins by modifying `TRIG_PIN` and `ECHO_PIN` constants
- Some boards may need voltage divider for Echo pin (5V to 3.3V)

## 📏 Distance Reference

| Duration (µs) | Distance (cm) |
|---------------|---------------|
| 58 | 1 cm |
| 290 | 5 cm |
| 580 | 10 cm |
| 2900 | 50 cm |
| 5800 | 100 cm |

## 🔬 Experiment Ideas

1. **Add Averaging:**
   - Read sensor multiple times and average
   - Reduces noise and improves accuracy

2. **Distance Alarms:**
   - Set distance thresholds
   - Trigger LED or buzzer when exceeded

3. **Distance Display:**
   - Show distance on LCD
   - Update in real-time

4. **Multiple Sensors:**
   - Use multiple HC-SR04 sensors
   - Compare distances from different angles

5. **Servo Scanning:**
   - Mount sensor on servo
   - Scan area and map distances

6. **Temperature Compensation:**
   - Adjust speed of sound based on temperature
   - More accurate distance measurements

## 📚 Related Resources

- [Arduino pulseIn()](https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/)
- [HC-SR04 Datasheet](https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf)
- [Ultrasonic Sensor Tutorial](https://www.arduino.cc/en/Tutorial/Ping)
- [Arduino Digital Pins](https://www.arduino.cc/reference/en/language/functions/digital-io/)

---

**Author:** XergioAleX  
**Date:** 2025  
**Version:** 1.0  
**Project:** Ultrasonic Sensor - HC-SR04

