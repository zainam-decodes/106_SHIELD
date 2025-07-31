![Typing SVG](https://readme-typing-svg.demolab.com?font=Fira+Code&size=32&weight=800&duration=7000&pause=1000&color=002D9C&vCenter=false&width=1000&lines=SHIELD+—+A+SMART+GUARDIAN;LIVE+STREAMING+%7C+CALL+%7C+LIVE+LOCATION+%7C+SOS+ALERT+MESSAGE;WITH+WI-FI+%7C+BLUETOOTH+CAPABILITIES)

# 106_SHIELD

**A Silent guardian which listens when none listens and which acts  before it's too late.**
**SHIELD** is a compact and intelligent safety system designed to send emergency alerts, share live video feed, capture and store images, and track real-time location. It integrates Wi-Fi, Bluetooth, and GSM/GPS functionalities using ESP32-CAM and SIMCom A9G modules.

## Overview

This project is designed to provide a multi-functional security solution capable of:

- Triggering an SOS alert via push button or sound sensor
- Sending SMS with live GPS coordinates and stream link
- Initiating automatic calls in emergencies
- Capturing images and storing them on an SD card
- Streaming live video over Wi-Fi
- Sharing stream links via SMS, Bluetooth, and email


## Features

- SOS alert trigger (button or voice/sound)
- Automatic image capture and storage
- Real-time GPS location tracking using SIMCom A9G
- SMS and call alerts
- Live camera streaming via ESP32-CAM
- Stream link sharing via SMS, Bluetooth, and email
- SD card support for local image storage


## Hardware Requirements

- ESP32-CAM module
- SIMCom A9G (GSM + GPS)
- Micro SD card module (FAT32)
- Push button
- Sound sensor module
- 3.7V lithium battery / power bank
- FTDI programmer (for uploading code)
- Jumper wires and breadboard


## How the System Works

1. On startup, the ESP32-CAM initializes all modules.
2. If a button is pressed or sound is detected:
   - An image is captured using the onboard camera.
   - GPS coordinates are retrieved via SIMCom A9G.
   - The image is saved to the SD card.
   - An SMS is sent with the live stream link and GPS location.
   - The camera starts live streaming over Wi-Fi.
   - Stream link can also be shared via Bluetooth or email.


## Future Enhancements

- Integration with face detection or motion detection
- Cloud-based image storage (Firebase, AWS)
- Battery optimization for long-term deployment
- Development of a companion mobile application

---

## Author
**(TEAM CODEWIZARDS)**
**Zainab Jahan Umaima**  
Second Year Undergraduate  
Methodist College of Engineering  
Email: thezainabjahan14@gmail.com 
LinkedIn:www.linkedin.com/in/zayjaumaima


