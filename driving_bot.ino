//This sketch is for Lesson 6 "Motoring Around" and this will instruct your buggy to drive around.

// the code below connects the motor board pins to Arduino Uno PWM digital pins

// motor A (wired into the "A" on the motor board)

const int motorpinLeft1 = 5;
const int motorpinLeft2 = 6;

// motor B (wired into the "B" on the motor board)

const int motorpinRight1 = 11;
const int motorpinRight2 = 10;


void setup()
{
 
  // set all the motor control pins to outputs
 
  pinMode(motorpinLeft1, OUTPUT);
  pinMode(motorpinLeft2, OUTPUT);
  pinMode(motorpinRight1, OUTPUT);
  pinMode(motorpinRight2, OUTPUT);
 
 // setup the serial monitor
  Serial.begin(9600);
  //send message to the serial monitor
  Serial.println("Setup complete");
}

// ++++++++++++++++++++++++++++++FUNCTION CODE+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//function to stop the motors
void stopMotors() {
  
  analogWrite(motorpinLeft1, 0);
  analogWrite(motorpinLeft2, 0);
  analogWrite(motorpinRight1, 0);
  analogWrite(motorpinRight2, 0);

}

//function to drive the motors in forward direction at a set speed and time
//this function uses parameter passing where the values for speed - "speed" and time -"milliseconds" is passed to the function from the code in the "void loop"
void motorsForward(int speed, int milliseconds) {

 
  analogWrite(motorpinLeft1, speed*1.0);   // the "*1.0" can be changed to calibrate the motor
  analogWrite(motorpinRight1, speed*1.0); // the "*1.0" can be changed to calibrate the motor
  delay(milliseconds);
 Serial.println("motors forward"); 
 //call the stopMotors() function
  stopMotors();

}

void motorsBackward(int speed, int milliseconds) {

 
  analogWrite(motorpinLeft2, speed*1.0);   // the "*1.0" can be changed to calibrate the motor
  analogWrite(motorpinRight2, speed*1.0); // the "*1.0" can be changed to calibrate the motor
  delay(milliseconds);
 Serial.println("motors Backward"); 
 //call the stopMotors() function
  stopMotors();

}

//function to drive the motors in turn the buggy in a sharp left direction at a set speed and time
//this function uses parameter passing where the values for speed - "speed" and time -"milliseconds" is passed to the function from the void loop
void pointTurnLeft(int speed, int milliseconds){
  
    analogWrite(motorpinLeft2, speed);
    analogWrite(motorpinRight1, speed);
    delay(milliseconds);
    Serial.println("point turn left");
    //call the stopMotors() function
    stopMotors();
}

//function to drive the motors in turn the buggy in a sharp right direction at a set speed and time
//this function uses parameter passing where the values for speed - "speed" and time -"milliseconds" is passed to the function from the void loop
void pointTurnRight(int speed, int milliseconds){
  
    analogWrite(motorpinLeft1, speed);
    analogWrite(motorpinRight2, speed);
    delay(milliseconds);
    Serial.println("point turn right");
    //call the stopMotors() function
    stopMotors();
}


//this code will stop your program 
void shutdown()
{
 Serial.println("program finished"); 
 while(1);
}

//Add any additional Function code here i.e. light sensor, colour sensor. 


//++++++++++++++++++++++++++++++++++++++++++++PRIMARY CODE+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// the code below is your program, instructions here will be completed over and over again unless the "shutdown" function is called.
void loop()
{
  //tells your buggy to wait 3 seconds before completing instructions after it
  delay(3000); 
  //calls the "motorsForward" function and passes the value "200" for speed and the value "1000" milliseconds for time 
  motorsForward(200, 500);
 pointTurnLeft(200, 350);
   motorsForward(200, 500);
    
   //Add your own code here: 
  



  
  // calls the shutdown function to ensure the program only runs through once.
  shutdown(); 
  
}
//+++++++++++++++++++++++++++++++++++++++++++++++END OF PROGRAM++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
