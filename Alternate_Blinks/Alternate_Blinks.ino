/* Alternate_Blinks
 
 * DigitalWrite
 
 Alternatively blinks two LEDs that are connected to digital ouput pins. They alternation
 occurs every 0.5 sec. Note that this alternation is coded without the use of a delay()
 function, so other code can run simulatneously without being interrupted by the LED code.
 
 Test circuit:
 LEDs attached from pin 12 and from pin 13 to ground.
 
 Adi, 2012
 */

// pin numbers
const int pin1 =  12;
const int pin2 =  13;

// instant variables
int state = LOW;                // used to set the 2 LEDs' state
long previousMillis = 0;        // will store last time LED was updated
long interval = 500;            // alternation cycle in milliseconds

void setup() {
  // initializing digital pins as output:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);   
}

void loop(){
  
  // returns time since circuit started
  unsigned long currentMillis = millis();
 
  // check to see if it is time to blink the LED
  if(currentMillis - previousMillis > interval) {
    // save the last time LED was blinked
    previousMillis = currentMillis;   

    // reverses state variable
    if (state == LOW)
      state = HIGH;
    else
      state = LOW;

    // reverses signal for both LEDs by setting to state and !state.
    digitalWrite(pin1, state);
    digitalWrite(pin2, !state);
  }
}

