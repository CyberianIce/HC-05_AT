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
  Serial.println(F("\n"
  "##############################################################\n"
  "#                                                            #\n"
  "#                        W A R N I N G                       #\n"
  "#                                                            #\n"
  "#   EN pin on HC-05 must be set to HIGH before powering on!  #\n"
  "#   Do not forget to set Both NL & CR for end of line char!  #\n"
  "#                                                            #\n"
  "##############################################################\n"));
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
  Serial.println(F(
  "###############\n"
  "# DEVICE INFO #\n"
  "###############\n"
  "AT (Enter AT mode, Bluetooth module should return OK)\n"
  "AT+VERSION? (Print Bluetooth module firmware info)\n\n"
  "AT+ADDR? (Print Bluetooth module address)\n\n"
  "####################\n"
  "# RESTORE DEFAULTS #\n"
  "####################\n"
  "AT+RESET (Reset Bluetooth device with current settings)\n"
  "AT+ORGL (Restore Bluetooth device default settings)\n\n"
  "##################\n"
  "# BLUETOOTH NAME #\n"
  "##################\n"
  "AT+NAME? (Print Bluetooth device name)\n"
  "AT+NAME=<Param> (Set new Bluetooth device name)\n\n"
  "############\n"
  "# PIN CODE #\n"
  "############\n"
  "AT+PSWD? (Print curret Bluetooth device pairing PIN code)\n"
  "AT+PSWD=<Param> (Set new Bluetooth device pairing PIN code)\n\n"
  "###############\n"
  "# DEVICE ROLE #\n"
  "###############\n"
  "AT+ROLE? (Print curret Bluetooth device role)\n"
  "AT+ROLE=<Param> (Change Bluetooth device role. <Param>: 0 for Slave, 1 for Master or 2 for Slave-loop)\n\n"
  "################\n"
  "# DEVICE CLASS #\n"
  "################\n"
  "AT+CLASS? (Print curret Bluetooth device class)\n"
  "AT+CLASS=<Param> (Set Bluetooth device class)\n\n"
  "###############\n"
  "# DEVICE GIAC #\n"
  "###############\n"
  "AT+IAC? (Print curret Bluetooth device Gerneral Inquiry Access Code)\n"
  "AT+IAC=<Param> (Set new Bluetooth device Gerneral Inquiry Access Code)\n\n"
  "####################\n"
  "# SERIAL INTERFACE #\n"
  "####################\n"
  "AT+UART? (Print current Bluetooth device serial porot configuration)\n"
  "AT+UART=<Param1>,<Param2>,<Param3> (Set Bluetooth device Gerneral serial parameters. <Param1> - boud rate, <Param2> - stop bit and <Param3> - parity. Example: AT+UART=115200,0,1)\n\n"
  "################\n"
  "# CONNECT MODE #\n"
  "################\n"
  "AT+CMODE? (Print curret Bluetooth device current connect mode)\n"
  "AT+CMODE=<Param> (Set Bluetooth device connect mode. Params: 0 for fixed address, 1 for any address or 2 for slave-loop)\n\n"
  "#################\n"
  "# FIXED ADDRESS #\n"
  "#################\n"
  "AT+BIND? (Print curret Bluetooth device fixed address)\n"
  "AT+BIND=<Param> (Set new Bluetooth device fixed address)\n\n"
  "##############\n"
  "# STATUS LED #\n"
  "##############\n"
  "AT+POLAR=<Param1>,<Param2> (Set Bluetooth device LED I/O. <Param1> for PIO8, <Param2> for PIO9 (0 for LOW, 1 for HIGH drive state). Both parameters are required)\n"
  "AT+PIO=<Param1>,<Param2> (Set Bluetooth device PIO output. <Param1> is PIO number and <Param2> is PIO state (0 for LOW, 1 for HIGH). Both parameters are required)\n\n"
  "###################\n"
  "# SCAN PARAMETERS #\n"
  "###################\n"
  "AT+IPSCAN? (Display Bluetooth device current scan parameters)\n"
  "AT+IPSCAN=<Param1>,<Param2>,<Param3>,<Param4> (Set Bluetooth device scan parameter. <Param1> is query time interval, <Param2> is query duration, <Param3> is paging interval, <Param4> is call duration)\n\n"
  "#########\n"
  "# SNIFF #\n"
  "#########\n"
  "AT+SNIFF? (Print curret Bluetooth device sniff parameters)\n"
  "AT+SNIFF=<Param1>,<Param2>,<Param3>,<Param4> (Set Bluetooth device sniff parameter. <Param1> is max time, <Param2> is min time, <Param3> is retry time, <Param4> is timeout)\n\n"
  "#################\n"
  "# SECURITY MODE #\n"
  "#################\n"
  "AT+SENM? (Display Bluetooth device current security mode)\n"
  "AT+SENM=<Param1>,<Param2> (Set Bluetooth device security mode. <Param1> 0 for sec_mode0+off, 1 for sec_mode1+non_secure, 2 for sec_mode2_service, 3 for sec_mode3_link, 4 for sec_mode_unknown, <Param2> 0 for hci_enc_mode_off, 1 for hci_enc_mode_pt_to_pt, 2 for hci_enc_mode_pt_to_pt_and_bcast)\n\n"
  "##################\n"
  "# PAIRED DEVICES #\n"
  "##################\n"
  "AT+ADCN? (Display number of authenticated devices)\n"
  "AT+MRAD? (Display most recent authenticated device address)\n"
  "AT+FSAD=<Param> (Search for authenticated device. <Param> is authenticated device address)\n"
  "AT+PMSAD=<Param> (Delete authenticated device. <Param> is authenticated device address\n"
  "AT+RMAAD (Delete all authenticated devices\n\n"
  "#################\n"
  "# DEVICE STATEE #\n"
  "#################\n"
  "AT+STATE? (Display Bluetooth device working state)\n"
  "AT+INIT (Initialize the SPP profile lib)\n\n"
  "##################\n"
  "# DEVICE INQUIRY #\n"
  "##################\n"
  "AT+INQ (Inquiry Bluetooth device - returns address, class and signal strength)\n"
  "AT+INQC (Cancel inquiring Bluetooth device)\n\n"
  "################\n"
  "# CONNECT/PAIR #\n"
  "################\n"
  "AT+PAIR=<Param1>,<Param2> (Equipment matching: <Param1> is device address, <Param2> is timeout)\n"
  "AT+LINK=<Param> (Connect device: <Param> device address)\n"
  "AT+DISC (Disconnect Bluetooth device)\n\n"
  "#################\n"
  "# ENERGY SAVING #\n"
  "#################\n"
  "AT+ENSNIFF=<Param> (Enable energy saving mode: <Param> is device address)\n"
  "AT+EXSNIFF=<Param> (Enable extended energy saving mode: <Param> is device address)\n\n"
  "Enter AT command:"));
}
