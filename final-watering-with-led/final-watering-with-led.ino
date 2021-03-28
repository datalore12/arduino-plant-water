int sensor_pin = A0; //signal from the Capactive Soil Moisture Sensor
int ledpin = 3;      //digital pin for LED
int  output_value ;  // value of soil moisture 
int pump = 2;       //digital pin to the relay for pump
int threshold = 33; //threshold value to trigger pump. 400 is sensor threshold

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT); //indicate that soil moisture is INPUT
  pinMode(pump, OUTPUT);      //indicate that pump is OUTPUT
  pinMode(ledpin, OUTPUT);   //indicate that LED pin is OUTPUT
  Serial.println("Reading From the Sensor ...");
  delay(1000); //1 second delay

  digitalWrite(pump, HIGH);
  delay(500);
  }

void loop() {
  // put your main code here, to run repeatedly:
  output_value = analogRead(sensor_pin);  //get the value from soil moisture sensor
  output_value = map(output_value,550,0,0,100); //map to a percentage value
  Serial.print("Moisture : ");
  Serial.print(output_value);
  Serial.println("%");
  delay(1000);  //set this to 1000 for real use
  if (output_value < threshold) 
  { 
      digitalWrite(ledpin, HIGH);
      digitalWrite(pump, LOW);
      Serial.println("pump on");
      delay(15000); //run pump for 15 seconds
      digitalWrite(pump, HIGH);
      Serial.println("pump off");
      delay(300000); //wait for 5 minutes to stabilize moisture
  }
  else
  {
      digitalWrite(pump, HIGH);
      digitalWrite(ledpin,LOW);
      Serial.println("do not turn on pump");
      delay(300000); //wait for 5 minutes
    }  
}
