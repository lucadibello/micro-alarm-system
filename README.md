# Micro Alarm System

## Introduction

Micro Alarm System is a simple alarm system implemented via the Basys MX 3 microcontroller. This All-In-One alarm system will emit a high-pitched sound that is easily audible from several meters away, allowing you to notify everyone present of a possible theft/any illegal operation that involves moving the object on which the following system has been mounted. This displacement control is performed by a small accelerometer.
Micro Alarm System has infinite uses: for example if attached to an object it can notify people in the immediate vicinity of its illicit movement. Otherwise, if attached to the inside of a door, it can notify its opening.

![Basys MX3 Microcontroller](/assets/MicrocontrollerSchema.png)

### Getting started

The device is equipped with a UART serial port to operate on the alarm system. Therefore, in order to use it, it needs to be connected to a device that supports serial communication via USB. The device will show the following splashscreen once the power on procedure is completed:

![Micro-Alarm-System splashscreen](/assets/MicroAlarmSystem-splashscreen.png)

Now, if the BTNC button is pressed, you are prompted to enter the access code. The code is set to "0000" by default.
Once authenticated, the system is unlocked and then the menu to operate it is shown:

![Basys MX3 Microcontroller](/assets/MicroAlarmSystem-Menu.png)

Note: for security reasons it is advisable to change the password as a first operation.
Through a led it is possible to see quickly if the alarm system is active or not. If the led is red, it means that the system is on (connected to the power supply) but it is not active, so it does not listen to any movement. Otherwise, if the system is active, the led turns blue:

| System not activated       |  System activated |
:-------------------------:|:-------------------------:
![Security system not activated](/assets/MicroAlarmSystem-NotActive.jpg)  | ![Security system activated](/assets/MicroAlarmSystem-Active.jpg)

## Features

Micro Alarm System offers the following features:

- Alarm system activation/deactivation and movement monitoring
- Detection and recording of intrusion via logs
- Display and deletion of logs saved by the system
- Change security code with a personal one, up to 254 characters long

## Overview of system operation

The following flowchart illustrates the functionality of the system. In the diagram are not shown the functions related to the inactivity times. In fact, if the system remains inactive for 5 seconds, it is logged out and it will be necessary again to insert the password correctly in order to continue to interact.
For each action a log message is saved with the respective date and time so that it is possible to reconstruct the history of the actions performed since the program start or since the deletion of the log. For convenience and to make the scheme cleaner and more understandable.

![Micro-Alarm-System flowchart](/assets/MicroAlarmSystem-flowchart.png)
