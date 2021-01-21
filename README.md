# HC-05_AT
HC-05 Bluetooth module AT mode configurator

## What is this?
Just a small Arduino application for configuring HC-05 Bluetoot module via serial console. It contain list of available commands and common usage patterns.

## Wiring
Pinout:
HC-05 **EN**  <-> Arduino **D9**
HC-05 **TXD** <-> Arduino **D10**
HC-05 **RXD** <-> Arduino **D11**
HC-05 **GND** <-> Arduino **GND**
HC-05 **VCC** <-> Arduino **5V**

<img src="assets/Schematic.png">

## Serial console configuration
In order to pass through commands from one serial interface to another, both newline and carriage return must be selected as newline characters.
<img src="assets/serial-console.png">
