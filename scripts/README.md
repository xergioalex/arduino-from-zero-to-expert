# Arduino Learning Scripts Index

Welcome to the Arduino Learning Scripts collection! This directory contains progressive Arduino projects designed to take you from zero to expert level. Each script is a complete, self-contained project with documentation, circuit diagrams, and code examples.

## 📚 About This Collection

All scripts are organized in numerical order (01, 02, 03...) representing a structured learning path. Each script builds upon concepts learned in previous scripts, creating a comprehensive learning experience.

**What Each Script Includes:**
- ✅ Complete source code with detailed comments
- ✅ Circuit diagrams (Tinkercad simulation + real photos)
- ✅ Component list and connection guide
- ✅ Step-by-step instructions
- ✅ Code explanation
- ✅ Troubleshooting guide
- ✅ Learning objectives and concepts

## 🎯 Learning Path

Follow the scripts in numerical order to build your Arduino skills progressively:

1. **Scripts 01-02:** Digital Output Basics
2. **Script 03:** Digital Input Introduction
3. **Script 04:** Analog Output (PWM)
4. **Script 05:** Analog Input
5. **Script 06:** Multiple Outputs (RGB LED)
6. **Script 07:** Actuators and Libraries (Servo Motor with Potentiometer)
7. **Script 08:** Digital Control of Actuators (Servo Motor with Buttons)
8. **Script 09:** Automatic Motion Patterns (Servo Motor Sweep)
9. **Script 10:** Environmental Sensors (LDR Light Sensor)
10. **Script 11:** Sound Output (Buzzer - Basic and Melody examples)
11. **Script 12:** Interactive Sound (Buzzer Button)
12. **Script 13:** Temperature Sensing (LM35 Sensor)
13. **Script 14:** Distance Measurement (Ultrasonic Sensor)
14. **Script 15:** Display Output (LCD 16x2 with I2C)
15. **More coming soon...**

## 📋 Complete Scripts Index

### Beginner Level

| # | Script | Description | Key Concepts | Difficulty |
|---|--------|-------------|--------------|------------|
| **01** | [LED ON](01.led/) | Turn on an LED and keep it on | Digital output, `pinMode()`, `digitalWrite()` | ⭐ Beginner |
| **02** | [LED Blink](02.led_blink/) | Blink an LED on and off | Digital output, `delay()`, loops | ⭐ Beginner |
| **03** | [LED Button](03.led_button/) | Control LED with a push button | Digital input, `digitalRead()`, edge detection, pull-up resistors | ⭐ Beginner |
| **04** | [LED Fade](04.led_fade/) | Smooth fade in/out effect using PWM | PWM, `analogWrite()`, analog output, brightness control | ⭐ Beginner |
| **05** | [LED Potentiometer](05.led_potentiometer/) | Control LED brightness with potentiometer | Analog input, `analogRead()`, `map()`, voltage divider | ⭐ Beginner |
| **06** | [RGB LED](06.rgb_led/) | Control RGB LED to display different colors | RGB color model, multiple PWM outputs, color mixing, custom functions | ⭐ Beginner |
| **07** | [Servo Motor Potentiometer](07.servo_motor_potentiometer/) | Control servo position with potentiometer | Servo library, actuators, `servo.write()`, position control, libraries | ⭐ Beginner |
| **08** | [Servo Motor Button](08.servo_motor_button/) | Control servo position with buttons | Digital input control, edge detection, incremental positioning, button debouncing | ⭐ Beginner |
| **09** | [Servo Motor Sweep](09.servo_motor_sweep/) | Automatic back-and-forth servo motion | Automatic control, for loops, continuous motion patterns, speed control | ⭐ Beginner |
| **10** | [LDR Light Sensor](10.ldr_led/) | Automatic LED control based on light level | LDR sensors, analog sensors, threshold logic, automatic control, voltage dividers | ⭐ Beginner |
| **11** | [Buzzer](11.buzzer/) | Generate sounds and melodies (2 code examples) | Sound generation, `tone()`, `noTone()`, frequencies, arrays, loops, melody creation | ⭐ Beginner |
| **12** | [Buzzer Button](12.buzzer_button/) | Control sounds with buttons | Interactive control, multiple buttons, edge detection, button-triggered sounds | ⭐ Beginner |
| **13** | [Temperature Sensor](13.temperature_sensor/) | Read temperature from LM35 sensor | Temperature sensors, analog reading, voltage conversion, real-world measurements | ⭐ Beginner |
| **14** | [Ultrasonic Sensor](14.ultrasonic_sensor/) | Measure distance with HC-SR04 | Ultrasonic sensors, `pulseIn()`, distance calculation, timing measurements | ⭐ Beginner |
| **15** | [LCD Display](15.lcd_display/) | Display text on 16x2 LCD using I2C | LCD displays, I2C communication, libraries, text formatting, data display | ⭐ Beginner |

