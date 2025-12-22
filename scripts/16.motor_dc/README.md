# Motor DC Control with L298N

Control a DC motor's speed and direction using an L298N motor driver module. This project demonstrates motor control, PWM speed control, direction control, and using motor driver modules for robotics applications.

## 📋 Project Description

This project controls a DC motor using an L298N motor driver module. The motor will rotate forward, stop, rotate in reverse, and demonstrate speed control using PWM. This demonstrates motor control fundamentals, PWM for speed, direction control, and motor driver modules.

**Difficulty Level:** Beginner to Intermediate  
**Learning Objectives:**
- Understanding DC motors and motor control
- Using L298N motor driver module
- PWM speed control for motors
- Direction control (forward/reverse)
- Motor driver modules and their purpose
- Robotics fundamentals

## 🔧 Components Required

- **Arduino Board** (Uno, Nano, Mega, or compatible)
- **USB Cable** (to connect Arduino to computer)
- **DC Motor** (small DC motor, 5-12V recommended)
- **L298N Motor Driver Module**
- **Breadboard** (for easy connections)
- **Jumper Wires** (for connections)
- **Power Supply** (optional: external 5-12V power supply for motor, or use Arduino 5V for small motors)

**Important:** For small motors (like small hobby motors), you can power them from Arduino's 5V. For larger motors, use an external power supply.

## 🔌 Circuit Connections

**Circuit Connections:**

```
L298N Motor Driver Module:
  VCC → 5V (Arduino) or External 5-12V power supply
  GND → GND (Arduino and external power supply if used)
  ENA → Pin 9 (Arduino, PWM pin)
  IN1 → Pin 8 (Arduino)
  IN2 → Pin 7 (Arduino)
  OUT1 → Motor terminal 1
  OUT2 → Motor terminal 2

External Power Supply (if using):
  Positive → L298N VCC
  Negative → L298N GND (must be connected to Arduino GND too!)
```

**Visual Connection Guide:**
```
Arduino Board:
    Pin 9 (PWM) ──────────────────[L298N ENA]
    Pin 8 ─────────────────────────[L298N IN1]
    Pin 7 ─────────────────────────[L298N IN2]
    5V ────────────────────────────[L298N VCC] (for small motors)
    GND ───────────────────────────[L298N GND]

L298N Module:
    OUT1 ──────────────────────────[Motor Terminal 1]
    OUT2 ──────────────────────────[Motor Terminal 2]
```

**Important Notes:**
- **ENA** controls speed (PWM pin required)
- **IN1 and IN2** control direction
- **OUT1 and OUT2** connect to motor terminals
- **Power:** Small motors can use Arduino 5V, larger motors need external supply
- **GND Connection:** If using external power, connect both GNDs together (common ground)

### L298N Motor Driver Pin Configuration

**L298N Module Pins:**
- **VCC** - Power supply (5V from Arduino or external 5-12V)
- **GND** - Ground (must connect to Arduino GND)
- **ENA** - Enable pin A (PWM for speed control)
- **IN1** - Input 1 (direction control)
- **IN2** - Input 2 (direction control)
- **OUT1** - Motor output 1
- **OUT2** - Motor output 2

**Direction Control:**
```
IN1 = HIGH, IN2 = LOW  → Motor rotates FORWARD
IN1 = LOW,  IN2 = HIGH → Motor rotates REVERSE
IN1 = LOW,  IN2 = LOW  → Motor STOPS (brake)
IN1 = HIGH, IN2 = HIGH → Motor STOPS (brake)
```

**Speed Control:**
- **ENA** uses PWM (0-255)
- 0 = Stop
- 255 = Maximum speed
- Values in between = Variable speed

## 💻 Code Explanation

### Key Concepts

**DC Motor Control:**
- DC motors need high current (more than Arduino can provide)
- Motor driver modules (like L298N) provide current amplification
- PWM controls speed (duty cycle = speed)
- Direction controlled by switching motor terminals

**L298N Motor Driver:**
- **H-Bridge** circuit inside (allows forward and reverse)
- Can control 2 motors independently
- Provides current amplification
- Protects Arduino from motor current

