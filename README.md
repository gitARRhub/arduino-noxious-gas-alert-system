# Arduino Based Noxious Gas Alerting System With Ambient Observation For Mines

## Overview

This project is an Arduino-based noxious gas alerting system designed for mine safety applications. The system continuously monitors harmful gases, temperature, and humidity levels in underground mines and alerts workers whenever dangerous environmental conditions are detected.

The project uses:
- MQ-7 Gas Sensor
- DHT11 Temperature & Humidity Sensor
- DS3231 RTC Module
- Arduino UNO
- 16x2 LCD Display
- Buzzer and LEDs

The main objective of this project is to improve worker safety in hazardous mining environments using a low-cost embedded system.

---

# Objectives

- Detect harmful gases in mines
- Monitor temperature and humidity
- Alert workers using buzzer and LEDs
- Provide a low-cost safety system
- Display real-time environmental conditions on LCD

---

# Features

- Real-time gas monitoring
- Temperature monitoring
- Humidity monitoring
- Audio alert system using buzzer
- LED indication system
- LCD display output
- Real-time clock display
- Low-cost implementation

---

# Components Used

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| MQ-7 Gas Sensor | 1 |
| DHT11 Sensor | 1 |
| DS3231 RTC Module | 1 |
| 16x2 LCD Display | 1 |
| Buzzer | 1 |
| LEDs | 4 |
| Breadboard | 1 |
| Jumper Wires | Multiple |
| Battery | 1 |

---

# Working Principle

The MQ-7 sensor continuously monitors carbon monoxide gas concentration in the environment. When the gas level exceeds the predefined threshold, the Arduino activates the buzzer and warning LEDs to alert workers.

The DHT11 sensor measures:
- Temperature
- Humidity

These values are displayed on the LCD display in real time.

The DS3231 RTC module displays:
- Date
- Time
- Day

on the LCD display.

---

# Block Diagram

## Input Section
- MQ-7 Gas Sensor
- DHT11 Sensor
- DS3231 RTC

## Processing Section
- Arduino UNO

## Output Section
- LCD Display
- LEDs
- Buzzer

---

# Hardware Used

## Arduino UNO
Main microcontroller used to process sensor data and control outputs.

## MQ-7 Gas Sensor
Used for detecting carbon monoxide concentration in air.

## DHT11 Sensor
Measures temperature and humidity.

## DS3231 RTC Module
Provides accurate real-time date and time.

## LCD Display
Displays gas concentration, temperature, humidity, and time.

## Buzzer
Provides alert sound when dangerous gas concentration is detected.

---

# Software Used

## Arduino IDE

The project is programmed using Arduino IDE.

Features:
- Writing and uploading code
- Compatible with Arduino boards
- Offline development support
- Serial monitoring support

Download Arduino IDE:
https://www.arduino.cc/en/software

---

# Source Code

The source code for the project is included in the `src/` folder.

Main functionalities:
- Gas sensing
- Temperature monitoring
- Humidity monitoring
- RTC display
- LCD interfacing
- Buzzer alert system

---

# Results

The system successfully:
- Detects harmful gases
- Displays gas concentration on LCD
- Activates buzzer when gas exceeds threshold
- Displays temperature and humidity
- Indicates safe/danger conditions using LEDs

---

# Applications

- Coal mines
- Industrial safety systems
- Oil and gas industries
- Indoor air quality monitoring
- Agricultural industries
- Medical environments

---

# Future Improvements

Future enhancements may include:
- Wi-Fi module integration
- GPS tracking
- IoT-based monitoring
- Remote alert system
- Mobile application support

---

# Cost Analysis

| Component | Cost |
|---|---|
| Arduino UNO | ₹800 |
| DHT11 | ₹85 |
| MQ7 | ₹120 |
| DS3231 | ₹130 |
| LCD | ₹100 |
| Buzzer | ₹10 |
| Breadboard | ₹50 |
| Other Components | ₹100 |

**Total Cost:** ₹1400 Approx.

---

# Folder Structure

```text
arduino-noxious-gas-alert-system/
│
├── README.md
├── src/
│   └── gas_alert_system.ino
│
├── images/
│   ├── full_setup.jpg
│   ├── wiring.jpg
│   └── working.jpg
│
├── circuit_diagram/
│   ├── circuit.png
│   └── schematic.pdf
│
├── docs/
│   ├── project_report.pdf
│   └── presentation.pptx
│
└── components/
    └── components_list.txt