## 📖 Detailed Script Information

### 01. LED ON
**Location:** [`01.led/`](01.led/)  
**Description:** The perfect first Arduino project. Learn to turn on an LED and keep it on.  
**Concepts:** Digital output, `pinMode()`, `digitalWrite()`, `setup()`, `loop()`  
**Components:** Arduino, LED, Resistor (330Ω), Breadboard, Jumper wires  
**Tinkercad:** Included in project README

---

### 02. LED Blink
**Location:** [`02.led_blink/`](02.led_blink/)  
**Description:** Create a blinking LED effect. Learn about timing and loops.  
**Concepts:** Digital output, `delay()`, loops, timing control  
**Components:** Arduino, LED, Resistor (330Ω), Breadboard, Jumper wires  
**Tinkercad:** Included in project README

---

### 03. LED Button
**Location:** [`03.led_button/`](03.led_button/)  
**Description:** Control an LED with a push button. Toggle LED on/off with button presses.  
**Concepts:** Digital input, `digitalRead()`, edge detection, pull-up resistors, button debouncing  
**Components:** Arduino, LED, Resistor (330Ω), Push button, Breadboard, Jumper wires  
**Tinkercad:** Included in project README

---

### 04. LED Fade
**Location:** [`04.led_fade/`](04.led_fade/)  
**Description:** Create smooth fade in/out effect using PWM. Control LED brightness smoothly.  
**Concepts:** PWM (Pulse Width Modulation), `analogWrite()`, analog output, brightness control  
**Components:** Arduino, LED, Resistor (330Ω), Breadboard, Jumper wires  
**Tinkercad:** Included in project README

---

### 05. LED Potentiometer
**Location:** [`05.led_potentiometer/`](05.led_potentiometer/)  
**Description:** Control LED brightness with a potentiometer. Real-time brightness adjustment.  
**Concepts:** Analog input, `analogRead()`, `map()`, voltage divider, potentiometer  
**Components:** Arduino, LED, Resistor (330Ω), Potentiometer (10kΩ), Breadboard, Jumper wires  
**Tinkercad:** Included in project README

---

### 06. RGB LED
**Location:** [`06.rgb_led/`](06.rgb_led/)  
**Description:** Control an RGB LED to display different colors. Learn color mixing and multiple PWM outputs.  
**Concepts:** RGB color model, multiple PWM outputs, color mixing, custom functions, arrays  
**Components:** Arduino, RGB LED, Resistors (3x 330Ω), Breadboard, Jumper wires  
**Tinkercad:** Included in project README

---

### 07. Servo Motor Potentiometer
**Location:** [`07.servo_motor_potentiometer/`](07.servo_motor_potentiometer/)  
**Description:** Control a servo motor position using a potentiometer. Learn about actuators and Arduino libraries.  
**Concepts:** Servo library, actuators, `servo.write()`, position control, libraries, analog to actuator  
**Components:** Arduino, Servo Motor (SG90), Potentiometer (10kΩ), Breadboard, Jumper wires  
**Tinkercad:** Included in project README

---

### 08. Servo Motor Button
**Location:** [`08.servo_motor_button/`](08.servo_motor_button/)  
**Description:** Control a servo motor position using push buttons. Left button moves counterclockwise, right button moves clockwise.  
**Concepts:** Digital input control, edge detection, incremental positioning, button debouncing, angle limiting  
**Components:** Arduino, Servo Motor (SG90), Push Buttons (2x), Breadboard, Jumper wires  
**Tinkercad:** Included in project README

