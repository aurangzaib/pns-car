#include </home/aurangzaib/Documents/arduino/pns-car/src/setup.h>
void loop() {
    unsigned char serial_data;
    if (Serial.available() > 0) {
        serial_data = Serial.read() ;
        // FORWARD
        if (serial_data == 0) {
            forwardOn(fast) ;
        }
        // STOP
        if (serial_data == 1) {
            backwardOff() ;
            forwardOff() ;
        }
        // FORWARD RIGHT
        if (serial_data == 2) { // right button pressed
            backwardOff();
            for (rightup = 90; rightup < 175 && serial_data == 2; rightup += 5) {
                if (Serial.available() > 0) {
                    serial_data = Serial.read() ;
                }
                digitalWrite(forward_relay, HIGH);
                digitalWrite(forward_fet, HIGH);
                navigation.write(rightup) ;
            }
            rightdown  = rightup;
        }
        if (serial_data == 3) { // right button released
            forwardOff() ;
            for (; rightdown > 90; rightdown -= 5) {
                navigation.write(rightdown) ;
                delay(4) ;
            }
        }
        // FORWARD LEFT
        if (serial_data == 4) {// left button pressed
            backwardOff();
            for (leftup = 90; leftup > 35  && serial_data == 4; leftup -= 5) {
                digitalWrite(forward_relay, HIGH);
                digitalWrite(forward_fet, HIGH);
                navigation.write(leftup) ;
                if (Serial.available() > 0) {
                    serial_data = Serial.read() ;
                }
            }
            leftdown  = leftup;
        }
        if (serial_data == 5) { // left button released
            forwardOff() ;
            for (; leftdown < 90 ; leftdown += 5) {
                navigation.write(leftdown) ;
                delay(4) ;
            }
        }
        // REVERSE RIGHT
        if (serial_data == 6) { // right button pressed
            forwardOff();
            for (rightup = 90; rightup < 175 && serial_data == 6; rightup += 5) {
                digitalWrite(backward_drive, HIGH);
                navigation.write(rightup) ;
                if (Serial.available() > 0) {
                    serial_data = Serial.read() ;
                }
            }
            rightdown  = rightup;
        }
        if (serial_data == 7) { // right button released
            backwardOff() ;
            for (; rightdown > 90; rightdown -= 5) {
                navigation.write(rightdown) ;
                delay(4) ;
            }
        }
        // REVERSE LEFT
        if (serial_data == 8) {// left button pressed
            forwardOff();
            for (leftup = 90; leftup > 25  && serial_data == 8; leftup -= 5) {
                digitalWrite(backward_drive, HIGH);
                navigation.write(leftup) ;
                if (Serial.available() > 0) {
                    serial_data = Serial.read() ;
                }
            }
            leftdown  = leftup;
        }
        if (serial_data == 9) { // left button released
            backwardOff() ;
            for (; leftdown < 85 ; leftdown += 1) {
                navigation.write(leftdown) ;
                delay(4) ;
            }
        }
    }
}
