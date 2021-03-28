int sensor_pin = A0; //signal from the capacitive soil moisture sensor
int output_value ;  // value of soil moisture
int pump = 2;      // digital pin where the relay is plugged in
int threshold = 25;  //threshold value to trigger pump 400 is sensor threshold


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);  //setup for the soil moisture senor aka INPUt
  pinMode(pump, OUTPUT);      //setup for the pump aka   OUTPUT
  Serial.println("Reading From the Sensor ...");
  delay(1000);  //1 second delay
  }

void loop() {
  // put your main code here, to run repeatedly:

  output_value = analogRead(sensor_pin);     //gets the value from the soil moisture sensor
  output_value = map(output_value,550,0,0,100); // this sets the percentage value
  Serial.print("Moisture : ");
  Serial.print(output_value);    //print the percent of soil moisture - max is 33% if dipped in a cup of water
  Serial.println("%");
  delay(10000); //wait 10 seconds before checking again  (switch to this line after testing)
  //delay(1000); //check every 1 second (this is for testing)
  if (output_value < threshold)  //if the soil is dry then pump out water for 1 second
    {
    digitalWrite(pump, HIGH);
    Serial.println("pump on");
    delay(1000);  //run pump for 1 second;
    digitalWrite(pump, LOW);
    Serial.println("pump off");
    delay(300000); //wait 5 minutes 
    }
    else
    {
    digitalWrite(pump, LOW);
    Serial.println("do not turn on pump");
    delay(10000);  //change to following line
    //delay(300000); //wait 5 minutes
    }
}
