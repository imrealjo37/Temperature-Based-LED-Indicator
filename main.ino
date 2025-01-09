int celsius = 0;

void setup() {
  pinMode(A0, INPUT);       // Temperature sensor input
  Serial.begin(9600);       // Initialize serial communication
  pinMode(2, OUTPUT);       // Blue LED (Cold)
  pinMode(3, OUTPUT);       // Green LED (Moderate)
  pinMode(4, OUTPUT);       // Red LED (Hot)
}

void loop() {
  // Read temperature from the sensor and convert to Celsius
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);

  // Print temperature to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.println(" °C");

  // Control LEDs based on temperature
  if (celsius < 25) {       // Cold temperature
    digitalWrite(2, HIGH);  // Blue LED ON
    digitalWrite(3, LOW);   // Green LED OFF
    digitalWrite(4, LOW);   // Red LED OFF
  } 
  else if (celsius >= 25 && celsius <= 35) { // Moderate temperature
    digitalWrite(2, LOW);   // Blue LED OFF
    digitalWrite(3, HIGH);  // Green LED ON
    digitalWrite(4, LOW);   // Red LED OFF
  } 
  else if (celsius > 35) {  // Hot temperature
    digitalWrite(2, LOW);   // Blue LED OFF
    digitalWrite(3, LOW);   // Green LED OFF
    digitalWrite(4, HIGH);  // Red LED ON
  }

  delay(1000); // Wait for 1 second before the next reading
}
