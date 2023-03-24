/*

Install Adafruit Motor Shield Library before uploading this code.
AFMotor Library https://learn.adafruit.com/adafruit-motor-shield/library-install

Caution: Remove the jumper or switch off the battery switch before connecting the Arduino board to computer.
 
*/


#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(9, 10); //  object created for Bluetooth communication, with RX connected to pin 9 and TX connected to pin 10.

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
// Four "AF_DCMotor" objects are created, each representing one of the four motors.
char command;
void setup()
{
  bluetoothSerial.begin(9600);  //sets the Bluetooth module baud rate 
}			


void loop() {
  if (bluetoothSerial.available() > 0) {
    command = bluetoothSerial.read();

    Stop(); 
   
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
    }
  }
}
// In the loop() function, the code constantly checks if there is data available on the Bluetooth serial port.
// If there is, it reads the first character and calls a corresponding function based on the character ("F" for forward, "B" for back, "L" for left, and "R" for right).
// If the command is not one of these, the robot stops using the Stop() function.
void forward()
{
  motor1.setSpeed(255); // sets the maximum speed
  motor1.run(FORWARD);  //rotates the motor in the counterclockwise direction
  motor2.setSpeed(255); 
  motor2.run(FORWARD);  
  motor3.setSpeed(255); 
  motor3.run(FORWARD);  
  motor4.setSpeed(255); 
  motor4.run(FORWARD);  
}





void back()
{
  motor1.setSpeed(255); 
  motor1.run(BACKWARD);  // rotates the motor in the clockwise direction
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); 
}
void left()
{
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(255); 
  motor3.run(FORWARD);  
  motor4.setSpeed(255); 
  motor4.run(FORWARD);  }
void right()
{
  motor1.setSpeed(255); 
  motor1.run(FORWARD);  
  motor2.setSpeed(255); 
  motor2.run(FORWARD);  s
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); 
}
void Stop()
{
  motor1.setSpeed(0);  
  motor1.run(RELEASE); 
  motor2.setSpeed(0);  
  motor2.run(RELEASE); 
  motor3.setSpeed(0);  
  motor3.run(RELEASE); 
  motor4.setSpeed(0);  
  motor4.run(RELEASE); }
