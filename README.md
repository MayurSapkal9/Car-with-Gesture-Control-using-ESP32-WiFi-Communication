
# Car with Gesture Control using ESP32 WiFi Communication

This project implements a DIY car with gesture control using an ADXL345 accelerometer connected to an ESP32 microcontroller. The ESP32 communicates with the car through WiFi, and another ESP32 is used on the car to receive real-time gesture coordinates and drive the L298N motor driver.


## Features

- Gesture control of the DIY car using an ADXL345 accelerometer
- Real-time transmission of gesture coordinates through WiFi
- ESP32 microcontroller for processing and communication
- L298N motor driver for controlling the car's movement
- Customizable and expandable for future enhancements



## Components Used

- DIY car chassis with four wheels
- ADXL345 accelerometer
- ESP32 microcontroller (Controller)
- ESP32 microcontroller (Car)
- L298N motor driver
- Jumper wires
- Power supply (battery or DC adapter)
- Breadboard (optional, for circuit prototyping)

## Block Diagram

![Block Diagram](https://github.com/MayurSapkal9/Car-with-Gesture-Control-using-ESP32-WiFi-Communication/blob/main/Images/Block%20Diagram.jpg)
##  Installation and Setup

1. Set up the Arduino IDE and ESP32 board support.
2. Install the required libraries for the ADXL345 accelerometer and WiFi communication.
3. Connect the components as per the circuit diagram.
4. Upload the code to the ESP32 microcontrollers using the Arduino IDE.
5. Ensure that both the Controller and Car ESP32 boards are connected to WiFi.
6. Verify that the gesture coordinates are being transmitted and received correctly.

## Usage

1. Power on the DIY car and the Controller ESP32.
2. Connect the Controller ESP32 to the WiFi network.
3. Hold the ADXL345 accelerometer and perform gestures to control the car's movement.
4. The accelerometer data is sent wirelessly to the Car ESP32, which drives the L298N motor driver based on the received gesture coordinates.
5. Observe the car's response to the performed gestures.

## Testing and Calibration

- Ensure that the accelerometer is properly connected and calibrated for accurate gesture detection.
- Test the gesture control by performing various predefined gestures and verifying the car's response.
- Calibrate the sensitivity and threshold values as per your requirements and the car's capabilities.

## Video

[Video](https://youtu.be/GvW9IaUmPh0)
## Screenshots

 - CAR
   ![CAR](https://github.com/MayurSapkal9/Car-with-Gesture-Control-using-ESP32-WiFi-Communication/blob/main/Images/CAR.jpg)

-  Controller
    ![Controller](https://github.com/MayurSapkal9/Car-with-Gesture-Control-using-ESP32-WiFi-Communication/blob/main/Images/Controller.jpg)




## Acknowledgements

 Special thanks to the contributors and open-source projects that have inspired and provided valuable resources for this DIY car with gesture control project.

## Feedback

If you have any feedback, please reach out to us at :

- mayureshvsapkal9@gmail.com
- saurabhhagawane718@gmail.com


## Contributors

[Mayuresh Sapkal](https://github.com/MayurSapkal9)

[ Saurabh Hagawane](https://github.com/Saurabhh-37)