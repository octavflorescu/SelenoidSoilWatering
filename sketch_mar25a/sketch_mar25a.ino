const int soilSensor = A0;
const int valvePowerDigitalPin = 8;
const int LED_PIN = 13;

// Define our timer.
const long SECOND = 1000; // in milliseconds
const long MINUTE = 60 * SECOND;
const long HOUR = 60 * MINUTE;
const long DAY = 24 * HOUR;
// WATERING_TIME == 6 minutes due to flow through the pipe's diameter
// diameter allows 2 liters per hour
// => for 200ml per pot, 6 minutes are needed per watering 
const long WATERING_TIME = 6 * MINUTE; // in milliseconds

void setup() {
  pinMode(LED_PIN, OUTPUT);
  
  pinMode(soilSensor, INPUT);
  pinMode(valvePowerDigitalPin, OUTPUT);

  // Start with sensor OFF
  digitalWrite(valvePowerDigitalPin, LOW);
  
  // Setup serial plotter.
//  Serial.begin(9600);
}

void loop() {
  // Check soil needs water each day
  delay(DAY);
  
  int soilConductivity = analogRead(soilSensor);

  // Take reading, send to plotter.
//  Serial.println(soilConductivity);
    
  // humid soil ~ < 400
  if (soilConductivity <= 385) {
    // Turn valve ON and wait a moment.
    digitalWrite(valvePowerDigitalPin, HIGH);
    digitalWrite(LED_PIN, HIGH);

    delay(WATERING_TIME);
    
    // Turn valve OFF again and wait a moment for the water to infiltrate to the sensor
    digitalWrite(valvePowerDigitalPin, LOW);
    digitalWrite(LED_PIN, LOW);
  }
}
