/* Sweeper_Bot
 
 Adi, 2012
 */



#include <Servo.h> 

Servo myservo;      // create servo object to control a servo

int sensorPin = 1;  // analog input pin for infrared sensor
int val;            // variable to read the value from the analog pin
int pos = 0;        // variable to store the servo position 

void setup() 
{ 
  myservo.attach(9);      // attaches the servo on pin 9 to the servo object
  myservo.write(90);      // makes servo/sensor face forward.
  Serial.begin(9600);
} 

void loop() 
{
    myservo.write(90);
    delay(1000);

  val = analogRead(sensorPin);
  String result = "Front: " + String(val);
  Serial.println(result); 
  if(val < 500) {
    Serial.println("forward clear"); 
  } 
  else {
    Serial.println("forward blocked");   
  }

    myservo.write(0);
    delay(1000);                           // waits for the servo to get there 

  val = analogRead(sensorPin);
  result = "Left: " + String(val);
  Serial.println(result); 
  //   val = analogRead(sensorPin);
  //  val = map(val, 0, 1023, 0, 179);

  //  if(val < 100) {
  //    Serial.println(val); 
  //    Serial.write("left clear"); 
  //  } else {
  ///Serial.println("left blocked");   
  //  }

  //    myservo.write(90);                 
  // } else {
  //   myservo.write(0);
  // }
} 

