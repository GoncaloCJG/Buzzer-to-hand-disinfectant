int pirSensor1 = 2; // Define Pin 2 (Pir on the disinfectant)
int pirSensor2 = 4; // Define Pin 4 (Pir after the disinfectant)
int pinBuzzer = 7; // Define the Buzzer

// Variables that will store the time values when movement detected
unsigned long currentMillis1; 
unsigned long currentMillis2;

// Interval in which if Pin 4 detects a signal, the buzzer will not beep
const unsigned long interval = 4000; 

// Initialize the Pins
void setup() {
  pinMode(pirSensor1, INPUT);
  pinMode(pirSensor2, INPUT);
  pinMode(pinBuzzer, OUTPUT);
  
  Serial.begin(9600); // Configuration of the Serial port
}

void loop() {
  
  pirSensor1 = digitalRead(2);
  pirSensor2 = digitalRead(4);

  justCleaning(); 
  cleaning();
}

// Function if Pin 2 detects movement first
void justCleaning() {  
  if (pirSensor1 == HIGH) {
    currentMillis1 = millis(); // Stores the current value of millis() in the variable
    Serial.println("Thank you for disinfecting your hands!");
  }
}

// Function if Pin 4 detects movement first
void cleaning () {
  if ((pirSensor2 == HIGH) && currentMillis1 != 0) {
    currentMillis2 = millis(); // Stores the current value of millis() in the variable
    if ((currentMillis2 - currentMillis1 < interval) && currentMillis2 - currentMillis1 != 0)  {
        Serial.println("Disinfected hands, you can go!");
      noTone(7);
    }
    else {
      noTone(7);
    }
  }
   if (pirSensor2 == HIGH && (currentMillis2 - currentMillis1 >= interval) or pirSensor2 == HIGH && currentMillis1 == 0) {
    tone(7, 100, 1000);
    Serial.println("Hey! Disinfect your hands!!");
   }
}  
