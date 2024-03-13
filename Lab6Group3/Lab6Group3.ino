#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h> 
#include <Servo.h>

#define GREEN_LED_PIN 10 
#define RED_LED_PIN 12 
#define PASSCODE_LENGTH 4 
#define SERVO_PIN 11
#define PASSCODE "1234"

const byte ROWS = 4;
const byte COLS = 4;
char keys [ROWS] [COLS] = { 
 {'1', '2', '3', 'A'},
 {'4', '5', '6', 'B'},
 {'7', '8', '9', 'C'},
 {'*', '0', '#', 'D'}
 };

byte rowPins [ROWS] = {9, 8, 7, 6};
byte colPins [COLS] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap (keys), rowPins, colPins, ROWS, COLS); 
LiquidCrystal lcd (13, A4, A0, A1, A2, A3);
Servo lockServo;

String enteredPasscode = "";

void setup() {

 Serial.begin(9600); 
 lcd.begin(16, 2);
 lockServo.attach(SERVO_PIN);
 lcd.setCursor(5, 0);
 lcd.print("WELCOME");
 lcd.setCursor(3, 1);
 lcd.print("ADAMSONIAN");
 delay(2000);
 lcd.clear();
 lcd.print ("Enter Passcode:");
 pinMode (GREEN_LED_PIN, OUTPUT);
 pinMode (RED_LED_PIN, OUTPUT);
 }

void loop() {
 char key = keypad.getKey();
 if (key) {
  if (key == '#') {
   if (enteredPasscode.length() == PASSCODE_LENGTH) {
    if (enteredPasscode == PASSCODE) {
     lcd.clear();
     lcd.print ("Access Granted!");
     unlock();
     digitalWrite(GREEN_LED_PIN, HIGH);
     delay(2000);
     digitalWrite(GREEN_LED_PIN, LOW);

  } else {
     lcd.clear();
     lcd.print ("Access Denied!");
     digitalWrite(RED_LED_PIN, HIGH);
     delay(2000);
     digitalWrite(RED_LED_PIN, LOW);
     lcd.clear();
     lcd.print ("Enter Passcode:");

  }
     enteredPasscode = "";
  } 

    } else {

     enteredPasscode += key;
     lcd.setCursor(0, 1);
     lcd.print (enteredPasscode);
  }
  }
  }

void unlock() {
   lockServo.write(90);
   delay(2000);
   lockServo.write(0);
}
