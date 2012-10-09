/* Nightlight

  * AnalogRead, DigitalWrite, SerialOutput
  
  Reads an analog input on pin A0, and changes digital signal on D12 if input is above threshold.
  Input is printed to the serial monitor every 0.1 sec at 9600 baud.
  
  Test Circuit:
  LDR in series with 100 kOhm resistor controlling a LED at pin 12.
 
  Adi, 2012
 */
 
 int outputPin = 12;
 int state = LOW;
 int threshold = 100;
 
void setup() {
  // initializes serial communication at 9600 bits per second
  Serial.begin(9600);
  // initializes D12 for output.
  pinMode(outputPin, OUTPUT);
}

void loop() {
  // reads the input on analog pin 0
  int sensorValue = analogRead(A0);
  
  // checks input and sets LED state accordingly
  if (sensorValue < threshold)
    state = HIGH;
  else
    state = LOW;
    
  // sends signal pin D12
  digitalWrite(outputPin, state);  
  
  // print out input value after normalization
  Serial.println(sensorValue);
  delay(100);        // delay in between reads for stability
}
