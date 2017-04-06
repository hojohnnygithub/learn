void setup() 
{                  
  Serial.begin(9600);  
  //initialises serial communications at 9600 bits per second   
 
}

//this code will stop your program 
void shutdown()
{
 
 Serial.print("Program End");  // message or other warning 
 while(1);
}


void loop() 
{
// this is the message that will be sent to the Serial Monitor 
Serial.println(12345);
Serial.println("hello");


shutdown();
}

