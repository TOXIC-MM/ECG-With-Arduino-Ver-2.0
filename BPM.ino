
#define ANALOG_PIN A0
#define SERIAL_BAUD_RATE 9600

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
}

void loop() {
  // Read analog data from AD8232 module
  int analogValue = analogRead(ANALOG_PIN);

  // Convert analog data to heart rate (BPM)
  int heartRate = calculateHeartRate(analogValue);

  // Send heart rate data to computer
  Serial.println(heartRate);

  // Add some delay to avoid flooding the serial port
  delay(100);
}

int calculateHeartRate(int analogValue) {
  // Implement your heart rate calculation algorithm here
  // Example: Convert analog data to BPM using a calibration curve or formula
  int heartRate = map(analogValue, 0, 1023, 60, 180); // Example mapping from analog value to BPM
  return heartRate;
}
