
---

# don't touch my desk

so basically i built a radar system that watches my desk and locks my pc if someone gets too close. it uses an arduino, a servo motor, and an ultrasonic sensor to scan the area, shows the radar on my pc screen in real time, and runs a python script in the background that auto-locks windows the second something breaches the perimeter.

three separate programs working together. pretty cool ngl.

## what it does

- the servo sweeps the ultrasonic sensor left and right across about 150° (kept it between 15°–165° so the servo doesn't grind itself to death)
- three alert levels:
  - green = all clear, nothing within 80cm
  - yellow = something's getting close (40–80cm), yellow led turns on and it beeps once
  - red = breach, something's under 40cm, red led + continuous alarm + pc locks
- has a 3-strike system so it doesn't freak out over random noise or a wire reflection
- after an alarm it stays latched for 15 seconds then resets and goes back to scanning
- processing app shows the radar sweep live and plots dots where it detects stuff
- python script watches the serial data and calls the windows lock command the moment a breach is confirmed

## stuff you need

**hardware**
- arduino uno (or basically any compatible board)
- sg90 servo motor
- hc-sr04 ultrasonic sensor
- green, yellow, and red leds
- piezo buzzer
- breadboard + jumper wires

**software**
- arduino ide — for uploading the firmware
- processing — for the radar visualizer
- python 3 + pyserial — for the lockdown script

## how to set it up

**step 1 — arduino**

wire everything up using the pin numbers in the code (trig: 4, echo: 8, servo: 3). open the arduino ide, upload the code, done. if your servo makes a grinding noise at the end of its sweep just tweak the `map()` bounds slightly.

**step 2 — processing radar**

open the radar code in processing. find this line:

```
myPort = new Serial(this, "COM6", 9600);
```

change COM6 to whatever port your arduino is actually on. close the arduino serial monitor first or it won't connect. then just hit run.

**step 3 — python lockdown**

```
pip install pyserial
```

open the python script and make sure `arduino_port` matches your com port. run it in the background and it'll watch the serial stream. if anything crosses the 40cm line your pc locks instantly.

## important thing about serial ports

the arduino can only talk to one program at a time over usb. so you can't have the serial monitor, processing, AND the python script all running at once. pick one or the other. i usually just run processing + python together and leave the serial monitor closed.

## credits

used ai for debugging some of the trickier bits. everything else is mine.

---

