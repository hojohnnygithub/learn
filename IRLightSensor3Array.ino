
// Three(3) x InfraRed Sensor Obstacle Detection array (Left, Middle, Right)

// Make sure the pins you're using on the Arduino match these numbers.
const int sensorpinLeft = 2;
const int sensorpinMid = 3;
const int sensorpinRight = 4;

// Setup code will only run once at the start of the program.
void setup() {
  
  // Set sensor pins as input so that we can read information from them.
  pinMode(sensorpinLeft, INPUT);
  pinMode(sensorpinMid, INPUT);
  pinMode(sensorpinRight, INPUT);

// Allow us to print to the serial console
  Serial.begin(9600);
  Serial.println("Setup complete");

}

// Loop code will run after the setup code and keep running over and over again forever.
void loop() {

  
  
  // Object on direct right
  if (digitalRead(sensorpinLeft) == HIGH && digitalRead(sensorpinMid) == HIGH && digitalRead(sensorpinRight) == LOW){
    //send message to serial monitor
    Serial.println("Object detected on our right!");
    
  }
  
  //object directly in front
    else if (digitalRead(sensorpinLeft) == HIGH && digitalRead(sensorpinMid) == LOW && digitalRead(sensorpinRight) == HIGH ) {
    //send message to serial monitor
    Serial.println("Object directly in front!");
      
  }
    
     
  // Object on directly on left
  else if (digitalRead(sensorpinLeft) == LOW  && digitalRead(sensorpinMid) == HIGH && digitalRead(sensorpinRight) == HIGH) {
    //send message to serial monitor
    Serial.println("Object detected on our left!");
       
  }
  
  //no object in front
  else {
  //send message to serial monitor
    Serial.println("All Clear");

  }

  delay(200);
}
