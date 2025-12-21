# Arduino From Zero to Expert

A comprehensive learning repository for Arduino programming, from beginner basics to advanced topics. This repository contains Arduino projects, code examples, tutorials, and educational content to help you master microcontroller programming.

## 📚 About This Repository

This repository is designed as a structured learning path for Arduino enthusiasts. Each project includes complete documentation, circuit diagrams, and step-by-step instructions to help you learn progressively.

## 🚀 Getting Started

### Prerequisites

- **Arduino IDE** - Download from [arduino.cc](https://www.arduino.cc/en/software)
- **Arduino Board** - Any Arduino-compatible board (Uno, Nano, Mega, etc.)
- **USB Cable** - To connect your board to your computer
- **Basic Components** - LEDs, resistors, breadboard, jumper wires (for beginner projects)

### Quick Start

1. **Install Arduino IDE** from the [official website](https://www.arduino.cc/en/software)
2. **Clone This Repository**
   ```bash
   git clone https://github.com/yourusername/arduino-from-zero-to-expert.git
   cd arduino-from-zero-to-expert
   ```
3. **Navigate to a Script** - Go to `scripts/` folder and choose a project
4. **Open and Upload** - Open the `.ino` file in Arduino IDE, connect your board, and upload

## 📖 Arduino Learning Scripts

All scripts are located in the `scripts/` folder and are organized in a progressive learning order. Each script includes:
- Complete source code with comments
- Circuit diagrams (Tinkercad simulation + real photos)
- Component list and connections
- Step-by-step instructions
- Code explanation
- Troubleshooting guide

### 📋 Scripts Index

#### Beginner Level

| # | Script | Description | Concepts |
|---|--------|-------------|----------|
| **01** | [LED ON](scripts/01.led/) | Turn on an LED and keep it on | Digital output, `pinMode()`, `digitalWrite()` |
| **02** | [LED Blink](scripts/02.led_blink/) | Blink an LED on and off | Digital output, `delay()`, loops |
| **03** | [LED Button](scripts/03.led_button/) | Control LED with a push button | Digital input, `digitalRead()`, edge detection, pull-up resistors |
| **04** | [LED Fade](scripts/04.led_fade/) | Smooth fade in/out effect using PWM | PWM, `analogWrite()`, analog output, brightness control |
| **05** | [LED Potentiometer](scripts/05.led_potentiometer/) | Control LED brightness with potentiometer | Analog input, `analogRead()`, `map()`, voltage divider |
| **06** | [RGB LED](scripts/06.rgb_led/) | Control RGB LED to display different colors | RGB color model, multiple PWM outputs, color mixing, custom functions |
| **07** | [Servo Motor Potentiometer](scripts/07.servo_motor_potentiometer/) | Control servo position with potentiometer | Servo library, actuators, `servo.write()`, position control, libraries |
| **08** | [Servo Motor Button](scripts/08.servo_motor_button/) | Control servo position with buttons | Digital input control, edge detection, incremental positioning, button debouncing |
| **09** | [Servo Motor Sweep](scripts/09.servo_motor_sweep/) | Automatic back-and-forth servo motion | Automatic control, for loops, continuous motion patterns, speed control |
| **10** | [LDR Light Sensor](scripts/10.ldr_led/) | Automatic LED control based on light level | LDR sensors, analog sensors, threshold logic, automatic control, voltage dividers |
| **11** | [Buzzer](scripts/11.buzzer/) | Generate sounds and melodies (2 code examples) | Sound generation, `tone()`, `noTone()`, frequencies, arrays, loops, melody creation |
| **12** | [Buzzer Button](scripts/12.buzzer_button/) | Control sounds with buttons | Interactive control, multiple buttons, edge detection, button-triggered sounds |
| **13** | [Temperature Sensor](scripts/13.temperature_sensor/) | Read temperature from LM35 sensor | Temperature sensors, analog reading, voltage conversion, real-world measurements |
| **14** | [Ultrasonic Sensor](scripts/14.ultrasonic_sensor/) | Measure distance with HC-SR04 | Ultrasonic sensors, `pulseIn()`, distance calculation, timing measurements |
| **15** | [LCD Display](scripts/15.lcd_display/) | Display text on 16x2 LCD using I2C | LCD displays, I2C communication, libraries, text formatting, data display |

### 🎯 Learning Path

Follow the scripts in numerical order (01, 02, 03, 04, 05, 06, 07...) to build your Arduino skills progressively:

1. **Start with Basics** - Scripts 01-02 introduce digital output control
2. **Add Interaction** - Script 03 introduces digital input with buttons
3. **Explore Analog Output** - Script 04 introduces PWM and analog output
4. **Explore Analog Input** - Script 05 introduces analog input with potentiometer
5. **Multiple Outputs** - Script 06 introduces multiple PWM outputs with RGB LED
6. **Actuators and Libraries** - Script 07 introduces servo motors and Arduino libraries
7. **Digital Control of Actuators** - Script 08 shows button control of servos
8. **Automatic Motion** - Script 09 demonstrates automatic sweep patterns
9. **Environmental Sensors** - Script 10 introduces LDR sensors and automatic control
10. **Sound Output** - Script 11 introduces buzzer with basic and melody examples
11. **Interactive Sound** - Script 12 combines buttons with buzzer for interactive control
12. **Temperature Sensing** - Script 13 introduces temperature sensors and data conversion
13. **Distance Measurement** - Script 14 introduces ultrasonic sensors and distance calculation
14. **Display Output** - Script 15 introduces LCD displays and I2C communication
15. **Continue Learning** - More scripts coming soon!

## 📁 Repository Structure

```
arduino-from-zero-to-expert/
├── scripts/           # Arduino learning scripts (numbered in learning order)
│   ├── 01.led/        # LED ON example
│   ├── 02.led_blink/  # LED blink example
│   ├── 03.led_button/ # LED button control
│   ├── 04.led_fade/   # LED fade effect
│   ├── 05.led_potentiometer/ # LED brightness control with potentiometer
│   ├── 06.rgb_led/    # RGB LED color control
│   ├── 07.servo_motor_potentiometer/ # Servo motor control with potentiometer
│   ├── 08.servo_motor_button/ # Servo motor control with buttons
│   ├── 09.servo_motor_sweep/ # Automatic servo sweep motion
│   ├── 10.ldr_led/ # LDR light sensor automatic LED control
│   ├── 11.buzzer/ # Buzzer sound generation (basic + melody examples)
│   ├── 12.buzzer_button/ # Buzzer button control
│   ├── 13.temperature_sensor/ # Temperature sensor reading
│   ├── 14.ultrasonic_sensor/ # Ultrasonic distance measurement
│   ├── 15.lcd_display/ # LCD 16x2 text display with I2C
│   └── ...
├── docs/              # Tutorials and detailed documentation
├── AGENTS.md          # AI agent guidelines and coding standards
└── README.md          # This file
```

## 📖 How to Use This Repository

1. **Start with Script 01** - Begin with the first script in the `scripts/` folder
2. **Read the README** - Each script has a detailed README with circuit diagrams
3. **Build the Circuit** - Follow the wiring diagrams provided
4. **Upload and Test** - Upload the code and observe the results
5. **Experiment** - Modify the code to understand how it works
6. **Move to Next Script** - Progress to the next numbered script

## 🤝 Contributing

Contributions are welcome! Please follow these guidelines:

- All code and documentation must be in **English**
- Follow the coding standards in [AGENTS.md](AGENTS.md)
- Include a comprehensive README.md for each script
- Provide circuit diagrams (Tinkercad + real photos)
- Add clear comments explaining the code

## 📄 License

See [LICENSE](LICENSE) file for details.

## 🔗 Useful Resources

- [Arduino Official Documentation](https://www.arduino.cc/reference/en/)
- [Arduino IDE Guide](https://www.arduino.cc/en/guide)
- [Arduino Language Reference](https://www.arduino.cc/reference/en/)
- [Arduino Forum](https://forum.arduino.cc/)

---

**Happy Learning!** 🎉
