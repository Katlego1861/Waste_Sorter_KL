# ♻️ Smart Waste Sorter using ESP32-CAM and Edge Impulse

This project is an **AI-powered waste sorting system** that uses an **ESP32-CAM** and **Edge Impulse** machine learning model to automatically identify and sort waste items such as **plastic**, **paper**, and **organic**.  
The system combines **AI**, **IoT**, and **robotics** to promote smarter and cleaner waste management.

---

##  Repository Structure

| Folder / File | Description |
|----------------|--------------|
| **CAD Design/** | Contains the 3D design files and mechanical components of the waste sorter. |
| **Images and Videos/** | Demonstration images and videos showing the system in action. |
| **Casing/** | 3D enclosure and casing design for the ESP32-CAM and sorting mechanism. |
| **AI/** | Contains all Edge Impulse documentation, training results, and AI process details. |
| **Circuit diagram.drawio** | Circuit diagram of the hardware setup, created using Draw.io. |
| **BOM.md** | Bill of Materials listing all electronic and mechanical components used. |
| **KL_Waste.ino** | Main Arduino code for the ESP32 and ESP32-CAM that controls the waste sorter. |

---

##  Artificial Intelligence (Edge Impulse Integration)

The AI model was created using **Edge Impulse** to classify waste materials into categories such as **plastic**, **paper**, **metal**, and **organic**.  

### Process Overview:
1. **Data Collection** – Images of different waste materials were captured using the ESP32-CAM and my phone.  
2. **Data Processing** – Images were resized and processed in Edge Impulse to extract features.  
3. **Model Training** – A MobileNetV2 (96x96) transfer learning model was trained and optimized.  
4. **Testing & Validation** – Model performance was measured (Precision: 0.65, Recall: 0.48, F1 Score: 0.55).  
5. **Deployment** – The trained model was exported as an Arduino library and deployed to the ESP32-CAM.  
6. **Integration** – The ESP32-CAM sends results via **ESP-NOW** to another ESP32 that controls servo motors to direct waste into the correct bin.

---

##  Hardware Setup

**Main Components:**
- ESP32-CAM (for AI image classification)  
- ESP32 (for servo and OLED control)  
- Servo Motors (for bin sorting mechanism)  
- OLED Display (status updates and classification results)  
- Power Supply  
- Custom 3D printed casing  

Refer to the **Circuit diagram.drawio** file for full wiring details.

---

## Software and Libraries

The following Arduino libraries are required:
```cpp
#include <WiFi.h>
#include <esp_now.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP32Servo.h>
#include <waste_sorter_inferencing.h>
