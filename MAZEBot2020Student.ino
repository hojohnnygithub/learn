//This code is for MAZEBot - A driving robot that uses light sensors to avoid obstacles
//Also uses a colour sensor to seek out points of interest(colour)

//Arduino pins connected to Light sensors
const int sensorpinRight = 2;
const int sensorpinMid = 3;
const int sensorpinLeft = 4;

// motor A (wired into the "A" on the motor board)
const int motorpinLeft1 = 5;
const int motorpinLeft2 = 6;

// motor B (wired into the "B" on the motor board)

const int motorpinRight1 = 10;
const int motorpinRight2 = 11;

//Color Sensor pins
#define S0 13
#define S1 12 
#define S2 7 
#define S3 8 
#define sensorOut 9

//provide a variable for light sensor collection
int frequency = 0;
//int color=0;

void setup()
{
 
// set all the motor control pins to outputs
// Set sensor pins as input so that we can read information from them.
pinMode(sensorpinLeft, INPUT);
pinMode(sensorpinMid, INPUT);
pinMode(sensorpinRight, INPUT);
  
// setup the serial monitor
Serial.begin(9600);
//send message to the serial monitor
Serial.println("Setup complete");
  
//setup Motors
pinMode(motorpinLeft1, OUTPUT);
pinMode(motorpinLeft2, OUTPUT);
pinMode(motorpinRight1, OUTPUT);
pinMode(motorpinRight2, OUTPUT);

//setup color sensor
pinMode(S0, OUTPUT);
pinMode(S1, OUTPUT);
pinMode(S2, OUTPUT);
pinMode(S3, OUTPUT);
pinMode(sensorOut, INPUT);
  
// Setting frequency-scaling to 20%
digitalWrite(S0, HIGH);
digitalWrite(S1, LOW);
 
}

//FUNCTION CODE++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//function to stop the motors
void stopMotors() {
  
analogWrite(motorpinLeft1, 0);
analogWrite(motorpinLeft2, 0);
analogWrite(motorpinRight1, 0);
analogWrite(motorpinRight2, 0);

}

//function to drive the motors in forward direction at a set speed and time
//this function uses parameter passing where the values for speed - "speed" and time -"milliseconds" is passed to the function from the main code
void motorsForward(int speed, int milliseconds) {

// CHANGE THE VALUES BELOW WHERE IT SAYS "*1.0" TO STOP THE ROBOT FROM DRIFTING
analogWrite(motorpinLeft1, speed*1.0);
analogWrite(motorpinRight1, speed*1.0);
delay(milliseconds);
Serial.println("motors forward"); 
//call the stopMotors() function
stopMotors();
}

//function to drive the motors in forward direction at a set speed and time
//this function uses parameter passing where the values for speed - "speed" and time -"milliseconds" is passed to the function from the main code
void motorsBackward(int speed, int milliseconds) {
// CHANGE THE VALUES BELOW WHERE IT SAYS "*1.0" TO STOP THE ROBOT FROM DRIFTING
analogWrite(motorpinLeft2, speed*1.0);
analogWrite(motorpinRight2, speed*1.0);
delay(milliseconds);
Serial.println("motors backward"); 
//call the stopMotors() function
stopMotors();
}

//function to drive the motors in turn the buggy in a sharp left direction at a set speed and time
//this function uses parameter passing where the values for speed - "speed" and time -"milliseconds" is passed to the function from the main code
void pointTurnLeft(int speed, int milliseconds){
analogWrite(motorpinLeft2, speed);
analogWrite(motorpinRight1, speed);
delay(milliseconds);
Serial.println("point turn left");
//call the stopMotors() function
stopMotors();
}

//function to drive the motors in turn the buggy in a sharp right direction at a set speed and time
//this function uses parameter passing where the values for speed - "speed" and time -"milliseconds" is passed to the function from the main code
void pointTurnRight(int speed, int milliseconds){
analogWrite(motorpinLeft1, speed);
analogWrite(motorpinRight2, speed);
delay(milliseconds);
Serial.println("point turn right");
//call the stopMotors() function
stopMotors();
}

//function to exit the loop
//this code will stop your program 
void shutdown()
{
Serial.println("sketch finish"); 
while(1);
}



// Function for determining colours - readColor()
void readColor() {
digitalWrite(S2, LOW);
digitalWrite(S3, LOW);
// Reading the output frequency
frequency = pulseIn(sensorOut, LOW);
int R = frequency;
// Printing the values for the Red, Green and Blue values to the serial monitor
Serial.print("R= ");//printing name
Serial.print(frequency);//printing RED color frequency
Serial.print("  ");
delay(150);
// Setting Green filtered photodiodes to be read
digitalWrite(S2, HIGH);
digitalWrite(S3, HIGH);
// Reading the output frequency
frequency = pulseIn(sensorOut, LOW);
int G = frequency;
// Printing the value on the serial monitor
Serial.print("G= ");//printing name
Serial.print(frequency);//printing RED color frequency
Serial.print("  ");
delay(150);
// Setting Blue filtered photodiodes to be read
digitalWrite(S2, LOW);
digitalWrite(S3, HIGH);
// Reading the output frequency
frequency = pulseIn(sensorOut, LOW);
int B = frequency;
// Printing the value on the serial monitor
Serial.print("B= ");//printing name
Serial.print(frequency);//printing RED color frequency
Serial.println("  ");
delay(150);

// if statement condition - black surface
if ((R > 100 ) && (G > 100) && (B > 100)) {   
Serial.println("Surface is Black");
Serial.println("Stopping now");
stopMotors();
shutdown();         
}
}
//END FUNCTION CODE++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// PROGRAM instructions below this line will be completed over and over again unless the "shutdown" function is called.
void loop()
{
//OBSTACLE AVOIDANCE: 
//if statement condition - no object in front  
// HIGH means that nothing has been detected and LOW means that something has been detected
if ((digitalRead(sensorpinLeft) == HIGH) && (digitalRead(sensorpinMid) == HIGH) && (digitalRead(sensorpinRight) == HIGH)) {
//send message to serial monitor
Serial.println("No objects detected. Keep on rolling");
//drive the motors forward at speed 150 for 1000 milliseconds
motorsForward(150, 100);
//decision making based on color
readColor();
}
    
// if statement condition -  object on left of MazeBot
// LOW means that something has been detected
if (digitalRead(sensorpinLeft) == LOW) {
//send message to serial monitor
Serial.println("Object detected on our left!");
//stop MAZEBot 2 seconds
stopMotors();
delay(2000);
// ADD code to drive backward at speed 150 for 125 milliseconds (0.125 seconds)

// ADD code to turn the robot right sharply

//decision making based on color , please dont remove
readColor();
}
  
// object on right of MazeBot
// LOW means that something has been detected
if (digitalRead(sensorpinRight) == LOW) {
//send message to serial monitor
Serial.println("Object detected on our right!");
//stop MAZEBot 2 seconds
stopMotors();
delay(2000);
// ADD code to drive backward at speed 150 for 125 milliseconds (0.125 seconds)

// ADD code to turn left sharply

//decision making based on color , please dont remove
readColor();
}

//object in front of MazeBot
if (digitalRead(sensorpinMid) == LOW)  {
//send message to serial monitor
Serial.println("Object directly in front of us!"); 
//stop MAZEBot 2 seconds
stopMotors();
delay(2000);     
//ADD code to drive backward at speed 150 for 125 milliseconds (0.125 seconds)

//ADD code to turn left sharply

//decision making based on color, please dont remove
readColor();
}  
}//End of Void Loop
