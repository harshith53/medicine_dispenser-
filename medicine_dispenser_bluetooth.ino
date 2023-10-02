// Pill Candy Dispenser | Automatic | Touch less
#include <Servo.h>
Servo servo;
//int pos;
int Signal = 8; 
int servopin = 9;
char data = 0; 
int led=13;
void setup() {
Serial.begin(9600); 
pinMode(Signal, INPUT);
pinMode(led, OUTPUT); 
servo.attach(servopin);
servo.write(0); //close cap on power on
delay(1000);
servo.detach();
}
void loop() {
int buttonState = digitalRead(Signal);
delay(1);
if(Serial.available() > 0)
{
data = Serial.read(); 
Serial.print(data); 
if(data == 1)
{
{digitalWrite(led, HIGH);
delay(100);
}
else if(data ==0)
{
{digitalWrite(led, LOW);
}
}
14
if (buttonState == 0)
{
servo.attach(servopin); 
delay(1); 
servo.write(90); 
delay(3000); 
servo.write(0); 
delay(1000); 
servo.detach();
}
}