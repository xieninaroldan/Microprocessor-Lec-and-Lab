const int LEDS = 10;
const int LEDPins[LEDS] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int delay1;

void setup(){
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  pinMode(LED6,OUTPUT);
  pinMode(LED7,OUTPUT);
  pinMode(LED8,OUTPUT);
  pinMode(LED9,OUTPUT);
  pinMode(LED10,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(12,OUTPUT);
}

void loop(){
  delay1 = analogRead(A0);
}
 
