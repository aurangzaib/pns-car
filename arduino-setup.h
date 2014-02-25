#include </home/aurangzaib/Documents/arduino/pns-car/src/header.h>
void setup() {
    // serial port
    Serial.begin(9600) ;
    //throttle direction
    pinMode(forward_relay, OUTPUT) ;
    pinMode(forward_fet, OUTPUT) ;
    pinMode(backward_drive, OUTPUT) ;
    //throttle initialization
    backwardOff() ;
    forwardOff() ;
    // servo initialization
    navigation.attach(servo_direction) ;
    navigation.write(90);
    delay(3) ;
}