**PWM Speed Control:**
- `analogWrite()` sends PWM signal to ENA pin
- Higher value = faster speed
- Lower value = slower speed
- 0 = stop

### Key Functions

**`analogWrite(ENA_PIN, speed)`**
- Controls motor speed using PWM
- Speed: 0-255 (0 = stop, 255 = max speed)
- Must use PWM-capable pin (marked with ~ on Arduino)

**Direction Control:**
```cpp
// Forward
digitalWrite(IN1_PIN, HIGH);
digitalWrite(IN2_PIN, LOW);

// Reverse
digitalWrite(IN1_PIN, LOW);
digitalWrite(IN2_PIN, HIGH);

// Stop
digitalWrite(IN1_PIN, LOW);
digitalWrite(IN2_PIN, LOW);
```

**Speed Ramp:**
- Gradually increase/decrease speed
- Creates smooth acceleration/deceleration
- Uses `for` loop with PWM values

### Program Flow

1. **`setup()`** - Runs once:
   - Configure pins as outputs
   - Stop motor initially
   - Wait 1 second

2. **`loop()`** - Runs continuously:
   - Rotate forward at medium speed (3 seconds)
   - Stop (1 second)
   - Rotate reverse at medium speed (3 seconds)
   - Stop (1 second)
   - Speed ramp up from 0 to 255 (forward)
   - Speed ramp down from 255 to 0
   - Stop (2 seconds)
   - Repeat

## 🚀 Usage Instructions

### Step 1: Build the Circuit

1. **Connect L298N to Arduino:**
   - ENA → Pin 9 (PWM pin)
   - IN1 → Pin 8
   - IN2 → Pin 7
   - VCC → 5V (for small motors) or external power supply
   - GND → GND

2. **Connect Motor to L298N:**
   - Motor terminal 1 → OUT1
   - Motor terminal 2 → OUT2

3. **External Power (if needed):**
   - Connect external power supply (5-12V) to L298N VCC
   - **Important:** Connect external power GND to Arduino GND (common ground!)

**Important:** 
- For small hobby motors, Arduino 5V is usually enough
- For larger motors, use external power supply
- Always connect GNDs together (common ground)
- Check motor voltage rating before connecting

### Step 2: Open and Upload Code

1. Open Arduino IDE
2. Open the file `motor_dc.ino` from this folder
3. Connect your Arduino board
4. Select the correct board and port in Arduino IDE
5. Click **Upload** button

### Step 3: Observe Motor Behavior

1. After uploading, motor should:
   - Rotate forward for 3 seconds
   - Stop for 1 second
   - Rotate reverse for 3 seconds
   - Stop for 1 second
   - Speed ramp up (gradually increase speed)
   - Speed ramp down (gradually decrease speed)
   - Stop for 2 seconds
   - Repeat cycle

2. Open Serial Monitor (9600 baud) to see status messages

## 🔍 Expected Behavior

- Motor rotates forward at medium speed (200/255)
- Motor stops completely
- Motor rotates in reverse at medium speed
- Motor stops completely
- Motor gradually speeds up from 0 to maximum
- Motor gradually slows down from maximum to 0
- Motor stops
- Cycle repeats continuously
- Serial Monitor shows motor status and speed

## 🛠️ Troubleshooting

### Motor Doesn't Move

**Problem:** Motor doesn't rotate at all
- **Solution:** Check all connections (ENA, IN1, IN2, VCC, GND)
- **Solution:** Verify motor is connected to OUT1 and OUT2
- **Solution:** Check if motor works by connecting directly to power supply
- **Solution:** Verify ENA pin is connected to PWM pin (marked with ~)
- **Solution:** Check if external power supply is needed (motor may need more current)

### Motor Only Moves in One Direction

**Problem:** Motor only rotates forward, not reverse
- **Solution:** Check IN1 and IN2 connections
- **Solution:** Verify both IN1 and IN2 are connected correctly
- **Solution:** Try swapping IN1 and IN2 connections
- **Solution:** Check code - make sure both directions are programmed

### Motor Speed Doesn't Change

