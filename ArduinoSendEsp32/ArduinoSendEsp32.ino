//https://icircuit.net/arduino-interfacing-arduino-uno-esp32/2134 Serial circuit from here
void setup() {
  Serial.begin(9600); //Start serial transmisison at 9600 baud rate
}

void loop() {
  //Print the data to the Serial port
  Serial.println("Data");
  //Wait 5 seconds to allow data to be received on ESP32
  delay(5000);
 }
