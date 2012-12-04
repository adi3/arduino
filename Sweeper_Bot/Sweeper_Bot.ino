/* Sweeper_Bot
 
 Adi, 2012
 */



#include <Servo.h> 

Servo myservo;      // create servo object to control a servo

int sensorPin = 1;  // analog input pin for infrared sensor
int val;            // variable to read the value from the analog pin
int pos = 0;        // variable to store the servo position 

// pins for motor signals
int oneA = 4;
int oneB = 2;
int twoA = 8;
int twoB = 7;

void setup() 
{ 
  myservo.attach(9);      // attaches the servo on pin 9 to the servo object
  myservo.write(80);      // makes servo/sensor face forward.
  Serial.begin(9600);
  
  // initialize the digital motor pins as output.
  pinMode(oneA, OUTPUT);  
  pinMode(oneB, OUTPUT);  
  pinMode(twoA, OUTPUT);  
  pinMode(twoB, OUTPUT);    
} 

void loop() 
{
    myservo.write(80);
    if(isClear(400)){
      Serial.println("forward"); 
      moveForward();
    } else {
      Serial.println("back!"); 
      moveBack();
    }
    delay(500);
/*    myservo.write(80);
    delay(1000);

    val = analogRead(sensorPin);
 //   String result = "Front: " + String(val);
    if(val < 400) {
      Serial.println("forward clear\n"); 
    } 
    else {
      Serial.println("forward blocked\n");   
    }

    myservo.write(0);
    delay(1000);                           // waits for the servo to get there 
  
    val = analogRead(sensorPin);
//    result = "Left: " + String(val);
    if(val < 600) { 
      Serial.write("left clear\n"); 
    } else {
      Serial.println("left blocked\n");   
    }*/
}

void moveForward(){
  digitalWrite(oneA, HIGH);
  digitalWrite(oneB, LOW);
  digitalWrite(twoA, HIGH);
  digitalWrite(twoB, LOW);
}

void moveBack(){
  digitalWrite(oneB, HIGH);
  digitalWrite(oneA, LOW);
  digitalWrite(twoB, HIGH);
  digitalWrite(twoA, LOW);
}

boolean isClear(int threshold){
    val = analogRead(sensorPin);
    return (val < threshold);
}


