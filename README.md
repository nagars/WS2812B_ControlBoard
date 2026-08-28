# WS2812B_ControlBoard

A dedicated Power Supply and Controller PCB designed to safely power and control WS2812B addressable RGB LED strips using an onboard **ESP32 microcontroller**.

## Overview
A WS2812B LED Power supply and control board that can support power consumption of up to 3.5A (4A ceiling protected by a fuse) and wireless control using an esp32c6. Can connect up to 5 strips. 

<img width="1083" height="572" alt="WS2812BoardF" src="https://github.com/user-attachments/assets/89b4b161-4618-48d2-9a7b-61f6cadf241d" />

<img width="1083" height="572" alt="WS2812BoardB" src="https://github.com/user-attachments/assets/9f432893-8a7c-47bd-a19f-f518059034aa" />

### Power consumption calculation:
- 1 LED consumes 0.3W at max white light brightness. 
- Reducing to 1 colour consumes 0.1 W. 
- At 50% brightness, power consumption drops to 0.05W.
- As a result, in this configuration one can run a 300 LED strip at around 3A.

### Key Features
* **Integrated Power Management:** Safely splits 5V power supply between the high-current LED strip and the ESP32.
* **ESP32 Powered:** Leverage built-in Wi-Fi and Bluetooth to connect your LED project to smart home ecosystems (WLED, Home Assistant, ESPHome).
* **Logic Level Shifting:** Level shifter to bump ESP32's 3.3V GPIO data signal to the 5V signal required by WS2812B strips (prevents flickering and data corruption over longer distances).
* **Decoupling Protection:** large electrolytic capacitors to absorb sudden voltage spikes that could damage the LEDs.

## Hardware Requirements & Recommendations

To fully utilize this board, you will need:
1. **Power Supply:** A high-quality 5V DC power supply capable of supplying enough Amperage for your specific LED strip length (Formula: `Number of LEDs × 0.06A = Total Amps needed`).
2. **WS2812B LED Strip:** 3-pin addressable strip (5V, Data, GND).
3. **Thick Gauge Wire:** For connecting the power supply to the PCB, and the PCB to the LED strips, minimizing voltage drop.

## Safety Warning

* **Double-check polarities:** No AC reverse polarity protection. Follow the silkscreen markers.
* **Heat Dissipation:** Watch for heating at high power loads.

### Schematic Layout
<img width="2245" height="1587" alt="WS2812B_Control_PCB" src="https://github.com/user-attachments/assets/4abc7f95-122d-49fc-8e54-8f9e2fe588da" />

### PCB Layout
<img width="594" height="339" alt="Screenshot from 2026-08-28 14-38-51" src="https://github.com/user-attachments/assets/7500d09f-f4f9-4134-8188-24fb1301a756" />

