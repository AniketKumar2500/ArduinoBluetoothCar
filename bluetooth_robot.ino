#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(A5, A4); // RX, TX

//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);

char command;

void setup()
{
  bluetoothSerial.begin(9600);  //Set the baud rate to your Bluetooth module.
  Serial.begin(9600);
}

void loop() {
  if (bluetoothSerial.available() > 0) {
    command = bluetoothSerial.read();

    Stop(); //initialize with motors stoped
    Serial.println(command);
    switch (command) {
      case 'f':
        forward();
        
        break;
      case 'b':
        back();
        break;
      case 's':
        Stop();
        break; 
      case 'l':
        left();
        break;
      case 'r':
        right();
        break;
    }
  }
}

void back()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD);  //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD);  //rotate the motor clockwise
}

void forward()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor anti-clockwise
}

void left()
{
  motor1.setSpeed(150); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
}

void right()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD);  //rotate the motor clockwise
  motor2.setSpeed(150); //Define maximum velocity
  motor2.run(BACKWARD);  //rotate the motor clockwiseclockwise
}

void Stop()
{
  motor1.setSpeed(0);  //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0);  //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
}
