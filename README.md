# 🏠 ESP32-Based Smart Home Automation

A web-based home automation system built using **ESP32** that allows users to control electrical appliances remotely through a web interface over Wi-Fi.

## 📌 Project Overview

This project demonstrates a simple and practical **IoT-based home automation system** using an ESP32 microcontroller.

The ESP32 connects to a Wi-Fi network and runs a web server. Users can control connected devices such as lights and other appliances through a web-based dashboard.

The system uses a **relay module** to control physical electrical loads while providing real-time ON/OFF control through the webpage.

## 🎯 Objectives

* Control home appliances through a web interface.
* Establish wireless communication between a webpage and ESP32.
* Use a relay module to control physical loads.
* Demonstrate the practical application of IoT in home automation.
* Develop a simple and user-friendly smart home dashboard.

## ⚙️ Features

* 🌐 Wi-Fi-based control
* 💡 Light ON/OFF control
* ⚡ Relay-based appliance control
* 🖥️ Web-based dashboard
* 📡 ESP32 web server
* 🔄 Real-time device control
* 📊 Device status and ON-device count
* 🔌 Expandable for additional appliances

## 🧰 Hardware Components

| Component          |    Quantity |
| ------------------ | ----------: |
| ESP32 WROOM-32     |           1 |
| Relay Module       |           1 |
| LED / Light Load   | As required |
| Jumper Wires       | As required |
| Breadboard         |           1 |
| USB Cable          |           1 |
| Bulb Holder / Load | As required |

> **Safety:** For initial testing and demonstration, low-voltage loads are recommended. Mains-powered AC loads should only be handled with appropriate electrical safety precautions and supervision.

## 💻 Software & Technologies

* **Arduino IDE**
* **C/C++**
* **ESP32 Wi-Fi Library**
* **WebServer Library**
* **HTML**
* **CSS**
* **JavaScript**

## 🔌 System Architecture

```text
        Web Dashboard
              │
              │ Wi-Fi
              ▼
        ┌─────────────┐
        │    ESP32    │
        │ Web Server  │
        └──────┬──────┘
               │
          GPIO Control
               │
               ▼
        ┌─────────────┐
        │    Relay    │
        └──────┬──────┘
               │
               ▼
        Electrical Load
       (Light / Appliance)
```

## 🔄 Working Principle

1. The ESP32 connects to the available Wi-Fi network.
2. The ESP32 obtains an IP address and starts a web server.
3. The user opens the smart home dashboard in a browser.
4. When an ON/OFF button is pressed, the webpage sends a request to the ESP32.
5. The ESP32 processes the request and changes the corresponding GPIO state.
6. For relay-controlled devices, GPIO 23 controls the relay module.
7. The relay switches the connected load ON or OFF.

## 📍 Current Pin Configuration

| Device  | ESP32 Pin | Function       |
| ------- | --------: | -------------- |
| Light 1 |    GPIO 2 | Digital output |
| Relay   |   GPIO 23 | Relay control  |

### Relay Logic

The relay used in the prototype is **active LOW**:

```text
GPIO 23 → LOW  → Relay ON
GPIO 23 → HIGH → Relay OFF
```

## 🌐 Web Interface

The dashboard provides controls for:

* Light 1
* Light 2
* Fan
* Appliance
* All devices ON
* All devices OFF

The webpage communicates directly with the ESP32 through HTTP requests.

Example:

```text
http://ESP32_IP/relay/on
```

turns the relay ON.

```text
http://ESP32_IP/relay/off
```

turns the relay OFF.

## 📁 Project Structure

```text
ESP32-Home-Automation/
│
├── Arduino/
│   └── home_automation.ino
│
├── Web/
│   ├── index.html
│   ├── style.css
│   └── script.js
│
└── README.md
```

## 🚀 Getting Started

### 1. Upload the ESP32 Code

Open the Arduino sketch in Arduino IDE.

Select:

```text
Board: ESP32 Dev Module
Port: COM5
```

Upload the code to the ESP32.

### 2. Connect to Wi-Fi

The ESP32 connects to the configured Wi-Fi network and displays its IP address through the Serial Monitor.

Example:

```text
Wi-Fi connected!
ESP32 IP address: 192.168.15.128
Web server started!
```

### 3. Run the Web Dashboard

Open the web project and make sure the ESP32 IP address in `script.js` matches the current IP address of the ESP32.

Example:

```javascript
const ESP32_IP = "192.168.15.128";
```

### 4. Control the Devices

Use the dashboard buttons to turn the connected devices ON or OFF.

## 🔮 Future Improvements

* Static IP configuration
* Multiple relay channels
* Mobile-responsive interface
* Device scheduling
* Timer-based automation
* Energy consumption monitoring
* User authentication
* Voice control
* Mobile application
* Sensor-based automation
* Real-time device monitoring

## 🎓 Project Type

**Academic / IoT Mini Project**

### Developed Using

**ESP32 + Wi-Fi + Web Technologies + Relay-Based Control**

---

## 👨‍💻 Project Contributors

**Riddhi Saurana**
B.Tech Electrical Engineering
GBPIET, Uttarakhand

---

## ⭐ Conclusion

The ESP32-Based Smart Home Automation system demonstrates how a microcontroller, Wi-Fi connectivity, web technologies, and relay-based switching can be integrated to create a simple IoT-enabled home automation solution.

The project provides a foundation that can be expanded into a more advanced smart home system with multiple devices, scheduling, sensors, energy monitoring, and mobile or voice-based control.
