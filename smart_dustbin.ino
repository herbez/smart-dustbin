#include <LiquidCrystal.h>
#include <Servo.h>
// Constants
const int echoPin = 2;
const int trigPin = 3;
const int od30Pin = 4;
const int statePin = 5;
const int lcdAddr = 0x27;
const int lcdCols = 16;
const int lcdRows = 2;
const int SERVO_PIN = 9;
LiquidCrystal lcd(9,8,13,12,11,10);
Servo myservo;
void setup() {
 pinMode(echoPin, INPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(od30Pin, INPUT);
 pinMode(statePin, INPUT);
 lcd.begin(lcdCols, lcdRows);
 myservo.attach(SERVO_PIN);
}
void loop() {
 // Test Plan
 TestDistanceCalculation();
 TestInnerUltrasonicSensor();
 TestServoMotorOperation();
}
// Test the distance calculation
void TestDistanceCalculation() {
 Serial.println("Testing Distance Calculation...");
 // Simulating a pulseIn value
 long t = 20000;
 int dis = (int)(t * 0.034 / 2);
 Serial.print("Distance: ");
 Serial.print(dis);
 Serial.println(" cm\n");
}
// Test the inner ultrasonic sensor
void TestInnerUltrasonicSensor() {
 Serial.println("Testing Inner Ultrasonic Sensor...");
 // Simulating id value
 float id = 20.0;
 float per = (100 - (100 / 24.0) * id);
 // Simulate LCD output
 lcd.clear();
 if (per > 100) per = 100;
 lcd.print(per);
 lcd.print(" %");
 lcd.setCursor(0, 1);
 lcd.print("filled up\n");
}
// Test the servo motor operation
void TestServoMotorOperation() {
 Serial.println("Testing Servo Motor Operation...");
 // Simulating od30 and state values
 bool od30 = true;
 int state_motor = 0;
 int timer = 0;
 int state = 0;
 timer = 0;
 state = 0;
 if (od30 && digitalRead(statePin) == HIGH) {
 myservo.write(180);
 state_motor = 1;
 } else if (state_motor != 1) {
 myservo.write(180);
 state_motor = 1;
 if (timer < 3) {
 // Algorithm instruction for sensing message
 timer++;
 // Test sending message
 TestSendMessage();
 } else {
 timer = 0;
 }
 if (state == 0) {
 // Test sending message only when state=0
 TestSendMessage();
 state = 1;
 }
 }
 Serial.println();
}
// Test sending a message (placeholder function)
void TestSendMessage() {
 Serial.println("Sending message...");
}
