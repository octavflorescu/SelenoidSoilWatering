// SENSOR READING
const int soilSensor = A0;
const int valvePowerDigitalPin = 8;
const int LED_PIN = 13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  
  pinMode(soilSensor, INPUT);
  pinMode(valvePowerDigitalPin, OUTPUT);

  // Start with sensor OFF
  digitalWrite(valvePowerDigitalPin, LOW);
  
  // Setup serial plotter.
  Serial.begin(9600);
}

void loop() {
  int soilConductivity = analogRead(soilSensor);
  // Take reading, send to plotter.
  Serial.println(soilConductivity);
}
