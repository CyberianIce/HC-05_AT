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
  Serial.println(F("###############"));
  Serial.println(F("# DEVICE INFO #"));
  Serial.println(F("###############"));
  Serial.println(F("AT (Enter AT mode, Bluetooth module should return OK)"));
  Serial.println(F("AT+VERSION? (Print Bluetooth module firmware info)\n"));
  Serial.println(F("AT+ADDR? (Print Bluetooth module address)\n"));
  Serial.println(F("####################"));
  Serial.println(F("# RESTORE DEFAULTS #"));
  Serial.println(F("####################"));
  Serial.println(F("AT+RESET (Reset Bluetooth device with current settings)"));
  Serial.println(F("AT+ORGL (Restore Bluetooth device default settings)\n"));
  Serial.println(F("##################"));
  Serial.println(F("# BLUETOOTH NAME #"));
  Serial.println(F("##################"));
  Serial.println(F("AT+NAME? (Print Bluetooth device name)"));
  Serial.println(F("AT+NAME=<Param> (Set new Bluetooth device name)\n"));
  Serial.println(F("############"));
  Serial.println(F("# PIN CODE #"));
  Serial.println(F("############"));
  Serial.println(F("AT+PSWD? (Print curret Bluetooth device pairing PIN code)"));
  Serial.println(F("AT+PSWD=<Param> (Set new Bluetooth device pairing PIN code)\n"));
  Serial.println(F("###############"));
  Serial.println(F("# DEVICE ROLE #"));
  Serial.println(F("###############"));
  Serial.println(F("AT+ROLE? (Print curret Bluetooth device role)"));
  Serial.println(F("AT+ROLE=<Param> (Change Bluetooth device role. <Param>: 0 for Slave, 1 for Master or 2 for Slave-loop)\n"));
  Serial.println(F("################"));
  Serial.println(F("# DEVICE CLASS #"));
  Serial.println(F("################"));
  Serial.println(F("AT+CLASS? (Print curret Bluetooth device class)"));
  Serial.println(F("AT+CLASS=<Param> (Set Bluetooth device class)\n"));
  Serial.println(F("###############"));
  Serial.println(F("# DEVICE GIAC #"));
  Serial.println(F("###############"));
  Serial.println(F("AT+IAC? (Print curret Bluetooth device Gerneral Inquiry Access Code)"));
  Serial.println(F("AT+IAC=<Param> (Set new Bluetooth device Gerneral Inquiry Access Code)\n"));
  Serial.println(F("####################"));
  Serial.println(F("# SERIAL INTERFACE #"));
  Serial.println(F("####################"));
  Serial.println(F("AT+UART? (Print current Bluetooth device serial porot configuration)"));
  Serial.println(F("AT+UART=<Param1>,<Param2>,<Param3> (Set Bluetooth device Gerneral serial parameters. <Param1> - boud rate, <Param2> - stop bit and <Param3> - parity. Example: AT+UART=115200,0,1)\n"));
  Serial.println(F("################"));
  Serial.println(F("# CONNECT MODE #"));
  Serial.println(F("################"));
  Serial.println(F("AT+CMODE? (Print curret Bluetooth device current connect mode)"));
  Serial.println(F("AT+CMODE=<Param> (Set Bluetooth device connect mode. Params: 0 for fixed address, 1 for any address or 2 for slave-loop)\n"));
  Serial.println(F("#################"));
  Serial.println(F("# FIXED ADDRESS #"));
  Serial.println(F("#################"));
  Serial.println(F("AT+BIND? (Print curret Bluetooth device fixed address)"));
  Serial.println(F("AT+BIND=<Param> (Set new Bluetooth device fixed address)\n"));
  Serial.println(F("##############"));
  Serial.println(F("# STATUS LED #"));
  Serial.println(F("##############"));
  Serial.println(F("AT+POLAR=<Param1>,<Param2> (Set Bluetooth device LED I/O. <Param1> for PIO8, <Param2> for PIO9 (0 for LOW, 1 for HIGH drive state). Both parameters are required)"));
  Serial.println(F("AT+PIO=<Param1>,<Param2> (Set Bluetooth device PIO output. <Param1> is PIO number and <Param2> is PIO state (0 for LOW, 1 for HIGH). Both parameters are required)\n"));
  Serial.println(F("###################"));
  Serial.println(F("# SCAN PARAMETERS #"));
  Serial.println(F("###################"));
  Serial.println(F("AT+IPSCAN? (Display Bluetooth device current scan parameters)"));
  Serial.println(F("AT+IPSCAN=<Param1>,<Param2>,<Param3>,<Param4> (Set Bluetooth device scan parameter. <Param1> is query time interval, <Param2> is query duration, <Param3> is paging interval, <Param4> is call duration)\n"));
  Serial.println(F("#########"));
  Serial.println(F("# SNIFF #"));
  Serial.println(F("#########"));
  Serial.println(F("AT+SNIFF? (Print curret Bluetooth device sniff parameters)"));
  Serial.println(F("AT+SNIFF=<Param1>,<Param2>,<Param3>,<Param4> (Set Bluetooth device sniff parameter. <Param1> is max time, <Param2> is min time, <Param3> is retry time, <Param4> is timeout)\n"));
  Serial.println(F("#################"));
  Serial.println(F("# SECURITY MODE #"));
  Serial.println(F("#################"));
  Serial.println(F("AT+SENM? (Display Bluetooth device current security mode)"));
  Serial.println(F("AT+SENM=<Param1>,<Param2> (Set Bluetooth device security mode. <Param1> 0 for sec_mode0+off, 1 for sec_mode1+non_secure, 2 for sec_mode2_service, 3 for sec_mode3_link, 4 for sec_mode_unknown, <Param2> 0 for hci_enc_mode_off, 1 for hci_enc_mode_pt_to_pt, 2 for hci_enc_mode_pt_to_pt_and_bcast)\n"));
  Serial.println(F("##################"));
  Serial.println(F("# PAIRED DEVICES #"));
  Serial.println(F("##################"));
  Serial.println(F("AT+ADCN? (Display number of authenticated devices)"));
  Serial.println(F("AT+MRAD? (Display most recent authenticated device address)"));
  Serial.println(F("AT+FSAD=<Param> (Search for authenticated device. <Param> is authenticated device address)"));
  Serial.println(F("AT+PMSAD=<Param> (Delete authenticated device. <Param> is authenticated device address"));
  Serial.println(F("AT+RMAAD (Delete all authenticated devices\n"));
  Serial.println(F("#################"));
  Serial.println(F("# DEVICE STATEE #"));
  Serial.println(F("#################"));
  Serial.println(F("AT+STATE? (Display Bluetooth device working state)"));
  Serial.println(F("AT+INIT (Initialize the SPP profile lib)\n"));
  Serial.println(F("##################"));
  Serial.println(F("# DEVICE INQUIRY #"));
  Serial.println(F("##################"));
  Serial.println(F("AT+INQ (Inquiry Bluetooth device - returns address, class and signal strength)"));
  Serial.println(F("AT+INQC (Cancel inquiring Bluetooth device)\n"));
  Serial.println(F("################"));
  Serial.println(F("# CONNECT/PAIR #"));
  Serial.println(F("################"));
  Serial.println(F("AT+PAIR=<Param1>,<Param2> (Equipment matching: <Param1> is device address, <Param2> is timeout)"));
  Serial.println(F("AT+LINK=<Param> (Connect device: <Param> device address)"));
  Serial.println(F("AT+DISC (Disconnect Bluetooth device)\n"));
  Serial.println(F("#################"));
  Serial.println(F("# ENERGY SAVING #"));
  Serial.println(F("#################"));
  Serial.println(F("AT+ENSNIFF=<Param> (Enable energy saving mode: <Param> is device address)"));
  Serial.println(F("AT+EXSNIFF=<Param> (Enable extended energy saving mode: <Param> is device address)\n"));
  Serial.println(F("Enter AT command:"));
}
