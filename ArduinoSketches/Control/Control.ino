



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
char *blindFirstDIPSwitches = "11111";
char *blindLastDIPSwitches = "01000";

// IR TV Codes (use SAMSUNG)
int tvOnOff_0 = 0xE0E040BF;
int tv0_0 = 0xE0E08877;
int tv1_0 = 0xE0E020DF;
int tv2_0 = 0xE0E0A05F;
int tv3_0 = 0xE0E0609F;
int tv4_0 = 0xE0E010EF;
int tv5_0 = 0xE0E0906F;
int tv6_0 = 0xE0E050AF;
int tv7_0 = 0xE0E030CF;
int tv8_0 = 0xE0E0B04F;
int tv9_0 = 0xE0E0708F;
int tvVolUp_0 = 0xE0E0E01F;
int tvVolDown_0 = 0xE0E0D02F;
int tvChanUp_0 = 0xE0E048B7;
int tvChanDown_0 = 0xE0E008F7;
int tvMute_0 = 0xE0E0F00F;

// IR TV Codes (use raw)
// const unsigned int tvOnOff_0[68] = {4600,4350,700,1550,650,1550,650,1600,650,450,650,450,650,450,650,450,700,400,700,1550,650,1550,650,1600,650,450,650,450,650,450,700,450,650,450,650,450,650,1550,700,450,650,450,650,450,650,450,650,450,700,400,650,1600,650,450,650,1550,650,1600,650,1550,650,1550,700,1550,650,1550,650};
// const unsigned int tv0_0[68] = {4650,4300,700,1550,700,1500,700,1550,700,400,700,400,700,400,700,450,650,450,650,1550,700,1550,650,1550,700,400,700,400,700,400,700,450,700,400,700,1550,650,400,700,450,700,400,650,1550,700,400,700,450,700,400,700,400,700,1500,700,1550,700,1500,700,400,700,1550,650,1550,700,1500,700};
// const unsigned int tv1_0[68] = {4650,4300,700,1550,700,1550,650,1550,700,400,700,400,700,400,700,450,700,400,700,1500,700,1500,700,1550,700,450,650,400,700,450,650,450,700,400,700,400,700,450,650,1550,700,400,700,400,700,400,700,450,650,450,650,1550,700,1500,700,450,650,1550,700,1550,650,1550,700,1500,700,1550,650};
// const unsigned int tv2_0[68] = {4600,4350,650,1550,700,1500,700,1550,700,400,700,400,700,450,650,450,700,400,700,1500,700,1500,700,1550,700,400,700,450,650,450,700,400,700,400,700,1500,700,400,700,1550,700,400,700,400,700,450,650,450,700,400,700,400,700,1550,650,450,700,1500,700,1550,650,1550,700,1500,700,1550,650};
// const unsigned int tv3_0[68] = {4600,4350,700,1500,700,1550,650,1600,650,400,700,450,700,400,700,400,700,400,700,1550,650,1550,700,1500,700,400,700,450,700,400,700,400,700,400,700,400,700,1550,700,1500,700,450,650,450,700,400,700,400,700,400,700,1550,700,400,700,400,700,1550,650,1550,700,1500,700,1550,700,1500,700};
// const unsigned int tv4_0[68] = {4600,4350,700,1500,700,1550,650,1600,650,400,700,450,700,400,700,400,700,400,700,1550,650,1550,700,1500,700,400,700,450,700,400,700,400,700,400,700,400,700,1550,700,1500,700,450,650,450,700,400,700,400,700,400,700,1550,700,400,700,400,700,1550,650,1550,700,1500,700,1550,700,1500,700};
// const unsigned int tv5_0[68] = {4650,4350,700,1500,700,1550,650,1550,700,400,700,450,700,400,700,400,700,400,700,1500,700,1550,700,1500,700,450,650,450,700,400,700,400,700,400,700,1550,700,400,700,400,650,1550,700,450,650,450,700,400,700,450,650,450,650,1550,650,1550,700,400,700,1550,700,1500,700,1500,700,1550,700};
// const unsigned int tv6_0[68] = {4600,4350,650,1550,700,1500,700,1550,700,400,700,400,700,450,650,450,700,400,700,1500,700,1550,650,1550,700,400,700,450,700,400,700,400,700,400,700,400,700,1550,700,400,700,1500,700,450,650,450,700,400,700,400,700,1550,650,450,650,1550,700,400,700,1550,650,1550,700,1500,700,1550,650};
// const unsigned int tv7_0[68] = {4600,4350,700,1500,700,1550,650,1550,700,400,700,450,700,400,700,400,700,400,700,1550,650,1550,700,1500,700,400,700,450,700,400,700,400,700,400,700,450,650,450,650,1550,700,1500,700,450,700,400,700,400,700,450,650,1550,650,1550,700,450,650,400,700,1550,700,1500,700,1550,650,1550,700};
// const unsigned int tv8_0[68] = {4600,4350,650,1600,650,1500,700,1550,700,400,700,400,700,400,700,450,700,400,700,1500,700,1550,650,1550,700,400,700,450,650,450,700,400,700,400,700,1550,650,450,650,1550,700,1500,700,450,700,400,700,400,700,400,700,400,700,1550,700,400,700,450,650,1550,650,1550,700,1500,700,1550,650};
// const unsigned int tv9_0[68] = {4600,4350,700,1500,700,1550,650,1550,700,400,700,450,650,450,650,450,700,400,700,1500,700,1550,700,1550,650,400,700,450,700,400,700,400,700,400,700,450,650,1550,650,1600,650,1550,650,450,700,400,700,400,700,400,700,1550,700,400,700,400,700,400,700,1550,700,1500,700,1500,700,1550,700};
// const unsigned int tvVolUp_0[68] = {4600,4350,650,1550,700,1500,700,1550,700,400,700,400,700,450,650,450,700,400,700,1500,700,1550,650,1550,700,400,700,400,700,450,650,450,700,400,700,1500,700,1550,650,1550,700,400,700,450,700,400,700,400,700,400,700,450,650,450,650,450,650,1550,700,1500,700,1550,700,1500,700,1550,650};
// const unsigned int tvVolDown_0[68] = {4600,4350,700,1550,650,1550,700,1500,700,450,650,450,700,400,700,400,700,400,700,1550,700,1500,700,1550,700,400,700,400,700,400,700,450,650,450,650,1550,700,1500,700,450,650,1550,700,400,700,400,700,450,700,400,700,400,700,400,700,1550,700,400,700,1500,700,1500,700,1550,700,1500,700};
// const unsigned int tvChanUp_0[68] = {4600,4350,700,1500,700,1500,700,1550,700,450,650,400,700,450,650,450,700,400,700,1500,700,1550,650,1550,700,450,650,450,700,400,700,400,700,400,700,400,700,1550,700,400,700,400,700,1550,650,450,700,400,700,400,700,1550,650,450,650,1600,650,1550,650,450,700,1500,700,1500,700,1550,650};
// const unsigned int tvChanDown_0[68] = {4650,4300,700,1550,700,1500,700,1550,700,400,700,400,700,400,700,450,650,450,650,1550,700,1500,700,1550,700,400,700,400,700,400,700,450,700,400,700,400,700,400,700,450,650,450,650,1550,700,400,700,450,650,400,700,1550,700,1500,700,1550,700,1500,700,400,700,1550,650,1550,700,1500,700};
// const unsigned int tvMute_0[68] = {4650,4350,650,1550,650,1550,700,1550,700,400,700,400,700,400,700,450,650,450,650,1550,700,1500,700,1550,700,400,700,450,650,400,700,450,700,400,700,1500,700,1550,650,1550,700,1500,700,450,700,400,700,400,700,400,700,400,700,450,650,450,700,400,700,1500,700,1550,650,1550,700,1500,700};

