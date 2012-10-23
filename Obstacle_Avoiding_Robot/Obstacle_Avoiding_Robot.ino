  /* Obstacle_Avoiding_Robot
   
    * AnalogRead, DigitalWrite, SerialOutput
    
    Reads an analog input on pin A0 from an infrared sensor, and changes digital signal on pins 
    D10-13 to make the robot drive forward or take turns. Robot has a 2-motor drive with a castor
    for support. A single H-Bridge motor shield module is used to control the 2 motors.
    Sensor readinf is printed to the serial monitor every 0.1 sec at 9600 baud.
    
    Test Circuit:
    SHARP 2Y0A21 infrared sensor at pin A0 to measure distance. Both motors are connected to the
    motor shield module along with a 9V power-supply. Pins for motor 1 from the shield are connected
    at D12 and D13, and for motor 2 are connected at D10 and D11. Arduino is powered by a 9V battery
    through the USB port.
    
    Adi, 2012
   */
  
  // pin numbers
  const int inputPin = A0;
  const int pin1A =  12;      // orange
  const int pin1B =  13;      // red
  const int pin2A =  11;      // brown
  const int pin2B =  10;      // black
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
  
  

