// libraries
#include <Streaming.h>
#include <Servo.h>
// h-bridge control
#define forward_relay 4 // digital
#define forward_fet 3 // pwm
#define backward_drive 2 // digital
#define servo_direction 5 // pwm
// speed levels
#define fast 254
#define medium 190
#define turnspeed 160
#define slow 135
// Servo library instance
Servo navigation ;
// navigation control
unsigned char leftup = 0, leftdown = 0;
unsigned char rightup = 0, rightdown = 0;
// backward off function
void backwardOff() {
    digitalWrite(backward_drive, LOW);
    delay(25) ;
}// backward on function
void forwardOff() {
    digitalWrite(forward_relay, LOW);
    digitalWrite(forward_fet, LOW);
    delay(25) ;
}// forward on function
void backwardOn() {
    forwardOff();
    digitalWrite(backward_drive, HIGH);
}// forward off function
void forwardOn(unsigned char speed) {
    backwardOff();
    digitalWrite(forward_relay, HIGH);
    analogWrite(forward_fet, speed);
}
