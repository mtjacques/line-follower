//Define Pin Mappings
const int leftMotorPin = 9;
const int leftSensorPin = A1;
const int rightMotorPin = 10;
const int rightSensorPin = A0;

int rightlightThreshold = 550;
int leftlightThreshold = 500;

void setup()
{
  //Set Baud Rate, Required to use Serial Monitor
  Serial.begin(9600);
  pinMode(leftMotorPin, OUTPUT);
  pinMode(leftSensorPin, INPUT);
  pinMode(rightMotorPin, OUTPUT);
  pinMode(rightSensorPin, INPUT);
  
}

void loop()
{
  //Read Sensor Values
  int leftLightLevel = analogRead(leftSensorPin);
  int rightLightLevel = analogRead(rightSensorPin);
  Serial.println(rightLightLevel);
   
  // If left light sensor is greater than threshold
  // then turn left Motor on, else turn left Motor off
  if (leftLightLevel > leftlightThreshold)
    digitalWrite(leftMotorPin, HIGH);
  else
    digitalWrite(leftMotorPin, LOW);

  // If right light sensor is greater than threshold
  // then turn left Motor on, else turn left Motor off
  if (rightLightLevel > rightlightThreshold)
    digitalWrite(rightMotorPin, HIGH);
  else
    digitalWrite(rightMotorPin, LOW);

}
