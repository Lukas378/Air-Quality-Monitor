int pin = 2;
unsigned long duration;
unsigned long starttime;
unsigned long sampletime_ms = 30000; 
unsigned long lowpulseoccupancy = 0;
float ratio = 0;
float concentration = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);
  starttime = millis(); 
}

void loop() {
  duration = pulseIn(pin, LOW);
  Serial.print("duration: ");
  Serial.println(duration);
  lowpulseoccupancy = lowpulseoccupancy+duration;
  Serial.print("lowpulse: ");
  Serial.println(lowpulseoccupancy);
  if ((millis()-starttime) >= sampletime_ms) //if the sampel time = = 30s
  {
   
    ratio = lowpulseoccupancy/(sampletime_ms*10.0);  
    Serial.print("ratio: ");
    Serial.println(ratio);
    concentration = 1.1*pow(ratio,3)-3.8*pow(ratio,2)+520*ratio+0.62; 
    if (concentration > 1){
    Serial.print("Concentration = ");
    Serial.print(concentration);
    Serial.println(" pcs/0.01cf");
    Serial.println("\n");
    }
    lowpulseoccupancy = 0;
    starttime = millis();
  }
}
