// This program controls a line following robot circuit
// which contains two DC motors and two photoresistors.
// A light threshold is determined between the dark line
// and the white board, and when a photoresistor senses
// the dark line, its motor is turned off to keep the robot
// on the track.

// Define Pin Mappings
const int leftMotorPin = 9;
const int leftSensorPin = A1;
const int rightMotorPin = 10;
const int rightSensorPin = A0;
const int buttonPin = 7;

// thresholds will be determined later
int rightlightThreshold = 0;
int leftlightThreshold = 0;

// the photoresistor values when both photoresistors are directly
// over the white board.
int rightWhiteLevel = 0;
int leftWhiteLevel = 0;

// start variable is used to start the motors turning
int start = 0;

void setup()
{
  //Set Baud Rate, Required to use Serial Monitor
  Serial.begin(9600);
  pinMode(leftMotorPin, OUTPUT);
  pinMode(leftSensorPin, INPUT);
  pinMode(rightMotorPin, OUTPUT);
  pinMode(rightSensorPin, INPUT);
  // button is used to determine light thresholds
  // and start the robot
  pinMode(buttonPin, INPUT);
  
}

void loop()
{
  // read the value of the button (HIGH/LOW) (Default is HIGH)
  int buttonValue = digitalRead(buttonPin);
  
  // only determine thresholds and start robot if the button
  // was pressed
  if (buttonValue == LOW) {
    // Read sensor values for white light level.
    rightWhiteLevel = analogRead(rightSensorPin);
    leftWhiteLevel = analogRead(leftSensorPin);

    // create thresholds by subtracting 50 from the white
    // light level (this step predicts that the black line will
    // be more than 50 light values less than the white board).
    rightlightThreshold = rightWhiteLevel - 50;
    leftlightThreshold = leftWhiteLevel - 50;
    
    // print the values of the thresholds (used for testing)
    Serial.println("Left: " + leftlightThreshold);
    Serial.println("Right: " + rightlightThreshold);

    // set start variable to 1 to start the motor logic and delay for 
    // half a second to give time to move hand away from button.
    start = 1;
    delay(500);
  }

  // start variable is 0 until the button is clicked,
  // so the robot won't start until then.
  while (start == 1) {
    //Read Sensor Values
    int leftLightLevel = analogRead(leftSensorPin);
    int rightLightLevel = analogRead(rightSensorPin);
   
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
}
