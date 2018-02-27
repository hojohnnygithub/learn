//This program is to show students how the sensor array will detect objects and send messages to the serial monitor
//The code below will only work with the sensors

// Make sure the pins you're using on the Arduino match these numbers.
//Arduino pins connected to Light sensors
const int sensorpinRight = 2;
const int sensorpinMid = 3;
const int sensorpinLeft = 4;

//ADD in the connections for your motors

// Setup code will only run once at the start of the program.
void setup() {
 
  // Set sensor pins as input so that we can read information from them.
  pinMode(sensorpinLeft, INPUT);
  pinMode(sensorpinMid, INPUT);
  pinMode(sensorpinRight, INPUT);

// Allow us to send messages to the serial console
  Serial.begin(9600);
  Serial.println("Setup complete");

  //ADD in the connections for your motors
   
}

//add in your motors functions

// Loop code will run after the setup code and keep running over and over again forever until the power is shut off.
void loop() {

  

//no object in front  
  // HIGH means that nothing has been detected and LOW means that something has been detected
  if ((digitalRead(sensorpinLeft) == HIGH) && (digitalRead(sensorpinMid) == HIGH) && (digitalRead(sensorpinRight) == HIGH)) {
    //send message to serial monitor
    Serial.println("No objects detected. Keep on rolling");
    //ADD code to drive the motors forward at speed 100 for 1000 milliseconds
  
  }
    
  // object on left of MazeBot
  // LOW means that something has been detected
  if (digitalRead(sensorpinLeft) == LOW) {
    //send message to serial monitor
    Serial.println("Object detected on our left!");
    // ADD code to drive backward at speed 150 for 500 milliseconds (0.5 seconds)
    
    
    // ADD code to turn the robot left sharply
    
  }
  
  // object on right of MazeBot
  // LOW means that something has been detected
  if (digitalRead(sensorpinRight) == LOW) {
    //send message to serial monitor
    Serial.println("Object detected on our right!");
    // ADD code to drive backward at speed 150 for 500 milliseconds (0.5 seconds)
    
    // ADD code to turn left sharply



  }

    //object in front of MazeBot
    if (digitalRead(sensorpinMid) == LOW)  {
    //send message to serial monitor
    Serial.println("Object directly in front of us!");
        
    //ADD code to drive backward at speed 150 for 500 milliseconds (0.5 seconds)
    
    //ADD code to turn left sharply
    

      
  }
  
  
  }
  
  
  
  
    
  
  