---

### 09. Servo Motor Sweep
**Location:** [`09.servo_motor_sweep/`](09.servo_motor_sweep/)  
**Description:** Create automatic back-and-forth sweeping motion with a servo motor. Continuous motion from 0° to 180° and back.  
**Concepts:** Automatic control, for loops, continuous motion patterns, speed control, sequential positioning  
**Components:** Arduino, Servo Motor (SG90), Breadboard, Jumper wires  
**Tinkercad:** Included in project README

---

### 10. LDR Light Sensor
**Location:** [`10.ldr_led/`](10.ldr_led/)  
**Description:** Turn on LED automatically when it gets dark using LDR (Light Dependent Resistor). Automatic control based on light levels.  
**Concepts:** LDR sensors, analog sensors, threshold logic, automatic control, voltage dividers, environmental sensing  
**Components:** Arduino, LED, Resistor (330Ω), LDR (Light Dependent Resistor), Resistor (10kΩ), Breadboard, Jumper wires  
**Tinkercad:** Included in project README

---

### 11. Buzzer
**Location:** [`11.buzzer/`](11.buzzer/)  
**Description:** Generate sounds and melodies using a buzzer. Includes two code examples: basic note playing and complete melody playback.  
**Concepts:** Sound generation, `tone()`, `noTone()`, frequencies, musical notes, arrays, loops, melody creation, PWM for sound  
**Components:** Arduino, Buzzer (passive recommended), Breadboard, Jumper wires  
**Code Files:** `buzzer_basic.ino` (individual notes), `buzzer_melody.ino` (complete melodies)  
**Tinkercad:** Included in project README

---

### 12. Buzzer Button
**Location:** [`12.buzzer_button/`](12.buzzer_button/)  
**Description:** Control buzzer sounds using push buttons. Each button plays a different note or melody.  
**Concepts:** Interactive control, multiple buttons, edge detection, button-triggered sounds, combining input with output  
**Components:** Arduino, Buzzer (passive recommended), Push Buttons (4x), Breadboard, Jumper wires  
**Tinkercad:** Included in project README

---

### 13. Temperature Sensor
**Location:** [`13.temperature_sensor/`](13.temperature_sensor/)  
**Description:** Read temperature from LM35 temperature sensor and display it. Real-world sensor reading and data conversion.  
**Concepts:** Temperature sensors, analog reading, voltage conversion, real-world measurements, mathematical calculations  
**Components:** Arduino, LM35 Temperature Sensor, Breadboard, Jumper wires  
**Tinkercad:** Included in project README

---

### 14. Ultrasonic Sensor
**Location:** [`14.ultrasonic_sensor/`](14.ultrasonic_sensor/)  
**Description:** Measure distance using HC-SR04 ultrasonic sensor. Detect objects and measure distances.  
**Concepts:** Ultrasonic sensors, `pulseIn()`, distance calculation, timing measurements, trigger/echo signals  
**Components:** Arduino, HC-SR04 Ultrasonic Sensor, Breadboard, Jumper wires  
**Tinkercad:** Included in project README

---

### 15. LCD Display
**Location:** [`15.lcd_display/`](15.lcd_display/)  
**Description:** Display text and data on a 16x2 LCD display using I2C communication. Show information visually without Serial Monitor.  
**Concepts:** LCD displays, I2C communication, libraries, text formatting, data display, cursor positioning  
**Components:** Arduino, LCD 16x2 with I2C Module, Breadboard, Jumper wires (4 wires)  
**Tinkercad:** Included in project README

---

## 🚀 Getting Started

### How to Use These Scripts

1. **Start with Script 01** - Begin with the first script in numerical order
2. **Read the README** - Each script has a detailed README with complete documentation
3. **Build the Circuit** - Follow the wiring diagrams provided
4. **Upload the Code** - Open the `.ino` file in Arduino IDE and upload
5. **Test and Observe** - Watch the results and understand how it works
6. **Experiment** - Modify the code to learn more
7. **Move to Next Script** - Progress to the next numbered script

