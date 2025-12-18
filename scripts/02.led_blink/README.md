# LED Blink Example

A simple Arduino project to blink an LED. This is the perfect first project for beginners learning Arduino programming.

## 📋 Project Description

This project demonstrates the most basic Arduino functionality: controlling an LED. The LED will blink on and off every second, creating a simple but effective introduction to digital output control.

**Difficulty Level:** Beginner  
**Learning Objectives:**
- Understanding digital pins and outputs
- Using `pinMode()` and `digitalWrite()` functions
- Working with `delay()` function
- Understanding the `setup()` and `loop()` structure

## 🔧 Components Required

- **Arduino Board** (Uno, Nano, Mega, or compatible)
- **USB Cable** (to connect Arduino to computer)
- **LED** (optional, for external LED - any color)
- **Resistor** (330Ω, optional - only needed for external LED)
- **Breadboard** (optional - only needed for external LED)
- **Jumper Wires** (optional - only needed for external LED)

## 🔌 Circuit Connections

This project uses **Pin 12** for the external LED. Pin 12 does not have a built-in LED, so you need to connect an external LED.

**Circuit Connections:**

```
LED Anode (long leg) → Resistor (330Ω) → Pin 12
LED Cathode (short leg) → GND
```

**Visual Connection Guide:**
```
Arduino Board:
    Pin 12 ────[330Ω Resistor]───[LED Anode (+)]
    
    GND ─────────────────────────[LED Cathode (-)]
```

### Circuit Diagrams

**Tinkercad Simulation:**
https://www.tinkercad.com/things/00HPbnr4mdj-led-blink

![Tinkercad Circuit](circuit_tinkercad.png)

**Real Circuit Photo:**
![Real Circuit](circuit_real.png)

**Important Notes:**
- The LED anode (positive, long leg) connects to the resistor, then to pin 12
- The LED cathode (negative, short leg) connects directly to GND
- Always use a resistor (220Ω-330Ω) to protect the LED from excessive current
- Pin 12 is used instead of pin 13 to avoid the built-in LED (pin 13 has a built-in LED on most Arduino boards)
- This allows independent control of the external LED

## 💻 Code Explanation

### Key Functions

**`pinMode(LED_PIN, OUTPUT)`**
- Configures pin 12 as an output pin
- Must be called in `setup()` before using the pin
- `OUTPUT` means the pin will send signals (not receive them)

**`digitalWrite(LED_PIN, HIGH)`**
- Sets pin 12 to HIGH (5V or 3.3V depending on board)
- Turns the LED ON

**`digitalWrite(LED_PIN, LOW)`**
- Sets pin 12 to LOW (0V)
- Turns the LED OFF

**`delay(1000)`**
- Pauses the program for 1000 milliseconds (1 second)
- Allows you to see the LED state change
- Without delay, the LED would blink too fast to see

### Program Flow

1. **`setup()`** - Runs once when Arduino starts:
   - Configures pin 12 as output
   - Initializes serial communication for debugging
   - Sends "LED Blink Example Started" message to Serial Monitor

2. **`loop()`** - Runs continuously:
   - Turn LED ON (set pin to HIGH)
   - Send "LED ON" message to Serial Monitor
   - Wait 1 second
   - Turn LED OFF (set pin to LOW)
   - Send "LED OFF" message to Serial Monitor
   - Wait 1 second
   - Repeat forever

## 🚀 Usage Instructions

### Step 1: Open the Code

1. Open Arduino IDE
2. Open the file `led.ino` from this folder

### Step 2: Connect Arduino

1. Connect your Arduino board to your computer using the USB cable
2. Wait for the computer to recognize the device

### Step 3: Configure Arduino IDE

1. Go to **Tools → Board** and select your Arduino model (e.g., "Arduino Uno")
2. Go to **Tools → Port** and select the COM port where your Arduino is connected
   - On Windows: Usually `COM3`, `COM4`, etc.
   - On Mac/Linux: Usually `/dev/tty.usbmodem...` or `/dev/ttyUSB0`

### Step 4: Upload the Code

1. Click the **Upload** button (→) in Arduino IDE
2. Wait for the compilation and upload to complete
3. You should see "Done uploading" message

### Step 5: Observe the Result

- The external LED connected to pin 12 should start blinking (ON for 1 second, OFF for 1 second)
- Open the Serial Monitor (Tools → Serial Monitor) to see debug messages
- You should see "LED Blink Example Started", "LED ON", and "LED OFF" messages repeating

## 🔍 Expected Behavior

- LED turns ON for 1 second
- LED turns OFF for 1 second
- This pattern repeats indefinitely
- Serial Monitor shows "LED ON" and "LED OFF" messages

## 🛠️ Troubleshooting

### LED Not Blinking

**Problem:** Nothing happens after uploading
- **Solution:** Check that the correct board and port are selected in Arduino IDE
- **Solution:** Verify the upload completed successfully (check for errors)
- **Solution:** Try pressing the reset button on your Arduino board

### External LED Not Working

**Problem:** External LED doesn't light up or blink
- **Solution:** Check LED polarity - the long leg (anode) must connect to pin 12, short leg (cathode) to GND
- **Solution:** Verify the resistor is connected (330Ω recommended)
- **Solution:** Verify the LED is connected to pin 12 (check the `LED_PIN` constant in code)
- **Solution:** Test the LED by connecting it directly to 5V and GND (with resistor) to verify it works
- **Solution:** Make sure connections are secure and not loose
- **Solution:** Check that the code uploaded successfully

### Wrong Blink Speed

**Problem:** LED blinks too fast or too slow
- **Solution:** Modify the `delay(1000)` values in the code
  - Increase value (e.g., `delay(2000)`) for slower blinking
  - Decrease value (e.g., `delay(500)`) for faster blinking

### Serial Monitor Shows Nothing

**Problem:** No messages in Serial Monitor
- **Solution:** Make sure Serial Monitor is set to 9600 baud (bottom right of Serial Monitor window)
- **Solution:** Click the Serial Monitor icon after uploading the code

## 🎓 Learning Concepts

This project teaches:
- **Digital Output:** Controlling on/off states
- **Timing:** Using delays to control program flow
- **Arduino Structure:** Understanding `setup()` and `loop()`
- **Hardware Control:** Direct control of physical components

## 🔄 Next Steps

After mastering this project, try:
- Changing the blink speed
- Adding multiple LEDs
- Using different pins
- Creating patterns (Morse code, SOS signal, etc.)
- Controlling LED with a button

## 📝 Notes

- This project uses **Pin 12** for the external LED
- Pin 12 does not have a built-in LED, allowing independent control
- Pin 13 has a built-in LED on most Arduino boards, but this project uses pin 12 to avoid interference
- Always use a current-limiting resistor (220Ω-330Ω) with LEDs to prevent damage
- The `delay()` function pauses the program, allowing you to see the LED state changes
- You can change `LED_PIN` to any digital pin (2-13) if needed
- Modify the `delay()` values to change the blink speed

## 📚 Related Resources

- [Arduino Digital Pins Reference](https://www.arduino.cc/reference/en/language/functions/digital-io/)
- [Arduino delay() Function](https://www.arduino.cc/reference/en/language/functions/time/delay/)
- [LED Basics](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink)

---

**Author:** XergioAleX  
**Date:** 2025  
**Version:** 1.0  
**Project:** LED Blink Example

