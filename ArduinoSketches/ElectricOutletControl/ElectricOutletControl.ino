

// Help taken there : http://www.instructables.com/id/Arduino-433Mhz-Wireless-Communication-Rc-Switch/

#include <RCSwitch.h> // Needs RC-Switch library, can be found there : https://github.com/sui77/rc-switch

RCSwitch mySwitch = RCSwitch();

// DIP switches configuration
char *firstDIPSwitches = "10000";
char *lastDIPSwitches = "00010";


/**
 * Aux function to read commands (separated by a ";") on the serial stream.
 */
void executeCommandSerial(void (*commandHandler)(String)) {
  String stream = Serial.readString();
  if (stream != NULL) {
    int separator = stream.indexOf(';');
    int commandStart = 0;
    while (separator != -1) {
      (*commandHandler)(stream.substring(commandStart, separator));
      commandStart = separator + 1;
      separator = stream.indexOf(';', commandStart);
    }
  }
}


void setup() {
  Serial.begin(9600);

  // Transmitter on pin 10
  mySwitch.enableTransmit(10);

  mySwitch.switchOff(firstDIPSwitches,lastDIPSwitches);

}

void loop() {
  executeCommandSerial(commandHandler);
}


void commandHandler(String command){
  if (command == "ON"){
    mySwitch.switchOn(firstDIPSwitches,lastDIPSwitches);
    Serial.println("On !");
    delay(10);    // To give time for radio transmission
  } else if (command == "OFF"){
    mySwitch.switchOff(firstDIPSwitches,lastDIPSwitches);
    Serial.println("Off !");
    delay(10);    // To give time for radio transmission
  } else if (command == "WAIT"){    // Useless : only to test
    Serial.println("Waiting 2 seconds...");
    delay(2000);
  }
}

