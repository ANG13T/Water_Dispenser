

const int trigPin = 6;
const int echoPin = 7;
const int relayPin = 4;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode (trigPin, OUTPUT); 
  pinMode (echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance < 18){
    dispenseWater();
    delay(1000);
  }
}

void dispenseWater(){
  digitalWrite(relayPin, HIGH);
  delay(3000);
  digitalWrite(relayPin, LOW);
}
