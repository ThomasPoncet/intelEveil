



//void loop() {
//
//    for (int i = 0; i < 3; i++) {
//      irsend.sendNEC(0xFDB04F, 32);
//      delay(40);
//    }
//  delay(5000);
//}

// Help taken there : http://www.instructables.com/id/Arduino-433Mhz-Wireless-Communication-Rc-Switch/

#include <RCSwitch.h> // Needs RC-Switch library, can be found there : https://github.com/sui77/rc-switch
#include <IRremote.h> // Needs IRremote library, can be found there : https://github.com/z3t0/Arduino-IRremote

RCSwitch mySwitch = RCSwitch();
IRsend irsend;

// Used pins
int transmitterPin = 10;

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

  mySwitch.enableTransmit(transmitterPin);

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
  } else if (command == "TVON"){
    for (int i = 0; i < 3; i++) {
      irsend.sendRC5(0xC4C,12);
      delay(40);
    }
    Serial.println("Tv On !");
    delay(10);
  } else if (command == "TVOFF"){
    for (int i = 0; i < 3; i++) {
      irsend.sendRC5(0x44C,12);
      delay(40);
    }
    Serial.println("Tv Off !");
    delay(10);
  }
}

