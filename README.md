#  Desktop Proximity Alarm

*A simple Arduino-based security alarm that helps protect my desk and workspace from unwanted visitors.*

---

##  About The Project

I built the **Desktop Proximity Alarm** as a hardware project for the Hack Club Horizons program. The idea came from wanting a simple way to know if someone gets too close to my desk when I'm away.

The alarm uses an ultrasonic sensor to continuously measure distance. Depending on how close someone gets, the system reacts differently. First, it gives a visual warning using LEDs, and if someone comes even closer, it activates a loud alarm using a buzzer.

One feature I'm particularly proud of is that once the alarm is triggered, it stays on even if the person moves away. The only way to turn it off is by pressing the reset button.

This project helped me learn more about Arduino programming, sensors, electronic circuits, and state-based logic.

---

##  Features

*  Measures distance using an HC-SR04 ultrasonic sensor
*  Green LED indicates everything is safe
*  Yellow LED warns when someone is getting close
*  Red LED and buzzer activate when the protected area is breached
*  Alarm stays active once triggered
*  Physical reset button to disable the alarm
*  Serial Monitor output for live distance readings

---

##  Components Used

| Component                 | Quantity |
| ------------------------- | -------- |
| Arduino Uno R3            | 1        |
| HC-SR04 Ultrasonic Sensor | 1        |
| Piezo Buzzer              | 1        |
| Green LED                 | 1        |
| Yellow LED                | 1        |
| Red LED                   | 1        |
| 220Ω Resistors            | 3        |
| 10kΩ Resistor             | 1        |
| Push Button               | 1        |
| Breadboard & Jumper Wires | Several  |

---

##  Wiring

### HC-SR04

* TRIG → Pin 9
* ECHO → Pin 10

### LEDs

* Green LED → Pin 5
* Yellow LED → Pin 6
* Red LED → Pin 7

### Buzzer

* Positive Pin → Pin 11

### Reset Button

* Signal Pin → Pin 2

---

##  How It Works

The ultrasonic sensor constantly measures the distance between the sensor and any object in front of it.

### Safe Zone

If nothing is nearby, the green LED stays on.

### Warning Zone

When someone gets closer, the yellow LED turns on to indicate a potential intrusion.

### Alarm Zone

If the object enters the critical distance range:

* The red LED turns on
* The buzzer starts sounding
* The alarm becomes locked

Even if the person moves away afterward, the alarm continues until the reset button is pressed.

---

##  What I Learned

While building this project, I learned:

* How ultrasonic distance sensors work
* How to calculate distance using sound waves
* Arduino programming and debugging
* Using LEDs and buzzers for feedback
* Working with buttons and pull-down resistors
* Designing systems using state-based logic

This project was a great introduction to combining hardware and software to create something practical.

---

##  Setup

1. Assemble the circuit on a breadboard.
2. Connect the Arduino to your computer.
3. Open the Arduino IDE.
4. Upload the code to the Arduino Uno.
5. Open the Serial Monitor at 9600 baud.
6. Test the sensor and adjust distance thresholds if needed.

---

##  Future Improvements

Some upgrades I'd like to add in the future:

* OLED display for status information
* Rechargeable battery power
* Wi-Fi notifications to a phone
* Adjustable sensitivity settings
* Custom 3D-printed enclosure

---

##  Author

**Krishang Gupta**

Built as part of my Hack Club Horizons journey to learn more about electronics, embedded systems, and hardware development.
