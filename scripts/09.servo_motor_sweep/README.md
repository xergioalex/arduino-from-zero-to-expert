# Servo Motor Sweep

Create an automatic back-and-forth sweeping motion with a servo motor. The servo continuously moves from 0° to 180° and back, creating a smooth scanning motion. This project demonstrates automatic control and loop-based movement patterns.

## 📋 Project Description

This project creates an automatic sweeping motion where the servo motor continuously moves back and forth between 0° and 180°. The servo moves smoothly in one direction, reaches the limit, then reverses direction. This demonstrates automatic control patterns and using loops to create continuous motion.

**Difficulty Level:** Beginner  
**Learning Objectives:**
- Automatic servo control without user input
- Creating continuous motion patterns
- Using for loops for sequential movement
- Controlling movement speed with delays
- Understanding back-and-forth motion algorithms
- Smooth servo positioning

## 🔧 Components Required

- **Arduino Board** (Uno, Nano, Mega, or compatible)
- **USB Cable** (to connect Arduino to computer)
- **Servo Motor** (SG90 or compatible, 5V servo)
- **Breadboard** (for easy connections)
- **Jumper Wires** (for connections)
- **External Power Supply** (optional, for larger servos)

## 🔌 Circuit Connections

**Circuit Connections:**

```
Servo Motor Circuit:
  Servo Red Wire (VCC) → 5V (or external 5V power supply)
  Servo Black/Brown Wire (GND) → GND
  Servo Orange/Yellow Wire (Signal) → Pin 9 (PWM)
```

**Visual Connection Guide:**
```
Arduino Board:
    Pin 9 (~) ────────────────────────[Servo Signal (Orange/Yellow)]
    5V ───────────────────────────────[Servo VCC (Red)]
    GND ──────────────────────────────[Servo GND (Black/Brown)]
```

**Important Notes:**
- **Servo has 3 wires:** Red (VCC/5V), Black/Brown (GND), Orange/Yellow (Signal)
- **Signal wire** connects to PWM-capable pin (marked with ~ on Arduino Uno)
- **No sensors or buttons needed** - motion is automatic
- For larger servos, use external 5V power supply

## 💻 Code Explanation

### Key Concepts

**Automatic Sweep Motion:**
- Servo moves automatically without user input
- Continuous back-and-forth motion
- Two for loops create the sweep pattern
- First loop: 0° to 180° (forward)
- Second loop: 180° to 0° (backward)

**Loop-Based Movement:**
- `for` loops control sequential angle changes
- Each iteration moves servo by 1 degree
- Delay between movements controls speed
- Smooth, continuous motion

**Movement Speed:**
- Controlled by `DELAY_MS` constant (15ms default)
- Lower delay = faster movement
- Higher delay = slower movement
- Adjustable for different speeds

### Key Functions

**`myServo.write(servoAngle)`**
- Sets servo position to specified angle
- Called in each loop iteration
- Angle range: 0-180 degrees

**For Loop Pattern:**
```cpp
for (servoAngle = MIN_ANGLE; servoAngle <= MAX_ANGLE; servoAngle += angleStep)
```
- Moves servo from minimum to maximum angle
- Increments by `angleStep` (1 degree) each iteration
- Repeats until reaching maximum angle

**Reverse Loop:**
```cpp
for (servoAngle = MAX_ANGLE; servoAngle >= MIN_ANGLE; servoAngle -= angleStep)
```
- Moves servo from maximum back to minimum
- Decrements by `angleStep` each iteration
- Creates return motion

### Program Flow

1. **`setup()`** - Runs once when Arduino starts:
   - Attaches servo to pin 9
   - Sets initial position to 0°
   - Initializes serial communication

2. **`loop()`** - Runs continuously:
   - **Forward Sweep:** Loop from 0° to 180° (incrementing)
     - Set servo position
     - Print angle to Serial Monitor
     - Delay for smooth movement
   - **Reverse Sweep:** Loop from 180° to 0° (decrementing)
     - Set servo position
     - Print angle to Serial Monitor
     - Delay for smooth movement
   - Repeat forever

**Motion Pattern:**
```
0° → 1° → 2° → ... → 179° → 180° → 179° → ... → 2° → 1° → 0° → (repeat)
```

## 🚀 Usage Instructions

### Step 1: Build the Circuit

1. **Connect Servo Motor:**
   - Red wire (VCC) → 5V
   - Black/Brown wire (GND) → GND
   - Orange/Yellow wire (Signal) → Pin 9

**Important:** 
- Only servo motor needed - no buttons or sensors
- For larger servos, use external 5V power supply

### Step 2: Open and Upload Code

1. Open Arduino IDE
2. Open the file `servo_motor_sweep.ino` from this folder
3. Connect your Arduino board
4. Select the correct board and port in Arduino IDE
5. Click **Upload** button

### Step 3: Observe the Motion

