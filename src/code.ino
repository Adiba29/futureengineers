
#include <Servo.h>
#include <Pixy2.h>

#define lt 4 // attach pin D2 Arduino to pin Echo of HC-SR04
#define le 5 //attach pin D3 Arduino to pin Trig of HC-SR04
#define rt 6
#define re 7
#define ft 8
#define fe 11
int start=0;
int pb = 10;
int motor1pin1 = 2;
int motor1pin2 = 3;
int motor1pin3= 12;
Servo myservo; 
Pixy2 pixy;

long duration; // variable for the duration of sound wave travel
int df;// variable for the distance measurement
int dr;
int dl;
void setup() {
  

  myservo.attach(9); 
  myservo.write(90); 
  delay(15);
pbState  = digitalRead(pb);
  pinMode(pb,INPUT);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
    pinMode(motor1pin3, OUTPUT);
  digitalWrite(motor1pin2, LOW);
   digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin3, HIGH);
   
  pinMode(lt, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(le, INPUT); // Sets the echoPin as an INPUT
  pinMode(rt, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(re, INPUT);
  pinMode(ft, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(fe, INPUT);
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  if(pbState == LOW){

  // Clears the trigPin condition
  digitalWrite(rt, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(rt, HIGH);
  delayMicroseconds(10);
  digitalWrite(rt, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(re, HIGH);
  // Calculating the distance
  dr = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("right: ");
  Serial.print(dr);
  Serial.println(" cm");

  digitalWrite(lt, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(lt, HIGH);
  delayMicroseconds(10);
  digitalWrite(lt, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(le, HIGH);
  // Calculating the distance
  dl = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("left: ");
  Serial.print(dl);
  Serial.println(" cm");

  digitalWrite(ft, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(ft, HIGH);
  delayMicroseconds(10);
  digitalWrite(ft, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(fe, HIGH);
  // Calculating the distance
  df = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("front: ");
  Serial.print(df);
  Serial.println(" cm");
  myservo.write(90); 
  delay(15);
  digitalWrite(motor1pin2, LOW);
   digitalWrite(motor1pin1, HIGH);
  delay(4000);
if (df<45 && dr <30 )
{
  myservo.write(45); 
  delay(15);
    digitalWrite(motor1pin2, LOW);
   digitalWrite(motor1pin1, HIGH);
   delay(700);


if (dr<45 && df <30 )
{
  myservo.write(45); 
  delay(15);
    digitalWrite(motor1pin2, LOW);
   digitalWrite(motor1pin1, HIGH);
   delay(700);

}


}
