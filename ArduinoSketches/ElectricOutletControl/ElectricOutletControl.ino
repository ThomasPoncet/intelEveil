

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

}
void loop() {
  mySwitch.switchOn(firstDIPSwitches,lastDIPSwitches);
  delay(2000);
  mySwitch.switchOff(firstDIPSwitches,lastDIPSwitches);
  delay(2000);
}



