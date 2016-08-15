int led = 3;
int threshold = 30; //Change This
int volume;

int clap = false;

int clapInterval = 0;

bool light = false;

void setup() {                
  Serial.begin(9600); // For debugging
  pinMode(led, OUTPUT);     
}

void loop() {
  
  volume = analogRead(A0); // Reads the value from the Analog PIN A0
  
  if(volume>=threshold){
    // If first clap was made, then 
    if (!clap) {
      Serial.println("Clap interval TRUE");
      clap = true;
    } else if (clapInterval > 100) {
      
      if (light) {
        Serial.println("OFF");
        digitalWrite(led, LOW);
        light = false;
        
      } else {
        Serial.println("ON");
        digitalWrite(led, HIGH);
        light = true;
      }
      
      clap = false;
      clapInterval = 0;
    }
  }
  
  if (clap) {
    clapInterval++;
    
    if (clapInterval >= 500) {
      clapInterval = 0;
      Serial.println("Clap interval FALSE");
      clap = false;
    }
  }
  
  delay(1);
}
