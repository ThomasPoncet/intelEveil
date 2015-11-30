

// Used pins
int pressureSensorPin = 0;

// Configuration values
int limitValue = 50;

// Pressure state
boolean pressed;

// Return cmd
String pressure = "PRESSURE=";

void setup() {
  Serial.begin(9600);
  pressed = analogRead(pressureSensorPin) > limitValue;
}

void loop() {
  if (pressed != analogRead(pressureSensorPin) > limitValue) {
    pressed = !pressed;
    Serial.println(pressure+pressed);
    delay(500);
  }
}

