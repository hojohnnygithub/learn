//traffic light code with functions

//buzzer to arduino pin 9
const int buzzer = 9; 

void setup() {                

//set up pin 9 as buzzer
pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

//set up pin 13 to Red LED
pinMode(13, OUTPUT);
//set up pin 12 to  Yellow LED
pinMode(12, OUTPUT);
//set up pin 11 to  Green LED
pinMode(11, OUTPUT);


}
//consider the area below memory
//This were you create your functions. 

//blink function  - these are the specific instructions used to turn the led on and off
void blink(int led, int time) {
  digitalWrite(led, HIGH);   // set the LED on
  delay(time);              // wait for a second
  digitalWrite(led, LOW);    // set the LED off
  delay(time);              // wait for a second
  
}

//buzz function - these are the specific instructions used to buzz your your speaker once 
void buzz(int sound, int time){
  
  tone(buzzer, sound); // Send sound signal
  delay(time);        // wait 
  noTone(buzzer);     // Stop sound
  delay(time);         // wait 
}


//consider the area above memory


//shutdown function - this code will stop your program 
void shutdown()
{
 Serial.println("Program End");  // message to serial monitor
 while(1);
}

void loop() {

  // to call the blink function to blink the Red LED(pin 13) for 1/2 second(500 milliseconds) you use this code:
  blink(13, 500);

  //call the yellow LED to blink for 1/2 a second

  //call the green LED to blink for 1/2 a second

  //call blink to do green yellow red

  //call blink to do red rellow green

  //call blink to do red green yellow 

  //use a for loop to repat the pattern 8 times

    
  /* to call the buzz function to buzz the speaker with a sharp tone(1000)
   * for 1/2 second(500 milliseconds) you use this code:
   */
  buzz(1500,500);

  // call buzz to use the sound 1000 for 1/2 second
  
  // call buzz to use the sound 500 for 1/2 second

  // use a for loop to repeat the sounds 8 times
  
  // call buzz to make your own tune
  
  

  // call the shutdown function
  shutdown(); 
  }

