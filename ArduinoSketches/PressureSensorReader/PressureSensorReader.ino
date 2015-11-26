

// Used pins
int pressureSensorPin = 0;

// Configuration values
int limitValue = 500;

// Pressure state
boolean pressed;

void setup() {
  Serial.begin(9600);
  pressed = analogRead(pressureSensorPin) > limitValue;
}

void loop() {
//  if (pressed != analogRead(pressureSensorPin) > limitValue) {
//    pressed = !pressed;
//    // Serial acction
//  }
  
  // Pressure value log
  Serial.println(analogRead(pressureSensorPin));
  delay(500);
}