1. After uploading, the servo should start sweeping automatically
2. Watch the servo move from 0° to 180° smoothly
3. Then watch it move back from 180° to 0°
4. This cycle repeats continuously
5. Open Serial Monitor to see angle values

## 🔍 Expected Behavior

- Servo starts at 0° and moves smoothly to 180°
- Then reverses and moves smoothly back to 0°
- Motion is continuous and automatic
- No user input required
- Serial Monitor shows angle values (0-180)
- Cycle repeats indefinitely
- Smooth, even movement speed

## 🛠️ Troubleshooting

### Servo Doesn't Move

**Problem:** Servo doesn't sweep
- **Solution:** Check servo connections - Red to 5V, Black/Brown to GND, Orange/Yellow to pin 9
- **Solution:** Verify pin 9 is being used (check `SERVO_PIN` constant)
- **Solution:** Make sure servo is properly attached: `myServo.attach(SERVO_PIN)`
- **Solution:** Test servo with simple code: `myServo.write(90);` in setup()

### Servo Moves Too Fast

**Problem:** Servo sweeps too quickly
- **Solution:** Increase `DELAY_MS` value (try 30, 50, or 100)
- **Solution:** Higher delay = slower, smoother movement

### Servo Moves Too Slow

**Problem:** Servo sweeps too slowly
- **Solution:** Decrease `DELAY_MS` value (try 10 or 5)
- **Solution:** Lower delay = faster movement (but may be less smooth)

### Servo Jitters or Moves Erratically

**Problem:** Servo movement is not smooth
- **Solution:** Add external 5V power supply - Arduino 5V may not provide enough current
- **Solution:** Connect external power GND to Arduino GND (important!)
- **Solution:** Check for loose connections
- **Solution:** Increase delay slightly for smoother motion

### Servo Doesn't Reach Full Range

**Problem:** Servo doesn't reach 0° or 180°
- **Solution:** This is normal - servos have mechanical limits
- **Solution:** Adjust range: `MIN_ANGLE = 10, MAX_ANGLE = 170` to avoid extremes
- **Solution:** Some servos have different ranges - adjust accordingly

### Serial Monitor Shows Nothing

**Problem:** No values in Serial Monitor
- **Solution:** Make sure Serial Monitor is set to 9600 baud
- **Solution:** Click Serial Monitor icon after uploading code
- **Solution:** Verify serial communication is initialized in `setup()`

## 🎓 Learning Concepts

This project teaches:
- **Automatic Control:** Creating motion without user input
- **Loop Patterns:** Using for loops for sequential movement
- **Continuous Motion:** Creating repeating patterns
- **Speed Control:** Adjusting movement speed with delays
- **Back-and-Forth Motion:** Implementing bidirectional movement
- **Sequential Positioning:** Moving through positions in order

## 🔄 Next Steps

After mastering this project, try:
- **Variable Speed:** Change speed during sweep (fast-slow-fast)
- **Limited Range:** Sweep only part of range (e.g., 30° to 150°)
- **Multiple Servos:** Synchronize multiple servos sweeping together
- **Pattern Variations:** Create different sweep patterns (fast forward, slow back)
- **Sensor Integration:** Stop sweep when sensor detects something
- **Button Control:** Add button to start/stop sweep

## 📝 Notes

- This project uses **Pin 9** for servo control (must be PWM-capable)
- Servo sweeps automatically - no buttons or sensors needed
- Default delay: 15ms between movements (adjustable)
- Sweep range: 0° to 180° (adjustable)
- Motion is continuous and automatic
- You can change pins by modifying `SERVO_PIN` constant
- Adjust `DELAY_MS` to change sweep speed
- Adjust `MIN_ANGLE` and `MAX_ANGLE` to change sweep range

## 🔬 Experiment Ideas

1. **Change Sweep Speed:**
   - Modify `DELAY_MS` (try 5, 10, 30, 50, 100)
   - Observe how speed affects smoothness

2. **Limited Range:**
   - Change `MIN_ANGLE` and `MAX_ANGLE`
   - Try sweeping only 45° to 135°

3. **Variable Speed:**
   - Fast forward, slow backward
   - Or slow at ends, fast in middle

4. **Multiple Servos:**
   - Add more servos on different pins
   - Synchronize their sweeping motion

5. **Pattern Variations:**
   - Sweep to center, pause, then continue
   - Create figure-8 patterns with two servos

6. **Add Control:**
   - Add button to start/stop sweep
   - Add potentiometer to control speed

## 📚 Related Resources

- [Arduino Servo Library](https://www.arduino.cc/reference/en/libraries/servo/)
- [Arduino Servo Sweep Tutorial](https://www.arduino.cc/en/Tutorial/Sweep)
- [Arduino For Loop](https://www.arduino.cc/reference/en/language/structure/control-structure/for/)
- [Servo Motor Basics](https://www.arduino.cc/en/Tutorial/Knob)

---

**Author:** XergioAleX  
**Date:** 2025  
**Version:** 1.0  
**Project:** Servo Motor Sweep

