// this code tells an LED and buzzer to work together. 

//buzzer to arduino pin 9
const int buzzer = 9; 

void setup() {                
// setup pin 13 as an output for the LED
pinMode(13, OUTPUT);     

//set up pin 9 as buzzer
pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

//sets up your serial monitor  
Serial.begin(9600); 

}

//this code will stop your program 
void shutdown()
{
 Serial.println("Program End");  // message to serial monitor
 while(1);
}


void loop() {
  Serial.println("setup complete"); // send message to serial monitor
  
  digitalWrite(13, HIGH);   // set the LED on
  delay(1000);              // wait for a second
  Serial.println("blink LED"); // send message to serial monitor
  digitalWrite(13, LOW);    // set the LED off
  delay(1000);              // wait for a second
  
   
  tone(buzzer, 1000); // Send 1KHz sound signal
  delay(1000);        // wait for a second
  Serial.println("play sound"); // send message to serial monitor
  noTone(buzzer);     // Stop sound
  delay(1000);         // wait for a second
  

  
  shutdown(); //shutdown program

  }

