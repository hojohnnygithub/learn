/* This program is for lesson 8. The code you find below is only the "base code" which means 
 *  that this code will get you some of the way but it is expected that you will complete 
 *  the rest of the journey on your own. Good Luck!
 */

// Make sure the pins you're using on the Arduino match these numbers.
//Arduino pins connected to IR Light sensors
const int sensorpinRight = 2;
const int sensorpinMid = 3;
const int sensorpinLeft = 4;

//Arduino pins connected to motor driver shield
//motor A
const int motorpinLeft1 = 5;
const int motorpinLeft2 = 6;
//motor B
const int motorpinRight1 = 7;
const int motorpinRight2 = 8;


// Setup code will only run once at the start of the program.
void setup() {
  
  // Set each motor pin as output so we can send instructions to the motors.
  pinMode(motorpinLeft1, OUTPUT);
  pinMode(motorpinLeft2, OUTPUT);
  pinMode(motorpinRight1, OUTPUT);
  pinMode(motorpinRight1, OUTPUT);

  // Set sensor pins as input so that we can read information from them.
  pinMode(sensorpinLeft, INPUT);
  pinMode(sensorpinMid, INPUT);
  pinMode(sensorpinRight, INPUT);

  // Allow us to print to the serial console
  Serial.begin(9600);
  Serial.println("Setup complete");

}

// Create functions that tell the Arduino how to move the robot

// stop motors function
void stopMotors() {
  
  analogWrite(motorpinLeft1, 0);
  analogWrite(motorpinLeft2, 0);
  analogWrite(motorpinRight1, 0);
  analogWrite(motorpinRight2, 0);

}

// motors forward function, this accepts parameters passed to it - speed(values: 0-255) and time(values:milliseconds)
void motorsForward(int speed, int milliseconds) {
  
  analogWrite(motorpinLeft1, speed);
  analogWrite(motorpinRight1, speed);
  delay(milliseconds);
  //call the stopMotors() function
  stopMotors();

}

// motors backward function, this accepts parameters passed to it - speed(values: 0-255) and time(values:milliseconds)
void motorsBackward(int speed, int milliseconds) {
  
  analogWrite(motorpinLeft2, speed);
  analogWrite(motorpinRight2, speed); 
  delay(milliseconds);
  //call the stopMotors() function
  stopMotors();
}

// Point turn left function, this turns the Mazebot in a sharpLeft direction
// this accepts parameters passed to it - speed(values: 0-255) and time(values:milliseconds)
void pointTurnLeft(int speed, int milliseconds){
  
    analogWrite(motorpinLeft2, speed);
    analogWrite(motorpinRight1, speed);
    delay(milliseconds);
    //call the stopMotors() function
    stopMotors();
}

// Point turn right function, this turns the Mazebot in a sharp right direction
// this accepts parameters passed to it - speed(values: 0-255) and time(values:milliseconds)
void pointTurnRight(int speed, int milliseconds){

    analogWrite(motorpinLeft1, speed);
    analogWrite(motorpinRight2, speed);
    delay(milliseconds);
    //call the stopMotors() function
    stopMotors();
}


// Loop code will run after the setup code and keep running over and over again forever until the power is shut off.
void loop() {

  // Go forward at speed 100 for 2000 milliseconds (2 seconds)
  motorsForward(100, 2000);

  
  // object on right of MazeBot
  // LOW means that something has been detected
  if (digitalRead(sensorpinLeft) == HIGH && digitalRead(sensorpinMid) == HIGH && digitalRead(sensorpinRight) == LOW){
    //send message to serial monitor
    Serial.println("Object detected on our right!");
    // drive backward at speed 150 for 500 milliseconds (0.5 seconds)
    motorsBackward(150, 500);
    // turn left sharply
    pointTurnLeft(255, 500);
   

  }

    //object in front of MazeBot
    else if (digitalRead(sensorpinLeft) == HIGH && digitalRead(sensorpinMid) == LOW && digitalRead(sensorpinRight) == HIGH ) {
    //send message to serial monitor
    Serial.println("Object directly in front of us!");
        
    // drive backward at speed 150 for 500 milliseconds (0.5 seconds)
    motorsBackward(150, 500);
    // turn left sharply
    pointTurnLeft(255, 500);

      
  }
  
  // object on left of MazeBot
    else if (digitalRead(sensorpinLeft) == LOW  && digitalRead(sensorpinMid) == HIGH && digitalRead(sensorpinRight) == HIGH) {
    //send message to serial monitor
    Serial.println("Object detected on our left!");
    // drive backward at speed 150 for 500 milliseconds (0.5 seconds)
    motorsBackward(150, 500);
    // turn right sharply
    pointTurnRight(255, 500);
  
    
  }
  
  //no object in front  
  else {
    //send message to serial monitor
    // drive backward at speed 150 for 500 milliseconds (0.5 seconds)
    Serial.println("No objects detected. Keep on rolling");
    //drives forward at speed 100 for 1000 milliseconds
    motorsForward(100, 1000);
  }


}
