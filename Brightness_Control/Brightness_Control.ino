/* Brightness_Control

  * AnalogRead, AnalogWrite, SerialOutput
  
  Reads an analog input on pin A0, normalizes the value for outputting, and writes the corresponding value on PWM pin D9.
  Normalized result is printed to the serial monitor every 0.1 sec at 9600 baud.
  
  Test Circuit:
  LDR in series with 100 kOhm resistor controlling a motor's speed (or LED's brightness) at D9.
 
  Adi, 2012
 */
 
 int outputPin = 9;

void setup() {
  // initializes serial communication at 9600 bits per second
  Serial.begin(9600);
  // no pin initialization for PWM output
}

void loop() {
  // reads the input on analog pin 0
  int sensorValue = analogRead(A0);
  int normalValue = sensorValue * 256/1024;
  // print out input value after normalization
  Serial.println(normalValue);

  // writes output to digital pin 9
  analogWrite(outputPin, normalValue);
  delay(100);        // delay in between reads for stability
}
