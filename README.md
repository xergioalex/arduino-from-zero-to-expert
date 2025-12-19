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

### 🎯 Learning Path

Follow the scripts in numerical order (01, 02, 03, 04...) to build your Arduino skills progressively:

1. **Start with Basics** - Scripts 01-02 introduce digital output control
2. **Add Interaction** - Script 03 introduces digital input with buttons
3. **Explore Analog** - Script 04 introduces PWM and analog output
4. **Continue Learning** - More scripts coming soon!

## 📁 Repository Structure

```
arduino-from-zero-to-expert/
├── scripts/           # Arduino learning scripts (numbered in learning order)
│   ├── 01.led/        # LED ON example
│   ├── 02.led_blink/  # LED blink example
│   ├── 03.led_button/ # LED button control
│   ├── 04.led_fade/   # LED fade effect
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
