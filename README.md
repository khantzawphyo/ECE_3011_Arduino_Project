# Arduino-based Car Parking System

## Project Overview
This project is an Arduino-based car parking system designed to manage and monitor the availability of parking spaces in real-time. The system uses ultrasonic sensors to detect the presence of cars in parking slots and displays the availability of spaces on an LCD screen.

## Team Members
> Details in the Project Report.

## Project Description
The car parking system is a smart solution that automates the process of tracking available parking slots in a given area. Using ultrasonic sensors, the system can determine whether a parking spot is occupied or vacant and updates this information on an LCD display. The project was developed as part of the ECE_3011 Microprocessors and Interfacing course to apply the principles of microprocessor interfacing with real-world hardware components.

## Features
- **Real-time monitoring**: The system continuously checks the status of parking slots.
- **User-friendly display**: Information about the availability of parking spaces is displayed on an LCD.
- **Scalability**: The system can be expanded to manage more parking slots by adding additional sensors.

## Hardware Components
- Arduino Uno
- Ultrasonic Sensors (e.g., HC-SR04)
- LCD Display
- Breadboard and Jumper Wires
- Resistors

## Software Requirements
- Arduino IDE

## Setup and Installation
1. **Hardware Setup**:
   - Connect the ultrasonic sensors to the Arduino pins.
   - Wire the LCD display to the appropriate Arduino pins.
   - Ensure all components are powered and connected correctly.

2. **Software Installation**:
   - Install the Arduino IDE from [Arduino's official website](https://www.arduino.cc/en/software).
   - Download and open the project files in the Arduino IDE.
   - Upload the code to the Arduino Uno.

## How It Works
The system works by continuously monitoring each parking slot using an ultrasonic sensor. When a car is detected in a slot, the sensor sends this data to the Arduino, which then updates the availability status on the LCD display.

## Code Explanation
The code is structured into the following key sections:
- **Sensor Reading**: This section handles data input from the ultrasonic sensors.
- **Display Update**: This section manages the information shown on the LCD based on sensor readings.
- **Main Loop**: The main loop continuously checks the sensor readings and updates the display.

## Usage Instructions
1. Power on the Arduino system.
2. Monitor the LCD screen to see the availability of parking spaces.
3. The system will automatically update as cars enter or leave the slots.

## Conclusion
This project demonstrates the application of microprocessor interfacing in creating a real-world solution for parking management. The system is designed for scalability and can be extended to handle more parking slots by adding additional sensors.

