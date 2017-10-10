// Traffic Light 

// setup speaker to arduino pin 9

const int buzzer = 9;

void setup() {

  // Set buzzer - pin 9 as an output
  pinMode(buzzer, OUTPUT);
  //sets up your serial monitor
  Serial.begin(9600);
  // red led pin
  pinMode(13, OUTPUT);
  //yellow led pin
  pinMode(12, OUTPUT);
  //green led pin
  pinMode(11, OUTPUT);

}
//consider the area below memory

//shutdown function - this code will stop your program 
void shutdown()
{
 Serial.println("Program End");  // message to serial monitor
 while(1);
}

//consider the area above memory

void loop() {
  //Make the green Led blink 
  digitalWrite(11, HIGH);   // set the LED on
  delay(500);              // wait for a 1 second
  Serial.println("blink LED"); // send message to serial monitor
  digitalWrite(11, LOW);    // set the LED off
  delay(500);              // wait for a 1 second

  //Write your code here to make the yellow led blink
  
  
 
  
  //Write your code here to make the red led blink
  
  
  
  
  // Play a sound
  tone(buzzer, 1500);
  //send message to the serial
  Serial.println("play sound 1");
  // play sound for for 1/2 second
  delay(200);
  //stop sound
  noTone(buzzer);
  //stop sound for 1 second
  delay(200);

  //Write your code here to play a different sound 

  
  
  
  //stop this program/sketch
  shutdown();

}

