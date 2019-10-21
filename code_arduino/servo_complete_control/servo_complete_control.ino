#include <Arduino.h>
#include <Servo.h>

boolean newData = false;
char receivedChar = 0, hChar, vChar;
Servo servoH, servoV;
int actualPosUpper,actualPosLower;
int CHARMAX,RANGEMAX,REDUCTIONPID;


//servo horizontal : lower
//servo vertical : upper
void setup(){
  CHARMAX = 'l' - 'a';
  RANGEMAX = 5;
  Serial.begin(9600);
  servoV.attach(2, 900, 2400); // Wath out servo adjustement
  servoH.attach(3);
  actualPosUpper = 90;
  actualPosLower = 90;
  REDUCTIONPID = 1;
  servoV.write(actualPosUpper);
  servoH.write(actualPosLower);
}

void readOneChar() {
  if (Serial.available() > 0) {
    receivedChar = Serial.read();
    newData = true;
  }
}

void track() {
  readOneChar();

  int v = 0, h = 0;

  if (newData == false)
  return;

  // Code fonctionnel pour deplacement vertical
  if(receivedChar >= 'a' && receivedChar <= 'z'){
    h = receivedChar - 'a';

    if(receivedChar < 'l'){
      actualPosUpper += (CHARMAX - h) / REDUCTIONPID; // Deplacement vers le haut
    } else if (receivedChar > 'l') {
      actualPosUpper -= (h - CHARMAX) / REDUCTIONPID; // Deplacement vers le bas
    }
    servoH.write(actualPosUpper);

  }
  
  // Code fonctionnel pour deplacement horizontal
  else if(receivedChar >= 'A' && receivedChar <= 'Z'){
    v = receivedChar - 'A';

    if(receivedChar < 'L'){
      actualPosLower -= (int)((CHARMAX - v)/REDUCTIONPID);  // Deplacement vers la gauche
    } else if (receivedChar > 'L') {
      actualPosLower += (int)((v - CHARMAX)/REDUCTIONPID);  // Deplacement vers la droite
    }
    servoV.write(actualPosLower);
  }
  newData = false;
}

void loop(){
  receivedChar=0;
  track();
}
