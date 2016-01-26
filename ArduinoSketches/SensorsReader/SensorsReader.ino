

// Used pins
int pressSensorPin = 0;
int tempSensorPin = 1;
int lightSensorPin = 2;

// Configuration values
int pressLimVal = 50;
int tempLimVal = 320;
int lightLimVal = 300;

// Pressure state
boolean pressHigh;
// Temperature state
boolean tempHigh;
// Light state
boolean lightHigh;

void setup() {
  Serial.begin(9600);
  pressHigh = analogRead(pressSensorPin) > pressLimVal;
  tempHigh = analogRead(tempSensorPin) > tempLimVal;
  lightHigh = analogRead(lightSensorPin) > lightLimVal;
}

void loop() {
  if (pressHigh != analogRead(pressSensorPin) > pressLimVal) {
    pressHigh = !pressHigh;
    if (pressHigh){
      Serial.println("Press:High");
    } else {
      Serial.println("Press:Low");
    }
    delay(500);
  }
  if (tempHigh != analogRead(tempSensorPin) > tempLimVal) {
    tempHigh = !tempHigh;
    if (tempHigh){
      Serial.println("Temp:High");
    } else {
      Serial.println("Temp:Low");
    }
    delay(500);
  }
  if (lightHigh != analogRead(lightSensorPin) > lightLimVal) {
    lightHigh = !lightHigh;
    if (lightHigh){
      Serial.println("Light:High");
    } else {
      Serial.println("Light:Low");
    }
    delay(500);
  }
}
