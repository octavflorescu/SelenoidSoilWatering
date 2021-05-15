const int soilSensor = A0;
const int valvePowerDigitalPin = 8;
const int LED_PIN = 13;

// Define our timer.
const long WATERING_TIME = 20000; // in milliseconds
const long WATERING_DELAY = WATERING_TIME/2; // in milliseconds
long infiltration_delay = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  
  pinMode(soilSensor, INPUT);
  pinMode(valvePowerDigitalPin, OUTPUT);

  // Start with sensor OFF
  digitalWrite(valvePowerDigitalPin, LOW);

  infiltration_delay = 0;
  
  // Setup serial plotter.
  Serial.begin(9600);
}

void loop() {
  int soilConductivity = analogRead(soilSensor);
  // humid soil ~ < 400
  if (infiltration_delay <= millis() && soilConductivity <= 400) {
    // Turn valve ON and wait a moment.
    digitalWrite(valvePowerDigitalPin, HIGH);
    digitalWrite(LED_PIN, HIGH);

    delay(WATERING_TIME);

    // Take reading, send to plotter.
    Serial.println(analogRead(soilSensor));
    
    // Turn valve OFF again and wait a moment for the water to infiltrate to the sensor
    digitalWrite(valvePowerDigitalPin, LOW);
    digitalWrite(LED_PIN, LOW);

    infiltration_delay = millis() + WATERING_DELAY;
  }
}
