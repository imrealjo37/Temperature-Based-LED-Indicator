int celsius = 0;

void setup()
{
  pinMode(A0, INPUT);       // Temperature sensor input
  Serial.begin(9600);       // Initialize serial communication
  pinMode(2, OUTPUT);       // Green LED
  pinMode(3, OUTPUT);       // Yellow LED
  pinMode(4, OUTPUT);       // Red LED
}

void loop()
{
  // Read temperature from the sensor and convert to Celsius
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);

  // Print temperature to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.println(" °C");

  // Control LEDs based on temperature
  if (celsius < 25) { // Moderate temperature
    digitalWrite(2, HIGH); // Green LED ON
    digitalWrite(3, LOW);  // Yellow LED OFF
    digitalWrite(4, LOW);  // Red LED OFF
  } 
  else if (celsius >= 25 && celsius <= 35) { // Hot temperature
    digitalWrite(2, LOW);  // Green LED OFF
    digitalWrite(3, HIGH); // Yellow LED ON
    digitalWrite(4, LOW);  // Red LED OFF
  } 
  else if (celsius > 35) { // Very hot temperature
    digitalWrite(2, LOW);  // Green LED OFF
    digitalWrite(3, LOW);  // Yellow LED OFF
    digitalWrite(4, HIGH); // Red LED ON
  }

  delay(1000); // Wait for 1 second before the next reading
}
