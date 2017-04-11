// Arduino Buzzer / Piezo Speaker activity
   
// setup speaker to arduino pin 9

const int buzzer = 9; 

void setup(){
  
// Set buzzer - pin 9 as an output
pinMode(buzzer, OUTPUT); 
//sets up your serial monitor  
Serial.begin(9600); 
  
}


void loop(){
//send message to the serial
Serial.println("setup complete");
// Send 1KHz sound signal
tone(buzzer, 1000); 
//send message to the serial
Serial.println("play sound");
// play sound for for 1 second
delay(1000);        
//stop sound 
noTone(buzzer);     
//stop sound for 1 second
delay(1000);

}

