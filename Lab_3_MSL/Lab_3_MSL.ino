const int LEDS = 10;
const int LEDPins[LEDS] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
const int ButtonPin = 12;
int buttonState = 0;

void setup()
{
    for (int i = 0; i < LEDS; i++) {
        pinMode(LEDPins[i], OUTPUT);
    }
    pinMode(ButtonPin, INPUT);
}

void loop()
{
    buttonState = digitalRead(ButtonPin);
    if (buttonState == HIGH)
    {
        for (int i = LEDS - 1; i >= 0; i--) {
            digitalWrite(LEDPins[i], HIGH);
            delay(50);
            digitalWrite(LEDPins[i], LOW);
        }
    }
    else
    {
        for (int i = 0; i < LEDS; i++) {
            digitalWrite(LEDPins[i], HIGH);
            delay(50);
            digitalWrite(LEDPins[i], LOW);
        }
    }
}
