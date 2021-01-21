# HC-05_AT
HC-05 Bluetooth module AT mode configurator

## What is this?
Just a small Arduino application for configuring HC-05 Bluetoot module via serial console. It contain list of available commands and common usage patterns.

## How it works?
Very good, thanks for asking! It creates two serial interfaces and simply passes through commands from and to each other. First serial interface is default Arduino hardware serial interface (commonly accessed via USB), while for second we use SoftwareSerial.h library in order to emulate software serial interface (a.k.a bit-banging) and attach it to HC-05 Bluetoot module.

## Wiring
**Default pinout (tested):**  
HC-05 **EN**  <-> Arduino **D9**  
HC-05 **TXD** <-> Arduino **D10**  
HC-05 **RXD** <-> Arduino **D11**  
HC-05 **GND** <-> Arduino **GND**  
HC-05 **VCC** <-> Arduino **5V**  

For more details, refer to this diagram:  
<img src="assets/Schematic.png">

## Serial console configuration
**In order to pass through commands from one serial interface to another, both newline and carriage return must be selected as newline characters.** For more details, check out picture below:  

<img src="assets/serial-console.png">