### Prerequisites

- **Arduino IDE** - Download from [arduino.cc](https://www.arduino.cc/en/software)
- **Arduino Board** - Uno, Nano, Mega, or compatible
- **USB Cable** - To connect Arduino to computer
- **Basic Components** - LEDs, resistors, breadboard, jumper wires (listed in each script)

## 📊 Learning Progress Tracker

Use this checklist to track your progress:

- [ ] **01. LED ON** - Mastered digital output basics
- [ ] **02. LED Blink** - Learned timing and loops
- [ ] **03. LED Button** - Understood digital input
- [ ] **04. LED Fade** - Learned PWM and analog output
- [ ] **05. LED Potentiometer** - Mastered analog input
- [ ] **06. RGB LED** - Learned multiple PWM outputs
- [ ] **07. Servo Motor Potentiometer** - Learned actuators and libraries
- [ ] **08. Servo Motor Button** - Learned digital control of actuators
- [ ] **09. Servo Motor Sweep** - Learned automatic motion patterns
- [ ] **10. LDR Light Sensor** - Learned environmental sensors and automatic control
- [ ] **11. Buzzer** - Learned sound generation, notes, and melodies
- [ ] **12. Buzzer Button** - Learned interactive sound control
- [ ] **13. Temperature Sensor** - Learned temperature sensing and data conversion
- [ ] **14. Ultrasonic Sensor** - Learned distance measurement and timing
- [ ] **15. LCD Display** - Learned display output and I2C communication

## 🎓 Concepts Covered

### Digital I/O
- ✅ Digital output (`digitalWrite()`)
- ✅ Digital input (`digitalRead()`)
- ✅ Pin configuration (`pinMode()`)
- ✅ Pull-up resistors
- ✅ Edge detection

### Analog I/O
- ✅ PWM (Pulse Width Modulation)
- ✅ Analog output (`analogWrite()`)
- ✅ Analog input (`analogRead()`)
- ✅ Value mapping (`map()`)

### Advanced Topics
- ✅ Multiple PWM outputs
- ✅ Color mixing (RGB)
- ✅ Custom functions
- ✅ Timing and delays
- ✅ Button debouncing

## 🔧 Component Reference

Common components used across scripts:

| Component | Used In | Purpose |
|-----------|---------|---------|
| LED | All scripts | Visual output indicator |
| Resistor (330Ω) | All scripts | Current limiting for LEDs |
| Push Button | Script 03 | Digital input device |
| Potentiometer (10kΩ) | Script 05 | Analog input device |
| RGB LED | Script 06 | Multi-color output |
| Breadboard | All scripts | Prototyping platform |
| Jumper Wires | All scripts | Circuit connections |

## 📝 Notes

- All scripts are designed for **Arduino Uno** but work with most Arduino-compatible boards
- Scripts use **English** for all code, comments, and documentation
- Each script is **self-contained** with complete documentation
- **Circuit diagrams** are provided for both Tinkercad simulation and real circuits
- Scripts follow **progressive difficulty** - complete them in order

## 🔗 Quick Links

- [Main Repository README](../README.md)
- [Coding Standards (AGENTS.md)](../AGENTS.md)
- [Arduino Official Documentation](https://www.arduino.cc/reference/en/)
- [Arduino IDE Download](https://www.arduino.cc/en/software)

## 🤝 Contributing

If you'd like to add a new script:

1. Follow the naming convention: `##.script_name/`
2. Include complete documentation (README.md)
3. Provide circuit diagrams (Tinkercad + real photos)
4. Add detailed code comments
5. Follow the coding standards in [AGENTS.md](../AGENTS.md)

## 📚 Related Resources

- [Arduino Language Reference](https://www.arduino.cc/reference/en/)
- [Arduino Tutorials](https://www.arduino.cc/en/Tutorial/HomePage)
- [Arduino Forum](https://forum.arduino.cc/)
- [Tinkercad Circuits](https://www.tinkercad.com/circuits)

---

**Happy Learning!** 🎉

*Last Updated: 2025*

