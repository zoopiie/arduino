void stop()
{
  analogWrite(10,0);//Motor A speed
  analogWrite(11,0);//Motor B speed
}



void setup() {
  pinMode(12,OUTPUT);//directionPinA
  pinMode(13,OUTPUT);//directionPinB
  pinMode(10,OUTPUT);//speedPinA
  pinMode(11,OUTPUT);//speedPinB

}

void loop() {
  stop();

}
