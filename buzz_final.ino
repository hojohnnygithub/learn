// Arduino Buzzer / Piezo Speaker activity
   
// setup speaker to arduino pin 9

const int buzzer = 9; 

void setup(){
  
// Set buzzer - pin 9 as an output
pinMode(buzzer, OUTPUT); 
//sets up your serial monitor  
Serial.begin(9600); 
  
}

//this code will stop your program 
void shutdown()
{
 Serial.print("Program End");  // message to serial monitor
 while(1);
}


void loop(){
//send message to the serial
Serial.println("setup complete");
// Send 1KHz sound signal
tone(buzzer, 1000); 
//send message to the serial
Serial.println("play sound 1");
// play sound for for 1 second
delay(1000);        
//stop sound 
noTone(buzzer);     
//stop sound for 1 second
delay(1000);

// Send 1KHz sound signal
tone(buzzer, 1000); 
//send message to the serial
Serial.println("play sound 2 ");
// play sound for for 1 second
delay(1000);        
//stop sound 
noTone(buzzer);     
//stop sound for 1 second
delay(1000);

// Send 2KHz sound signal
tone(buzzer, 2000); 
//send message to the serial
Serial.println("play sound 3");
// play sound for for 1 second
delay(1000);        
//stop sound 
noTone(buzzer);     
//stop sound for 1 second
delay(1000);

// Send 3KHz sound signal
tone(buzzer, 3000); 
//send message to the serial
Serial.println("play sound 4");
// play sound for for 1 second
delay(1000);        
//stop sound 
noTone(buzzer);     
//stop sound for 1 second
delay(1000);

// Send 4KHz sound signal
tone(buzzer, 4000); 
//send message to the serial
Serial.println("play sound 5");
// play sound for for 1 second
delay(1000);        
//stop sound 
noTone(buzzer);     
//stop sound for 1 second
delay(1000);

shutdown(); 

}

