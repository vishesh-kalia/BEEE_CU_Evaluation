const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13;


long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); 
}


void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);


digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);


duration = pulseIn(echoPin, HIGH);


distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance >= 80){
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(ledPin, LOW);
}


Serial.print("Distance: ");
Serial.println(distance);
}