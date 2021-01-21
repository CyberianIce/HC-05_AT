#include <SoftwareSerial.h>

/**
 * CONFIGURATION
 * On Uno/Mega only interrupt capable pins can be used (designated with tilda symbol ~)
 */
#define HC_ENABLE 9 // Connect pin 9 from Arduino to pin ENABLE on HC-05
#define HC_TX 10 // Connect pin 10 from Arduino to pin TX on HC-05
#define HC_RX 11 // Connect pin 11 from Arduino to pin RX on HC-05


/**
 * Do not modify anything below this line 
 * Serial interfaces initialisation and start HC-05 in AT mode
 */
SoftwareSerial BTSerial(HC_TX, HC_RX); // TX & RX are inversed here on purpose to avoid confusion when wiring
String hlpCmd = "";

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50);
  Serial.println(F("\n##############################################################\n#   Do not forget to set Both NL & CR for end of line char   #\n##############################################################\n"));
  help();
  pinMode(HC_ENABLE, OUTPUT);
  digitalWrite(HC_ENABLE, HIGH); // Enter AT mode
  BTSerial.begin(38400); // HC-05 default baud rate in AT mode is 38400
}

/**
 * Print response from HC-05 in console terminal (if any)
 */
void loop() {
  if (BTSerial.available()) Serial.write(BTSerial.read());
}

/**
 * Parse commands from serial console and pass to HC-05 (byte-literal)
 */
void serialEvent() {
  BTSerial.write(Serial.read());
}

/**
 * Print available AT commands
 */
void help() {
  Serial.println(F("AT (Enter AT mode, Bluetooth module should return OK)"));
  Serial.println(F("AT+VERSION? (Print Bluetooth module firmware info\n"));
    
  Serial.println(F("AT+RESET (Reset)"));
  Serial.println(F("AT+ORGL (Restore default settings)\n"));
  
  Serial.println(F("AT+ADDR? (Print address of Bluetooth module)\n"));
  
  Serial.println(F("AT+NAME? (Print Bluetooth device name)"));
  Serial.println(F("AT+NAME=<Param> (Set new Bluetooth device name\n"));

  Serial.println(F("AT+PSWD? (Print curret Bluetooth device pairing PIN code"));
  Serial.println(F("AT+PSWD=<Param> (Set new Bluetooth device pairing PIN code.\n"));
  
  Serial.println(F("AT+ROLE? (Print curret Bluetooth device role"));
  Serial.println(F("AT+ROLE=<Param> (Change Bluetooth device role. Params: 0 for Slave, 1 for Master or 2 for Slave-loop)\n"));
    
  Serial.println(F("AT+CLASS? (Print curret Bluetooth device class"));
  Serial.println(F("AT+CLASS=<Param> (Set Bluetooth device class.\n"));

  Serial.println(F("AT+IAC? (Print curret Bluetooth device Gerneral Inquiry Access Code"));
  Serial.println(F("AT+IAC=<Param> (Set Bluetooth device Gerneral Inquiry Access Code.\n"));

  Serial.println(F("AT+UART? (Print current Bluetooth device serial porot configuration."));
  Serial.println(F("AT+UART=<Param1>,<Param2>,<Param3> (Set Bluetooth device Gerneral serial parameters. Param1 - boud rate, Param2 - stop bit and Param3 - parity. Example: AT+UART=115200,0,1\n"));

  Serial.println(F("AT+CMODE? (Print curret Bluetooth device Gerneral Inquiry Access Code"));
  Serial.println(F("AT+CMODE=<Param> (Set Bluetooth device connect mode. Params: 0 for fixed address, 1 for any address or 2 for slave-loop\n"));
  
  Serial.println(F("Enter AT command:"));
}
