# Home Appliances Control Project

## Overview
This project is a **mobile-based home automation system** that allows users to control home appliances remotely using an Android application. It is developed as part of the **CSE211: Introduction to Embedded Systems** course at **Ain Shams University**.

The system is built using a **TM4C123GH6PM microcontroller**, which controls appliances based on user commands received via UART communication. It also monitors the room temperature and door status, triggering an alarm if the temperature exceeds a predefined threshold.

## Features
- **Lamp Control**: Turn a 220V lamp ON/OFF remotely while keeping a manual switch.
- **Plug Control**: Enable/Disable a power plug, preventing unauthorized use when off.
- **Door Status Monitoring**: Check if the door is open or closed using a magnetic switch.
- **Temperature Monitoring**: Display real-time room temperature.
- **Temperature Alarm**: Trigger a software and physical alarm (buzzer) if the temperature exceeds a set threshold.
- **Door Activity Logging**: Store and display timestamps for door open/close events.

## Components Used
- **TM4C123GH6PM microcontroller**
- **Relay Module** (to switch the 220V lamp and plug)
- **Magnetic Door Sensor**
- **Temperature Sensor**
- **Buzzer**
- **Android Smartphone** (running a custom-built mobile application)

## System Implementation
### Microcontroller Firmware
- Uses **UART communication** to receive control commands from the mobile app.
- Uses **GPIO** for appliance control and door status monitoring.
- Uses **ADC** to read the temperature sensor.
- Implements **interrupts and polling** to handle inputs efficiently.

### Android Application
- Sends commands to the microcontroller via **Bluetooth/UART**.
- Displays door status and room temperature.
- Allows users to toggle the lamp and plug.
- Alerts users when the temperature exceeds a safe level.
- Logs door open/close times for security tracking.

## How It Works
1. The **Android app** sends a command (e.g., 'L' for lamp, 'P' for plug) via **UART**.
2. The **microcontroller** receives the command and toggles the corresponding output.
3. The **door sensor** updates the app with "OPEN" or "CLOSED" status.
4. The **temperature sensor** continuously monitors the room temperature.
5. If the temperature **exceeds the threshold**, a **buzzer sounds**, and a **warning is sent to the app**.
6. All door activity is **logged and displayed** on the mobile app.

## Project Deliverables
- **Source Code**: Firmware (TM4C123) + Android Application Code
- **Demo Video**: A 5-minute demonstration of the project in action.
- **Technical Report**: Contains
  - Team contributions
  - Flowcharts
  - Component list & wiring diagrams
  - Prototype photos
  - Challenges & solutions

## How to Use
1. **Upload the firmware** to the TM4C123GH6PM board.
2. **Install the mobile app** on an Android device.
3. **Connect via Bluetooth/UART** to the microcontroller.
4. Use the app to **toggle the lamp/plug, check the door status, and monitor the temperature**.
5. If the **temperature is too high**, the alarm will activate automatically.

## Challenges Faced & Solutions
- **UART Communication Issues**: Resolved by optimizing baud rate settings.
- **Power Management for 220V devices**: Used relay modules for safe switching.
- **Mobile App Debugging**: Tested multiple UI/UX designs for better usability.

## Conclusion
This project successfully demonstrates an embedded system for **smart home automation**, integrating hardware and software to enhance home security and convenience. Future improvements may include **Wi-Fi connectivity** and **voice control integration**.


---
Project developed for **Ain Shams University - Faculty of Engineering**.

