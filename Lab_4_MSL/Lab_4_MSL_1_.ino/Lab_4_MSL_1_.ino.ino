const int LEDS = 10;
const int LEDPins[LEDS] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
const int PotentPin = A0;
int delay1;

void setup() {
  for (int i = 0; i < LEDS; i++) {
    pinMode(LEDPins[i], OUTPUT);
  }
  pinMode(PotentPin, INPUT);
}

void loop() {
  // Read potentiometer value to determine blinking speed
  int delayValue = analogRead(PotentPin);
  // Map the potentiometer value to a suitable delay range
  int mappedDelay = map(delayValue, 0, 1023, 50, 1000);

  // Blink LEDs
  for (int i = 0; i < LEDS; i++) {
    digitalWrite(LEDPins[i], HIGH);
    delay(mappedDelay);
    digitalWrite(LEDPins[i], LOW);
  }
}
