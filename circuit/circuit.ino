// zenduino alpha by taylor (hello@tay.is)
// basic code to create a self-ringing meditation bell

#include <Servo.h>  // servo library

Servo servo1;  // servo control object

void setup(){
  servo1.attach(9); // servo is connected to digital pin 9 on arduino
}

// establish pattern for a basic bell ring
// these degree measurements are specific to my build and
// should be adjusted depending on your arrangement
void basicRing(){
  servo1.write(180);  // tell servo to go to 180 degrees
  delay(200);         // pause to allow time to move
  servo1.write(120);  // tell servo to return to 120 degrees
  delay(10000);        // pause for 10 seconds after each ring
}

void loop(){

  //delay(30000); // pause for 30 seconds to prepare for meditation
  
  servo1.write(120); // move servo to start position for your build
  delay(500);        // allow time to move to position
  
  // ring three times to announce the beginning of the sit
  basicRing();
  basicRing();
  basicRing();
  
  servo1.detach(); // detach servo, preventing noise while not in use
  
  // adjust this based on how long you want to meditate
  // it is currently set for a 25 minute session
  delay(1500000);
  
  servo1.attach(9); // attach servo for closing rings
  
  // ring three times to announce the end of the sit
  basicRing();
  basicRing();
  basicRing();
  
  servo1.detach(); // detach servo, preventing noise while not in use
  
  while(1){ }; // infinite loop to stop the code from continuing
  
}
