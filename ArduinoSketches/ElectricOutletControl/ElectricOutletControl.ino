

// Help taken there : http://www.instructables.com/id/Arduino-433Mhz-Wireless-Communication-Rc-Switch/

#include <RCSwitch.h> // Needs RC-Switch library, can be found there : https://github.com/sui77/rc-switch

RCSwitch mySwitch = RCSwitch();

// DIP switches configuration
char *firstDIPSwitches = "10000";
char *lastDIPSwitches = "00010";



void setup() {
  Serial.begin(9600);

  // Transmitter on pin 10
  mySwitch.enableTransmit(10);

  mySwitch.switchOff(firstDIPSwitches,lastDIPSwitches);

}
void loop() {
  String command = Serial.readString();
//  Serial.println(command);
//  if (command == NULL) {
//    Serial.println("null");
//  }
//  if (command != NULL){
//    if (command == "ON"){
//      mySwitch.switchOn(firstDIPSwitches,lastDIPSwitches);
//    } else if (command == "OFF"){
//      mySwitch.switchOff(firstDIPSwitches,lastDIPSwitches);
//    }
//  }
  executeCommandSerial();
}

void commandHandler(String command){
  if (command == "ON"){
    mySwitch.switchOn(firstDIPSwitches,lastDIPSwitches);
  } else if (command == "OFF"){
    mySwitch.switchOff(firstDIPSwitches,lastDIPSwitches);
  }
}

void executeCommandSerial() {
  String stream = Serial.readString();
  if (stream != NULL) {
    int separator = stream.indexOf(';');
    int commandStart = 0;
    while (separator != -1) {
      commandHandler(stream.substring(commandStart, separator));
      commandStart = separator + 1;
      separator = stream.indexOf(commandStart, ';');
    }
  }
}

