// InfraRed Light Sensor Obstacle Detection 

//setup hardware connections
int LED = 13; // Use the onboard Uno LED
int isObstaclePin = 7;  // This is our input pin
int isObstacle = HIGH;  // HIGH MEANS NO OBSTACLE

//setup inputs and outputs
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(isObstaclePin, INPUT);
  Serial.begin(9600);
  Serial.println("Setup Complete");
}

void loop() {
  
  isObstacle = digitalRead(isObstaclePin);
  
  //uses a conditional known as an "if else" statement to make decisions
  //this is the "if" part and it checks for the condition: if an obstacle is detected
  //An obstacle detected - run the following code
  if (isObstacle == LOW)
  {
    //obstacle is found so send message to serial monitor
    Serial.println("OBSTACLE!!, OBSTACLE!!");
    //turn on LED
    digitalWrite(LED, HIGH);
  }
  //this is the "else" part and it only works when the condition: an obstacle is not detected
  //No obstacle detected - run the following code
  else
  {
    //obstacle is not found so send message to serial monitor
    Serial.println("clear");
    //turn off LED
    digitalWrite(LED, LOW);
  }
  //wait 0.2 seconds before the program is repeated
  delay(200);

  //notice how there is no "shutdown" function, this means the program will be repeat until the power is shut off
}

