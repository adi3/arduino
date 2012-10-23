/* Path_Avoiding_Robot
 
 Adi, 2012
 */

// pin numbers
const int inputPin = A0;
const int pin1A =  12;
const int pin1B =  13;
const int pin2A =  11;
const int pin2B =  10;
const int threshold = 600;

int turn = 0;

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
  if (sensorValue < threshold) {
      driveForward();
  } else {
      turn = random(2);
      if (turn == 0)
        turnLeft();
      if (turn == 1)
        turnRight();
  }
  // print out input value after normalization
  Serial.println(sensorValue);
  delay(100);        // delay in between reads for stability

}

void driveForward(){
    digitalWrite(pin1A, LOW);
    digitalWrite(pin1B, HIGH);
    digitalWrite(pin2A, LOW);
    digitalWrite(pin2B, HIGH);
}


void turnRight(){
    digitalWrite(pin1A, HIGH);
    digitalWrite(pin1B, LOW);
    digitalWrite(pin2A, LOW);
    digitalWrite(pin2B, HIGH);
    delay(1800);
}

void turnLeft(){
    digitalWrite(pin1A, LOW);
    digitalWrite(pin1B, HIGH);
    digitalWrite(pin2A, HIGH);
    digitalWrite(pin2B, LOW);
    delay(1800);
}



