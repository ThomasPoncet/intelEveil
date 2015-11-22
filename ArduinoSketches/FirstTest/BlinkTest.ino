boolean blink = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.println("hello world !");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (blink) {
    digitalWrite(13, HIGH);
    wait(1000);
    digitalWrite(13, LOW);
    wait(200);    
  }

  while (Serial.available()) {
    // get the new byte:
    blink = '1' == ((char)Serial.read());
    Serial.println(blink);
  }
}


