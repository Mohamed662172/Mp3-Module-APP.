# MP3 Module Control System (AVR ATmega32A)

A reusable and modular **MP3 Player Control Library** developed for the **ATmega32A Microcontroller**. This project provides a high-level API to control the **DFPlayer Mini** (or similar MP3 modules) via the UART protocol.

---

## 🎵 Project Overview

The system is built with a layered architecture (MCAL, HAL, and Application) to ensure reusability and clean code. It abstracts the complex serial command frames of the MP3 module into simple, intuitive C functions.

### 🔑 Key Features

- **Full Playback Control:** Play, Pause, Resume, Stop, Next, and Previous track.
- **Advanced Navigation:** Play specific tracks from folders or the root directory.
- **Volume & EQ Management:** 30 levels of volume control and multiple Equalizer presets (Normal, Pop, Rock, Jazz, Classic, Bass).
- **Status Monitoring:** Query functions to check if a track is playing, current volume, and total tracks on SD/USB.
- **Modular Design:** Easily portable to other AVR microcontrollers by updating the MCAL layer.

---

## 🏗️ System Architecture

The project follows a strict **Hardware Abstraction Layer (HAL)** approach, separating the MP3 logic from the UART communication.

![System Architecture](https://private-us-east-1.manuscdn.com/sessionFile/6d6PodzvRjfNhM4gyqPamI/sandbox/Yzp4pMcF5y4EyLgvYD063K-images_1771620072180_na1fn_L2hvbWUvdWJ1bnR1L01wMy1Nb2R1bGUtQVBQL21wM19zdHJ1Y3R1cmU.png?Policy=eyJTdGF0ZW1lbnQiOlt7IlJlc291cmNlIjoiaHR0cHM6Ly9wcml2YXRlLXVzLWVhc3QtMS5tYW51c2Nkbi5jb20vc2Vzc2lvbkZpbGUvNmQ2UG9kenZSamZOaE00Z3lxUGFtSS9zYW5kYm94L1l6cDRwTWNGNXk0RXlMZ3ZZRDA2M0staW1hZ2VzXzE3NzE2MjAwNzIxODBfbmExZm5fTDJodmJXVXZkV0oxYm5SMUwwMXdNeTFOYjJSMWJHVXRRVkJRTDIxd00xOXpkSEoxWTNSMWNtVS5wbmciLCJDb25kaXRpb24iOnsiRGF0ZUxlc3NUaGFuIjp7IkFXUzpFcG9jaFRpbWUiOjE3OTg3NjE2MDB9fX1dfQ__&Key-Pair-Id=K2HSFNDJXOU9YS&Signature=Evp9yGoT4jFZnSmaivEAfnCEVjY~iCigK0zqHPc~KeixmIWxg~2mLPur62FqigWOApPs7OipQu947lfMzBCZpIsQvmj2-52YdVCchkZAY4si9wotKJeErxKF0Mh3el1qPcs~SrIhft44g80pjQNnt6ZpAxSP0z1KqBT2agbqhRZ5S33XrYF8TzjFzZMtThmaEL6vI5-AWiUUBoLpgtRn~LCV3l9pbVFQi5lhp5DB-n2x1MTOomJixhn-H6cPIiXyvmn~8y5u62R0EtaoK8qgRYVlZNoS~DA2UcaEnOy2BbRdDimeMpvNHte8zYyBPRBRJMrHJ30Y11ArWHgqHuHkkQ__)

### 📂 Project Structure

| Directory / File | Description |
| :--- | :--- |
| `MCAL/` | Microcontroller Abstraction Layer (UART and DIO drivers). |
| `HAL/` | Hardware Abstraction Layer (MP3 Module logic and command formatting). |
| `Mp3_Module.h` | The main API interface containing the `Mp3_API` structure. |
| `DF Summary .txt` | Documentation of the MP3 module's serial protocol and naming rules. |
| `main.c` | Example application demonstrating how to use the library. |

---

## 💻 Technical Implementation

### **Command Frame Format**
The library automatically handles the construction of the 10-byte command frame required by the DFPlayer Mini:
- **Start Byte:** `0x7E`
- **Version:** `0xFF`
- **Length:** `0x06`
- **Command Code:** (e.g., `0x03` for Play)
- **Feedback:** (Enabled/Disabled)
- **Parameters:** (MSB & LSB)
- **Checksum:** Automatically calculated using the formula: `0xFFFF - (Sum of bytes) + 1`
- **End Byte:** `0xEF`

### **Example Usage**
```c
#include "Mp3_Module.h"

int main(void) {
    // Initialize UART and MP3 Module
    Mp3M0.Mp3Module_Init();
    
    // Play the first track
    Mp3M0.play(1);
    
    // Set volume to 20
    Mp3M0.Setvolume(20);
    
    while(1) {
        // Application logic
    }
}
```

---

## 🛠️ Requirements
- **Microcontroller:** ATmega32A (or compatible).
- **MP3 Module:** DFPlayer Mini.
- **Compiler:** AVR-GCC (Atmel Studio / Microchip Studio).
- **Hardware:** UART connection (TX to RX, RX to TX with 1k resistor recommended).

---

## 👤 Author
**Mohamed**
- GitHub: [@Mohamed662172](https://github.com/Mohamed662172)
