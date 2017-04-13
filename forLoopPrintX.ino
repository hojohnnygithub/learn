void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("setup complete");
}

//this code will stop your program 
void shutdown()
{
 Serial.println("Program End");  // message to serial monitor
 while(1);
}

void loop() {
  for(int x = 0;x < 100; x++){
    Serial.println(x); //prints the value of X 0 to 99
  }

shutdown();
}
