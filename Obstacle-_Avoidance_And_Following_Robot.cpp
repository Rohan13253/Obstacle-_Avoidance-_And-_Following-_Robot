// C++ code
int leftbackwardpin = 12 ;// Declare variable for motor pin
int leftforwardpin = 11 ;// Declare variable for motor pin
int rightforwardpin= 9 ;
int rightbackwardpin= 10;
int leftmotorspeed = 6;
int rightmotorspeed = 5;
// Declear variable for ir sensor
const int triggerPin = 8 ;
const int echoPin = 7; 
const int ledPin= 2;
//Declar variable for ultrasonic sensor
const int ussthreshold = 10; // Max distance 

// IR Sensor
const int sensor2Pin = A2; //Left
const int sensor1Pin = A1; // Right

//Delear variable for inout state
int sensor2; // will take analog reading
int sensor1;
//Threshold value for ultrasonic sensor
const long threshold = 200; 

long duration; // store duration in long
long cm;

void setup()// Code that run one time
{
  pinMode(leftforwardpin, OUTPUT);// Set motor pin as output
  pinMode(leftbackwardpin, OUTPUT);// Set motor pin as output
  pinMode(rightforwardpin, OUTPUT);
  pinMode(rightbackwardpin, OUTPUT);
  pinMode(leftmotorspeed, OUTPUT);
  pinMode(rightmotorspeed, OUTPUT);
  
  // Sensor code
  Serial.begin(9600);
  pinMode(triggerPin,OUTPUT); //trigger as output
  pinMode(echoPin,INPUT); // this says to get input from this pin
}

 
  
void loop()// run the code in loop
{
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2); // Send low for 2 microsec
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);// send high for 2 microsec
  // 10 microsec is least  required by the sensor
  // This takes the input and and detech the high input
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  cm = duration/58;
  Serial.println(cm);
  
 sensor2 = analogRead(sensor2Pin);
 sensor1 = analogRead(sensor1Pin);

  if (sensor1 > threshold  && sensor2 > threshold  && cm > ussthreshold)
  {
    moveForward(0,225,225);
  }
  else if(sensor1 > threshold  && sensor2 < threshold )
  {//What if left sensor see the line
    turnRight(0,225,225);
  } 
  else if(sensor1 < threshold  && sensor2 > threshold )
  {//What if left sensor see the line
    turnLeft(0,255,225);
  }
  else {
    stopDriving(1000,0,0);
  }

}

 void moveForward(int delay_time,int leftspeed,int rightspeed)
 {
  analogWrite(leftmotorspeed,leftspeed); // to contol speed
  analogWrite(rightmotorspeed,rightspeed);
  digitalWrite(rightforwardpin, HIGH);// to set how motor will spin
  digitalWrite(rightbackwardpin, LOW);
  digitalWrite(leftforwardpin, HIGH);
  digitalWrite(leftbackwardpin,LOW);
  delay(delay_time);
 }
void moveBackward(int delay_time,int leftspeed,int rightspeed)
{
  analogWrite(leftmotorspeed,leftspeed);
  analogWrite(rightmotorspeed,rightspeed);
  digitalWrite(rightforwardpin, LOW);
  digitalWrite(rightbackwardpin, HIGH);
  digitalWrite(leftforwardpin, LOW);
  digitalWrite(leftbackwardpin, HIGH);
  delay(delay_time);
 }
  
void turnLeft(int delay_time,int leftspeed,int rightspeed)
 {
  analogWrite(leftmotorspeed,225);
  analogWrite(rightmotorspeed,225);
  digitalWrite(rightforwardpin, HIGH);
  digitalWrite(rightbackwardpin, LOW);
  digitalWrite(leftforwardpin, LOW);
  digitalWrite(leftbackwardpin,HIGH);
  delay(delay_time);
 }
void turnRight(int delay_time,int leftspeed,int rightspeed)
 {
  analogWrite(leftmotorspeed,225);
  analogWrite(rightmotorspeed,225);
  digitalWrite(rightforwardpin, LOW);
  digitalWrite(rightbackwardpin, HIGH);
  digitalWrite(leftforwardpin, HIGH);
  digitalWrite(leftbackwardpin,LOW);
  delay(delay_time);
 }
void stopDriving(int delay_time,int leftspeed,int rightspeed)
 {
  analogWrite(leftmotorspeed,225);
  analogWrite(rightmotorspeed,225);
  digitalWrite(rightforwardpin, LOW);
  digitalWrite(rightbackwardpin,LOW);
  digitalWrite(leftforwardpin,LOW);
  digitalWrite(leftbackwardpin,LOW);
  delay(delay_time);
  
  
 }