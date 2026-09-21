# RFID-Based Smart Attendance & Access Management System

An Arduino-based RFID system that identifies registered users and provides attendance and access feedback using an RC522 RFID reader.

## 📌 Project Overview

This project uses an Arduino UNO and RC522 RFID reader to identify RFID cards through their unique IDs.

When a registered card is scanned, the system displays the user's name and attendance status on a 16×2 I2C LCD, turns on the green LED, and produces one short beep.

For an unregistered card, the system displays an access denied message, turns on the red LED, and produces two short beeps.

## ✨ Features

- RFID-based user identification
- Registered and unregistered card verification
- Attendance status indication
- 16×2 I2C LCD display
- Green LED for valid cards
- Red LED for invalid cards
- Buzzer feedback
- Serial Monitor logging
- Prevents repeated processing while the same card remains near the reader

## 🔧 Components Used

- Arduino UNO R3
- RC522 RFID Reader Module
- RFID Card / Tag
- 16×2 I2C LCD
- Green LED
- Red LED
- 5V Buzzer
- 220Ω Resistors
- Breadboard
- Jumper Wires
- USB Cable

## 🔌 Pin Connections

| Component | Pin | Arduino UNO |
|---|---|---|
| RC522 | SDA / SS | D10 |
| RC522 | SCK | D13 |
| RC522 | MOSI | D11 |
| RC522 | MISO | D12 |
| RC522 | RST | D9 |
| RC522 | 3.3V | 3.3V |
| RC522 | GND | GND |
| I2C LCD | SDA | A4 |
| I2C LCD | SCL | A5 |
| I2C LCD | VCC | 5V |
| I2C LCD | GND | GND |
| Green LED | Anode via 220Ω | A0 |
| Red LED | Anode via 220Ω | A1 |
| Buzzer | Positive | D8 |
| Buzzer | Negative | GND |

## ⚙️ How It Works

1. The Arduino initializes the RC522 RFID reader, LCD, LEDs, buzzer and communication interfaces.
2. The RC522 detects an RFID card and reads its unique UID.
3. The Arduino compares the scanned UID with the registered UID.
4. For a valid card, access is granted and attendance is marked.
5. For an invalid card, access is denied.
6. The LCD, LEDs, buzzer and Serial Monitor provide feedback.
7. The system waits for the card to be removed before accepting another scan.

## 💻 Technologies & Concepts

- Arduino Programming
- C/C++
- RFID Communication
- SPI Communication
- I2C Communication
- Digital Input/Output
- Serial Communication
- Conditional Logic
- Hardware Debugging

## 📚 Libraries Used

- MFRC522
- LiquidCrystal_I2C

## 🧪 Testing

The system was tested using both registered and unregistered RFID cards.

### Registered Card
- LCD: Welcome message and attendance confirmation
- Green LED: ON
- Buzzer: One short beep
- Serial Monitor: Access GRANTED / Attendance MARKED

### Unregistered Card
- LCD: Access Denied
- Red LED: ON
- Buzzer: Two short beeps
- Serial Monitor: Access DENIED / Attendance NOT MARKED

## 📸 Project Demonstration

Photos and demonstration media of the physical hardware implementation can be added here.

## 🎯 Learning Outcome

This project provided hands-on experience in RFID interfacing, SPI and I2C communication, Arduino programming, hardware debugging, and integrating multiple output devices into an embedded system.

## 👩‍💻 Author

**Manasi Ambore**  
Electronics & Communication Engineering Student
