
  void myInput() {

    // This code is in charge of collecting input data from the sensors 😀😀😀
  
    // Analog sensor(s)
    pinMode(A1, INPUT); // Water level sensor
    pinMode(A2, INPUT); // pH and EC sensor
    pinMode(A3, INPUT); // Humidity sensor
    pinMode(A4, INPUT); // Temperature sensor
    pinMode(A5, INPUT); // Pressure sensor
    
    // Digital sensor(s)
    pinMode(1, INPUT); // Light intensity sensor
    
  }
  
    void myOutput() {
      
    // This code is in charge of collecting output data from the sensors 😀😀😀
    
    // Digital sensor(s) 
    pinMode(1, OUTPUT); // Water pump
    pinMode(2, OUTPUT); // Growth light

  }


  void setup() {
    
  // put your setup code here, to run once:
  
  // Calling function(s)
  myInput();
  myOutput();

  }

  void loop() {
  
  // put your main code here, to run repeatedly:

   const int waterSensorValue = analogRead(A1);
   delay(200);
   const int tempValue = analogRead(A4);
   delay(200);
   const bool lightValue = digitalRead(2); 

   Serial.begin(19600);
   Serial.println('Water level is:' + waterSensorValue);
   delay(1000);

  // If water level is too low, turn on the pump
  if (waterSensorValue >= 0 && waterSensorValue < 400) {
    digitalWrite(1, HIGH);
    Serial.println('Water level is too low 😢😢😢')

  // If water level is too high, turn the pump off
  } else if (waterSensorValue >= 400) {
    digitalWrite(1, LOW);
    Serial.println('Water level is too high 😢😢😢')
  }

  // Display temperature value
  Serial.println('The temperature level is' + tempValue);
  delay(200);

  // 
  if (lightValue === 'HIGH') {
   const totalTimeOfLight = millis();
   if (totalTimeOfLight >= 48600000) {
     digitalWrite(2, LOW);
      }
    }
  }
