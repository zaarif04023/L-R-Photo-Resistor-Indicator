# L-R-Photo-Resistor-Indicator

# Arduino Light Detection System

## Overview

This project uses two photoresistors to measure light levels on the left and right sides of a system. Based on the difference between the two readings, the Arduino activates one of three LEDs to indicate whether the left side, right side, or center has the stronger light level.

The system uses calibrated sensor values to convert raw analog readings into percentages, making it easier to compare the light intensity detected by each sensor.

## Features

- **Dual Light Detection:** Reads light levels from two photoresistors connected to analog pins A0 and A1.
- **Sensor Calibration:** Uses minimum and maximum sensor values to map raw readings to a percentage scale from 0 to 100.
- **Three-LED Indicator:** Displays whether the left sensor, right sensor, or center condition is detected.
- **Serial Monitor Output:** Prints sensor readings, calculated brightness percentages, and the detected direction.
- **Threshold-Based Detection:** Uses a 10-point difference between calculated brightness values to determine whether one side has significantly more light.

## Hardware Requirements

- Arduino Uno or compatible board
- 2 photoresistors (LDRs)
- 3 LEDs
- 3 current-limiting resistors for the LEDs (typically 220–330 Ω)
- Resistors for the photoresistor voltage-divider circuits
- Breadboard
- Jumper wires
- USB cable for programming and serial communication

## Pin Configuration

| Component | Arduino Pin |
|---|---|
| Left photoresistor | A0 |
| Right photoresistor | A1 |
| Left LED | Digital pin 12 |
| Center LED | Digital pin 11 |
| Right LED | Digital pin 10 |

## Calibration

The minimum and maximum values determine how raw readings are converted to percentages.

```cpp
int leftMin = 6, leftMax = 1017;
int rightMin = 0, rightMax = 1016;
```

To calibrate the sensors:

1. Upload the program to the Arduino.
2. Open the Serial Monitor and set the baud rate to 9600.
3. Observe each photoresistor's raw readings under different lighting conditions.
4. Update the minimum and maximum values based on the readings you observe.
5. Test the LEDs under different lighting conditions to confirm the system responds as expected.

## How It Works

### 1. Read Sensor Values

The Arduino reads the analog values from both photoresistors using `analogRead()`.

```cpp
int leftLightLevel = analogRead(leftPhotoResistor);
int rightLightLevel = analogRead(rightPhotoResistor);
```

The analog readings typically range from 0 to 1023.

### 2. Convert Readings to Percentages

The `map()` function converts each sensor's raw reading into a percentage using its calibrated minimum and maximum values.

```cpp
int brightnessL = map(leftLightLevel, leftMin, leftMax, 0, 100);
int brightnessR = map(rightLightLevel, rightMin, rightMax, 0, 100);
```

Current calibration values:

- Left sensor: minimum = 6, maximum = 1017
- Right sensor: minimum = 0, maximum = 1016

These values should be adjusted to match the readings from your actual sensors.

### 3. Determine the Detected Direction

The Arduino compares the calculated brightness percentages.

| Condition | LED Output | Result |
|---|---|---|
| Left brightness is more than 10 points higher than right brightness | Left LED ON | Left |
| Right brightness is more than 10 points higher than left brightness | Right LED ON | Right |
| Equal | Center LED ON | Center |

Only one LED is activated at a time.

### 4. Display Results

The Serial Monitor displays the raw sensor readings, calculated percentages, and detected direction.

## Project Purpose

This project demonstrates fundamental Arduino concepts, including analog input, sensor calibration, conditional logic, digital output, and serial communication. It can also serve
