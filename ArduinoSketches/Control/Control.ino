



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
char *coffeeFirstDIPSwitches = "10000";
char *coffeeLastDIPSwitches = "00010";
char *heaterFirstDIPSwitches = "11111";
char *heaterLastDIPSwitches = "00010";
char *lightFirstDIPSwitches = "11111";
char *lightLastDIPSwitches = "10000";
char *curtainFirstDIPSwitches = "11111";
char *curtainLastDIPSwitches = "01000";

// IR TV Codes (use RC6)
int tvOnOff_0 = 0x1000C;
int tvOnOff_1 = 0xC;
int tv0_0 = 0x0;
int tv0_1 = 0x1000;
int tv1_0 = 0x1;
int tv1_1 = 0x1001;
int tv2_0 = 0x2;
int tv2_1 = 0x1002;
int tv3_0 = 0x3;
int tv3_1 = 0x1003;
int tv4_0 = 0x4;
int tv4_1 = 0x1004;
int tv5_0 = 0x5;
int tv5_1 = 0x1005;
int tv6_0 = 0x6;
int tv6_1 = 0x1006;
int tv7_0 = 0x7;
int tv7_1 = 0x1007;
int tv8_0 = 0x8;
int tv8_1 = 0x1008;
int tv9_0 = 0x9;
int tv9_1 = 0x1009;
int tvVolUp_0 = 0x10;
int tvVolUp_1 = 0x10010;
int tvVolDown_0 = 0x11;
int tvVolDown_1 = 0x10011;
int tvChanUp_0 = 0x4C;
int tvChanUp_1 = 0x1004C;
int tvChanDown_0 = 0x4D;
int tvChanDown_1 = 0x1004D;
int tvMute_0 = 0xD;
int tvMute_1 = 0x1000D;


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

  mySwitch.switchOff(coffeeFirstDIPSwitches,coffeeLastDIPSwitches);
  mySwitch.switchOff(heaterFirstDIPSwitches,heaterLastDIPSwitches);
  mySwitch.switchOff(lightFirstDIPSwitches,lightLastDIPSwitches);
  mySwitch.switchOff(curtainFirstDIPSwitches,curtainLastDIPSwitches);

}

void loop() {
  executeCommandSerial(commandHandler);
}


void commandHandler(String command){
  if (command == "COFFEEON"){
    mySwitch.switchOn(coffeeFirstDIPSwitches,coffeeLastDIPSwitches);
    Serial.println("Coffee on !");
    delay(10);    // To give time for radio transmission
  } else if (command == "COFFEEOFF"){
    mySwitch.switchOff(coffeeFirstDIPSwitches,coffeeLastDIPSwitches);
    Serial.println("Coffee off !");
    delay(10);    // To give time for radio transmission
  } else if (command == "HEATERON"){
    mySwitch.switchOn(heaterFirstDIPSwitches,heaterLastDIPSwitches);
    Serial.println("Heater on !");
    delay(10);    // To give time for radio transmission
  } else if (command == "HEATEROFF"){
    mySwitch.switchOff(heaterFirstDIPSwitches,heaterLastDIPSwitches);
    Serial.println("Heater off !");
    delay(10);    // To give time for radio transmission
  } else if (command == "LIGHTON"){
    mySwitch.switchOn(lightFirstDIPSwitches,lightLastDIPSwitches);
    Serial.println("Light on !");
    delay(10);    // To give time for radio transmission
  } else if (command == "LIGHTOFF"){
    mySwitch.switchOff(lightFirstDIPSwitches,lightLastDIPSwitches);
    Serial.println("Light off !");
    delay(10);    // To give time for radio transmission
  } else if (command == "CURTAINON"){
    mySwitch.switchOn(curtainFirstDIPSwitches,curtainLastDIPSwitches);
    Serial.println("Curtain on !");
    delay(10);    // To give time for radio transmission
  } else if (command == "CURTAINOFF"){
    mySwitch.switchOff(curtainFirstDIPSwitches,curtainLastDIPSwitches);
    Serial.println("Curtain off !");
    delay(10);    // To give time for radio transmission
  } else if (command == "WAIT"){    // Useless : only to test
    Serial.println("Waiting 2 seconds...");
    delay(2000);
  } else if (command == "TVONOFF"){
    for (int i = 0; i < 3; i++) {
      irsend.sendRC6(tvOnOff_0,20);
      delay(40);
    }
    Serial.println("Tv On/Off !");
    delay(10);
  } else if (command == "TV0"){
    for (int i = 0; i < 3; i++) {
      irsend.sendRC6(tv0_0,20);
      delay(40);
    }
  } else if (command == "TV1"){
    for (int i = 0; i < 3; i++) {
      irsend.sendRC6(tv1_0,20);
      delay(40);
    }
  } else if (command == "TV2"){
    for (int i = 0; i < 3; i++) {
      irsend.sendRC6(tv2_0,20);
      delay(40);
    }
  } else if (command == "TV3"){
    for (int i = 0; i < 3; i++) {
      irsend.sendRC6(tv3_0,20);
      delay(40);
    }
  } else if (command == "TV4"){
    for (int i = 0; i < 3; i++) {
      irsend.sendRC6(tv4_0,20);
      delay(40);
    }
  } else if (command == "TV5"){
    for (int i = 0; i < 3; i++) {
      irsend.sendRC6(tv5_0,20);
      delay(40);
    }
  } else if (command == "TV6"){
    for (int i = 0; i < 3; i++) {
      irsend.sendRC6(tv6_0,20);
      delay(40);
    }
  } else if (command == "TV7"){
    for (int i = 0; i < 3; i++) {
      irsend.sendRC6(tv7_0,20);
      delay(40);
    }
  } else if (command == "TV8"){
    for (int i = 0; i < 3; i++) {
      irsend.sendRC6(tv8_0,20);
      delay(40);
    }
  } else if (command == "TV9"){
    for (int i = 0; i < 3; i++) {
      irsend.sendRC6(tv9_0,20);
      delay(40);
    }
  } else if (command == "TVVOLUP"){
    for (int i = 0; i < 3; i++) {
      irsend.sendRC6(tvVolUp_0,20);
      delay(40);
    }
  } else if (command == "TVVOLDOWN"){
    for (int i = 0; i < 3; i++) {
      irsend.sendRC6(tvVolDown_0,20);
      delay(40);
    }
  } else if (command == "TVCHANUP"){
    for (int i = 0; i < 3; i++) {
      irsend.sendRC6(tvChanUp_0,20);
      delay(40);
    }
  } else if (command == "TVCHANDOWN"){
    for (int i = 0; i < 3; i++) {
      irsend.sendRC6(tvChanDown_0,20);
      delay(40);
    }
  } else if (command == "TVMUTE"){
    for (int i = 0; i < 3; i++) {
      irsend.sendRC6(tvMute_0,20);
      delay(40);
    }
  }
}
