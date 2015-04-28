  /*Code by: Cody Jameson
    ARTD416:Programming For Artist
    This project controls a DC motor with a potentiometer.
    based off the speed of the motor, different LEDS will
    become lit based off of the speed of the motor.
  */
  
  //***Variables***\\
  
  //Analog pin for potentiometer
  int potPin = A0; 
  //Digital pin for the motor
  int motorPin = 9;
  // The value of the potentiometer
  int potValue = 0;
  //The value of the motor speed
  int motorValue = 0;
  //The clear LED
  int onPin = 4;
  //The Red LED PIN
  int hihPin = 5; 
  //The Yellow LED PIN
  int medPin = 6; 
  //The Green LED PIN
  int lowPin = 7; 
  //Sets the range for power on
  int fanOn = 1000;
  //Sets the range for low fan speed
  int fanLowPower = 800;
  //Sets the range for medium fan speed
  int fanMediumPower = 500;
  //Sets the speed for maximum fan spped
  int fanMaximumPower = 200;
  
  //***Setup***\\
  
  void setup() {
  //Bits per second for the Serial
   Serial.begin(9600);
  //Initializes each LED
   pinMode(onPin, OUTPUT);
   pinMode(lowPin, OUTPUT);
   pinMode(medPin, OUTPUT);
   pinMode(hihPin, OUTPUT);
   }
  //***The loop***\\
  void loop() {
   //sets the value of the potentiometer
   potValue = analogRead(potPin);  
   //sets the value of the motor
   motorValue = map(potValue, 0, 1023, 0, 255);
   //outputs the motor speed based on the parameter of the potentiometer
   analogWrite(motorPin, motorValue); 
   //Prints the value of the potentiometer to the serial console as a string
   Serial.print("potentiometer = " );   
   //Prints the value of the potentiometer to the serial console
   Serial.print(potValue);
   //Prints the value of the motor speed one tabed distance to the serial console
   Serial.print("\t motor = ");
   //Prints the value of the motor speed to the serial console
   Serial.println(motorValue);
   //Sets the delay speed of the output from the potentiometer to the motor speed
//   delay(2);  
   
  //***The if statements***\\ 
  
  //If the potentiometer range is less than or equal to 200, the Red LED turns on.
   if (potValue <= fanMaximumPower) { //example
      digitalWrite(hihPin, HIGH);
      digitalWrite(medPin, LOW);
      digitalWrite(lowPin, LOW);
       } 
  //If the potentiometer range is less than or equal to 500, the Yellow and Green LED turns on.
    
    else if (potValue <= fanMediumPower) {
      digitalWrite(hihPin, LOW);
      digitalWrite(medPin, HIGH);
      digitalWrite(lowPin, HIGH);
       }
  //If the potentiometer range is less tha or equal to 800, the Red, and Yellow LED turns off and the Green LED turns on
       
     else if (potValue <= fanLowPower ) {
      digitalWrite(hihPin, LOW);
      digitalWrite(medPin, LOW);
      digitalWrite(lowPin, HIGH);
      }
   //If the potentiometer range is greater or equal to 1000, the White LED turns on.
     else if (potValue >= fanOn ){
       digitalWrite(onPin, HIGH);
       digitalWrite(lowPin, LOW);
     }
   }
