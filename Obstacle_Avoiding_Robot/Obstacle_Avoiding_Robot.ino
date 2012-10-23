/* Path_Avoiding_Robot
 
 Adi, 2012
 */

// pin numbers
const int inputPin = A0;
const int pin1A =  13;
const int pin1B =  12;
const int pin2A =  11;
const int pin2B =  10;
const int threshold = 200;

void setup() {
    // initializes serial communication at 9600 bits per second
  Serial.begin(9600);
  
  // initializing digital pins as output:
  pinMode(pin1A, OUTPUT);
  pinMode(pin1B, OUTPUT);
  pinMode(pin2A, OUTPUT);
  pinMode(pin2B, OUTPUT);  
}

void loop(){
  
  // reads the input on analog pin 0
  int sensorValue = analogRead(A0);
  
  // checks input and sets LED state accordingly
  if (sensorValue < threshold)
    driveForward();
  else
    
    
 

    // reverses signal for both LEDs by setting to state and !state.
 //   digitalWrite(pin1, state);
 //   digitalWrite(pin2, !state);
    
  // print out input value after normalization
  Serial.println(sensorValue);
  delay(100);        // delay in between reads for stability

}

void driveForward(){
    digitalWrite(pin1A, HIGH);
    digitalWrite(pin1B, LOW);
    digitalWrite(pin2A, HIGH);
    digitalWrite(pin2B, LOW);
}


