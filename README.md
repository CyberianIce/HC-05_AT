# HC-05_AT
HC-05 Bluetooth module AT mode configurator for Arduino (Nano/Uno/Mega)

## What is this?
Small Arduino serial console application for configuring HC-05 Bluetoot module via serial console. It contain list of available AT commands and common usage patterns. It's manily used to change default HC-05 Bluetooth name, PIN code, operation mode, etc.

### What is AT mode?
In order to change default configuration parameters of your Bluetooth module (such as device name, PIN code, ...) You need to put your device in AT mode first. This can be done in one of following two ways:  
1. Setting EN pin on HC-05 module to HIGH while powering on HC-05.
2. Some HC-05 modules are equipped with small hardware button (next to EN pin). If Your device is equipped with one, all you need to do in order to enter AT mode is to keep this button pressed while powering on HC-05 module.

***Notice***  
*EN pin must be set to HIGH before HC-05 is supplied with power.*

### How do I know if I am in AT mode?
Once you successfully enter AT mode, your HC-05 LED will start blinking very slowly (with 3 second interval)

### How it works?
Very good, thanks for asking! It creates two serial interfaces and simply passes through commands from and to each other. First serial interface is default Arduino hardware serial interface (commonly accessed via USB), while for second we use SoftwareSerial.h library in order to emulate software serial interface (a.k.a bit-banging) and attach it to HC-05 Bluetoot module.

## Wiring
**Default pinout (tested):**  
<img src="assets/Schematic.png">

Legend:  
HC-05 **EN_** <-> Arduino **D9**  
HC-05 **TXD** <-> Arduino **D10**  
HC-05 **RXD** <-> Arduino **D11**  
HC-05 **GND** <-> Arduino **GND**  
HC-05 **VCC** <-> Arduino **5V**  

***Notice***  
*As mentioned above, in order to boot in AT mode, EN pin on HC-05 must be supplied with +5V **BEFORE** HC-05 is supplied with power. One can achieve this in multiple ways:*  
- *Placing simple switch or momentary button between HC-05 VCC and Arduino +5V which must be pressed after arduino is booted (after signal HIGH is sent from D9 to EN)*
- *Connecting HC-05 VCC after arduino is powered on and ready*
- *Or you may even wire everything like pictured above, and shortly disconnect HC-05 VCC and reconnect it back after Arduino is booted.*

## Serial console configuration
**In order to pass through commands from one serial interface to another, both newline and carriage return must be selected as newline characters.** For more details, check out picture below:  

<img src="assets/serial-console.png">

## AT command list
*Need description*  
Once you upload this scatch to Arduino and open serial port monitor, list of common AT command with typical usage pattern will be displayed.
