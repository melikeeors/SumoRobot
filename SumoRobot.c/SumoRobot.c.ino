// Ultrasonic sensor
int echoPin = 3; //2
int trigPin = 4; //3
long duration;
int distance;
// Motors
int enA = 5; //4
int in1 = 6; //5
int in2 = 7; //6
int enB = 11; //7
int in3 = 9; //8
int in4 = 10; //9
// Color sensors
int irAnalogPin = A0;  // Analog pin for TCRT5000 sensor
int irAnalogPin2 = A1;  // Analog pin for TCRT5000 sensor
int irAnalogValue;
int irAnalogValue2; 


void setup() {
  // put your setup code here, to run once:

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(irAnalogPin, INPUT);
  pinMode(irAnalogPin2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the analog IR sensor value
  irAnalogValue = analogRead(irAnalogPin);
  irAnalogValue2 = analogRead(irAnalogPin2); 

  // Print the IR analog value for debugging
  /* Serial.print("IR Analog Value: ");
  Serial.println(irAnalogValue2); */

  // Check if the IR sensor detects a black surface using analog value
  if (irAnalogValue2 < 750) {  // Assuming lower value indicates white surface
    // Move the robot
    // Send a pulse to trigger the ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the echo time from the sensor
    duration = pulseIn(echoPin, HIGH);

    // Calculate distance in centimeters
    distance = duration * 0.034 / 2;

    // Print the distance for debugging
    Serial.print("Distance: ");
    Serial.println(distance);

    if (distance < 65) {  // Object detected within 20 cm
      // Move forward at maximum speed
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, 255);

      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enB, 255);
    } 
    else {
      // Move in a circle at maximum speed
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, 225);

      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enB, 225);
      delay(65);
    }

    if(irAnalogValue > 750){
        // Move backwards
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        analogWrite(enA, 255);

        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        analogWrite(enB, 255);
    }
  } else {
    // Stop the robot if it detects a black surface
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enA, 0);

    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enB, 0);
    while (true) {
      // Do nothing, effectively halting the robot
    }
  } 

  delay(100);  // Small delay to allow sensor to stabilize
}