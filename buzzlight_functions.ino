// this code tells an LED and buzzer to work together. 

//buzzer to arduino pin 9
const int buzzer = 9; 

void setup() {                

//set up pin 9 as buzzer
pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

//set up pin 13 to LED

pinMode(13, OUTPUT);

}
//consider the area below memory
//This were you create your functions. 

/*function for blinking the LED called "blink"
 *the blink function contrains instructions to manipulate the LED connected to pin 13. 
 * When it is called, the call will contain value for time which will be used to state  
 * how long the LED is turned of for an off for.
 */
 
void blink(int time) {
  digitalWrite(13, HIGH);   // set the LED on
  delay(time);              // wait for a second
  Serial.println("blink LED"); // send message to serial monitor
  digitalWrite(13, LOW);    // set the LED off
  delay(time);              // wait for a second
  
}
/*function to make the buzzer sound called "buzz"
 *the buzz function contrains instructions to manipulate the buzzer connected to pin 9. 
 * When it is called, the call will contain two value for the sound and the time which will be used to state  
 * which sound to play and how long to play it for and how long to turn it off.
 */
//buzz function - this code will buzz your your speaker once 
void buzz(int sound, int time){
  
  tone(buzzer, sound); // Send 1KHz sound signal
  delay(time);        // wait 
  Serial.println("play sound"); // send message to serial monitor
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

  // to call the blink function to blink the LED for 1/2 second(500 milliseconds) you use this code:
  blink(500);
  /* to call the buzz function to buzz the speaker with a sharp tone(1000)
   * for 1/2 second(500 milliseconds) you use this code:
   */
  buzz(1000,500);
  
  
  

  // call the shutdown function
  shutdown(); 
  }

