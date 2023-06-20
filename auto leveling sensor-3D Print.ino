/* This tests a 3D Printer TL-TOUCH auto leveling sensor for 3D Printers. CR-Touch - BL-Touch - 3D Touch
 *  It sends a RC servo PWM signal of 10 degrees to lower the test probe.
 *  If the probe is pushed in approximately 0.130", the unit sends a quick positive pulse
 *  on the white wire. No more than 3.3 volts. (That is why pullups on)
 *  The unit will suck the probe in & flash the red light.
 *  Then this sends a PWM signal of 90 degrees to raise the test probe, simulating moving 
 *  to another test point. After a delay it lowers the probe again & starts over.
 *  BL-touch may have inverted output so use the attachInterrupt line for FALLING edge detect.
*/ 

#include <Servo.h> 
Servo myservo;  // create servo object to control a servo 
int Touch = 0; 
const int ledPin = 13;       // the pin that the LED is attached to
const byte interruptPin = 2;  // White probe output wire to Digital pin 2
 
void setup() 
{ 
  Serial.begin(115200);
  myservo.attach(13 );  // attaches the servo on pin 9 to the servo object 
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING);  // off to on will interrupt & go to blink function
  // attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);  // FALLING edge detect for BL-touch, Maybe?
} 
 
void loop() 
{ 
//    myservo.write(10);              // tell servo to go to DOWN position 
//    delay(15);                       // waits 15ms for the servo to reach the position
    if (Touch == 1) {      // went from off to on:
     myservo.write(90);        // tell servo to go to UP position. 
     Serial.print("tes11\n");
     delay(1000);
     digitalWrite(ledPin, HIGH);    // Turn LED on
//     delay(2000);
//     digitalWrite(ledPin, LOW);     // Turn LED off
     ; 
    }
    if (Touch == 0) {      // went from off to on:
     myservo.write(90);        // tell servo to go to UP position. 
     Serial.print("test2");
delay(1000);
     digitalWrite(ledPin, LOW);     // Turn LED off
    }
} 

void blink() {
  Touch = 1;
} 
