#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int val;    // variable to read the value from the analog pin
int i = 0;
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  
  myservo.write(3);                  // sets the servo position according to the scaled value
  delay(500);                           // waits for the servo to get there
  myservo.write(177);                  // sets the servo position according to the scaled value
 delay(500);                           // waits for the servo to get there

}
