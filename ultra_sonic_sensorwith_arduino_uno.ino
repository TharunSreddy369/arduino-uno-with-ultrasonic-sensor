// Pin definitions
const int trigPin = 9;
const int echoPin = 8;
const int buzzerPin = 7;

// Variables for duration of echo and distance
long duration;
int distance;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10us pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time it takes for the echo to return
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm
  distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor (for debugging)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if the distance is within the desired range
  if (distance <= 10) {
    // Object is 10 cm or closer, beep twice
    beep(2);
  } else if (distance <= 15) {
    // Object is 15 cm away, beep once
    beep(1);
  }

  // Add a short delay before the next measurement
  delay(500);
}

// Function to beep the buzzer a certain number of times
void beep(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(100);  // Buzzer ON for 100ms
    digitalWrite(buzzerPin, LOW);
    delay(100);  // Buzzer OFF for 100ms between beeps
  }
}