// IR TV Codes (use RC6)
//int tvOnOff_0 = 0x1000C;
//int tvOnOff_1 = 0xC;
//int tv0_0 = 0x0;
//int tv0_1 = 0x1000;
//int tv1_0 = 0x1;
//int tv1_1 = 0x1001;
//int tv2_0 = 0x2;
//int tv2_1 = 0x1002;
//int tv3_0 = 0x3;
//int tv3_1 = 0x1003;
//int tv4_0 = 0x4;
//int tv4_1 = 0x1004;
//int tv5_0 = 0x5;
//int tv5_1 = 0x1005;
//int tv6_0 = 0x6;
//int tv6_1 = 0x1006;
//int tv7_0 = 0x7;
//int tv7_1 = 0x1007;
//int tv8_0 = 0x8;
//int tv8_1 = 0x1008;
//int tv9_0 = 0x9;
//int tv9_1 = 0x1009;
//int tvVolUp_0 = 0x10;
//int tvVolUp_1 = 0x10010;
//int tvVolDown_0 = 0x11;
//int tvVolDown_1 = 0x10011;
//int tvChanUp_0 = 0x4C;
//int tvChanUp_1 = 0x1004C;
//int tvChanDown_0 = 0x4D;
//int tvChanDown_1 = 0x1004D;
//int tvMute_0 = 0xD;
//int tvMute_1 = 0x1000D;


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
  mySwitch.switchOff(blindFirstDIPSwitches,blindLastDIPSwitches);

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
  } else if (command == "BLINDON"){
    mySwitch.switchOn(blindFirstDIPSwitches,blindLastDIPSwitches);
    Serial.println("Blind on !");
    delay(10);    // To give time for radio transmission
  } else if (command == "BLINDOFF"){
    mySwitch.switchOff(blindFirstDIPSwitches,blindLastDIPSwitches);
    Serial.println("Blind off !");
    delay(10);    // To give time for radio transmission
  } else if (command == "WAIT"){    // Useless : only to test
    Serial.println("Waiting 2 seconds...");
    delay(2000);
  // } else if (command == "TVONOFF"){
  //   for (int i = 0; i < 3; i++) {
  //     irsend.sendRC6(tvOnOff_0,20);
  //     delay(40);
  //   }
  //   Serial.println("Tv On/Off !");
  //   delay(10);
  // } else if (command == "TV0"){
  //   for (int i = 0; i < 3; i++) {
  //     irsend.sendRC6(tv0_0,20);
  //     delay(40);
  //   }
  // } else if (command == "TV1"){
  //   for (int i = 0; i < 3; i++) {
  //     irsend.sendRC6(tv1_0,20);
  //     delay(40);
  //   }
  // } else if (command == "TV2"){
  //   for (int i = 0; i < 3; i++) {
  //     irsend.sendRC6(tv2_0,20);
  //     delay(40);
  //   }
  // } else if (command == "TV3"){
  //   for (int i = 0; i < 3; i++) {
  //     irsend.sendRC6(tv3_0,20);
  //     delay(40);
  //   }
  // } else if (command == "TV4"){
  //   for (int i = 0; i < 3; i++) {
  //     irsend.sendRC6(tv4_0,20);
  //     delay(40);
  //   }
  // } else if (command == "TV5"){
  //   for (int i = 0; i < 3; i++) {
  //     irsend.sendRC6(tv5_0,20);
  //     delay(40);
  //   }
  // } else if (command == "TV6"){
  //   for (int i = 0; i < 3; i++) {
  //     irsend.sendRC6(tv6_0,20);
  //     delay(40);
  //   }
  // } else if (command == "TV7"){
  //   for (int i = 0; i < 3; i++) {
  //     irsend.sendRC6(tv7_0,20);
  //     delay(40);
  //   }
  // } else if (command == "TV8"){
  //   for (int i = 0; i < 3; i++) {
  //     irsend.sendRC6(tv8_0,20);
  //     delay(40);
  //   }
  // } else if (command == "TV9"){
  //   for (int i = 0; i < 3; i++) {
  //     irsend.sendRC6(tv9_0,20);
  //     delay(40);
  //   }
  // } else if (command == "TVVOLUP"){
  //   for (int i = 0; i < 3; i++) {
  //     irsend.sendRC6(tvVolUp_0,20);
  //     delay(40);
  //   }
  // } else if (command == "TVVOLDOWN"){
  //   for (int i = 0; i < 3; i++) {
  //     irsend.sendRC6(tvVolDown_0,20);
  //     delay(40);
  //   }
  // } else if (command == "TVCHANUP"){
  //   for (int i = 0; i < 3; i++) {
  //     irsend.sendRC6(tvChanUp_0,20);
  //     delay(40);
  //   }
  // } else if (command == "TVCHANDOWN"){
  //   for (int i = 0; i < 3; i++) {
  //     irsend.sendRC6(tvChanDown_0,20);
  //     delay(40);
  //   }
  // } else if (command == "TVMUTE"){
  //   for (int i = 0; i < 3; i++) {
  //     irsend.sendRC6(tvMute_0,20);
  //     delay(40);
  //   }
  } else if (command == "TVONOFF"){
    for (int i = 0; i < 1; i++) {
      irsend.sendSAMSUNG(tvOnOff_0,32);
      delay(40);
    }
    Serial.println("Tv On/Off !");
    delay(10);
  } else if (command == "TV0"){
    for (int i = 0; i < 3; i++) {
      irsend.sendSAMSUNG(tv0_0,32);
      delay(40);
    }
  } else if (command == "TV1"){
    for (int i = 0; i < 3; i++) {
      irsend.sendSAMSUNG(tv1_0,32);
      delay(40);
    }
  } else if (command == "TV2"){
    for (int i = 0; i < 3; i++) {
      irsend.sendSAMSUNG(tv2_0,32);
      delay(40);
    }
  } else if (command == "TV3"){
    for (int i = 0; i < 3; i++) {
      irsend.sendSAMSUNG(tv3_0,32);
      delay(40);
    }
  } else if (command == "TV4"){
    for (int i = 0; i < 3; i++) {
      irsend.sendSAMSUNG(tv4_0,32);
      delay(40);
    }
  } else if (command == "TV5"){
    for (int i = 0; i < 3; i++) {
      irsend.sendSAMSUNG(tv5_0,32);
      delay(40);
    }
  } else if (command == "TV6"){
    for (int i = 0; i < 3; i++) {
      irsend.sendSAMSUNG(tv6_0,32);
      delay(40);
    }
  } else if (command == "TV7"){
    for (int i = 0; i < 3; i++) {
      irsend.sendSAMSUNG(tv7_0,32);
      delay(40);
    }
  } else if (command == "TV8"){
    for (int i = 0; i < 3; i++) {
      irsend.sendSAMSUNG(tv8_0,32);
      delay(40);
    }
  } else if (command == "TV9"){
    for (int i = 0; i < 3; i++) {
      irsend.sendSAMSUNG(tv9_0,32);
      delay(40);
    }
  } else if (command == "TVVOLUP"){
    for (int i = 0; i < 3; i++) {
      irsend.sendSAMSUNG(tvVolUp_0,32);
      delay(40);
    }
  } else if (command == "TVVOLDOWN"){
    for (int i = 0; i < 3; i++) {
      irsend.sendSAMSUNG(tvVolDown_0,32);
      delay(40);
    }
  } else if (command == "TVCHANUP"){
    for (int i = 0; i < 3; i++) {
      irsend.sendSAMSUNG(tvChanUp_0,32);
      delay(40);
    }
  } else if (command == "TVCHANDOWN"){
    for (int i = 0; i < 3; i++) {
      irsend.sendSAMSUNG(tvChanDown_0,32);
      delay(40);
    }
  } else if (command == "TVMUTE"){
    for (int i = 0; i < 3; i++) {
      irsend.sendSAMSUNG(tvMute_0,32);
      delay(40);
    }
  }
}
