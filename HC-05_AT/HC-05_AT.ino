#include <SoftwareSerial.h>

#define HC_RX 10
#define HC_TX 11

SoftwareSerial BTSerial(HC_RX, HC_TX);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(38400);
  help();
}

void loop() {
  if (BTSerial.available()) Serial.write(BTSerial.read());
}

void SerialEvent () {
  BTSerial.write(Serial.read());
}

void help() {
  Serial.println("AT (Enter AT mode)");
  Serial.println("AT+RESET (Reset)");
  Serial.println("AT+VERSION? (Print Bluetooth module firmware info");
  Serial.println("AT+ORGL (Restore default settings)");
  Serial.println("AT+ADDR? (Print address of Bluetooth module)");
  Serial.println("AT+NAME? (Print Bluetooth device name)");
  Serial.println("AT+NAME=<Param> (Set new Bluetooth device name");
  
  Serial.println("AT+ROLE? (Print curret Bluetooth device role");
  
  Serial.println("Enter AT command:");
}