**Problem:** Motor runs at one speed only
- **Solution:** Verify ENA pin is connected to PWM pin (Pin 9, marked with ~)
- **Solution:** Check if `analogWrite()` is being used (not `digitalWrite()`)
- **Solution:** Verify PWM pin is correct in code

### Motor Runs Too Fast or Too Slow

**Problem:** Motor speed is not appropriate
- **Solution:** Adjust `motorSpeed` variable in code (0-255)
- **Solution:** Lower values = slower speed
- **Solution:** Higher values = faster speed
- **Solution:** Try values: 100 (slow), 150 (medium), 200 (fast), 255 (max)

### Motor Stops Unexpectedly

**Problem:** Motor stops or behaves erratically
- **Solution:** Check power supply - motor may need more current
- **Solution:** Use external power supply if motor is large
- **Solution:** Check all connections are secure
- **Solution:** Verify GND connections (common ground required)

### L298N Gets Hot

**Problem:** L298N module becomes hot
- **Solution:** This is normal - L298N can get warm during operation
- **Solution:** Ensure proper heat dissipation (don't cover module)
- **Solution:** Reduce motor speed if too hot
- **Solution:** Check motor current rating vs L298N capacity

## 🎓 Learning Concepts

This project teaches:
- **DC Motors:** How DC motors work and need to be controlled
- **Motor Drivers:** Why motor driver modules are needed
- **PWM Control:** Using PWM for variable speed control
- **Direction Control:** Switching motor direction
- **H-Bridge:** Understanding H-bridge circuits (inside L298N)
- **Power Management:** Handling motor power requirements
- **Robotics Basics:** Fundamental motor control for robotics

## 🔄 Next Steps

After mastering this project, try:
- **Two Motor Control:** Control two motors independently
- **Motor with Potentiometer:** Control speed with potentiometer
- **Motor with Buttons:** Control direction with buttons
- **Robot Car:** Build a simple robot car with two motors
- **Motor Encoder:** Add encoder for position feedback
- **Motor with Sensor:** Control motor based on sensor input

## 📝 Notes

- This project uses **Pins 7, 8, and 9** for motor control
- **ENA** must be a PWM pin (marked with ~ on Arduino Uno: 3, 5, 6, 9, 10, 11)
- **Small motors** can use Arduino 5V power
- **Larger motors** need external power supply (5-12V)
- **Common ground** is essential when using external power
- Motor direction can be reversed by swapping OUT1 and OUT2
- L298N can control 2 motors (this project uses Motor A)

## ⚡ Power Supply Guide

**For Small Motors (hobby motors, small DC motors):**
- Use Arduino 5V pin
- Usually sufficient for motors under 500mA

**For Larger Motors:**
- Use external power supply (5-12V, depending on motor)
- Connect positive to L298N VCC
- Connect negative to L298N GND
- **Critical:** Connect external power GND to Arduino GND (common ground!)

**Power Supply Ratings:**
- Voltage: Match motor voltage (usually 5V, 6V, 9V, or 12V)
- Current: Should provide at least motor's rated current
- Example: 12V 1A power supply for 12V motor

## 🔬 Experiment Ideas

1. **Variable Speed Control:**
   - Add potentiometer to control speed
   - Read analog value and map to PWM

2. **Button Control:**
   - Add buttons for forward/reverse/stop
   - Control motor direction with buttons

3. **Sensor-Based Control:**
   - Control motor based on distance sensor
   - Stop motor when object detected

4. **Two Motor Control:**
   - Add second motor
   - Control both motors independently
   - Create differential drive robot

5. **Speed Profiles:**
   - Create acceleration/deceleration curves
   - Smooth start and stop

## 📚 Related Resources

- [Arduino PWM](https://www.arduino.cc/en/Tutorial/PWM)
- [L298N Datasheet](https://www.st.com/resource/en/datasheet/l298.pdf)
- [DC Motor Control Tutorial](https://www.arduino.cc/en/Tutorial/MotorControl)
- [H-Bridge Explanation](https://en.wikipedia.org/wiki/H-bridge)

---

**Author:** XergioAleX  
**Date:** 2025  
**Version:** 1.0  
**Project:** Motor DC Control with L298N

