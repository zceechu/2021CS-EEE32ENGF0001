//ESP 32 Serial read program.
//https://www.arduino.cc/reference/en/language/functions/communication/serial/read/ Some of the program inspired from here
//https://icircuit.net/arduino-interfacing-arduino-uno-esp32/2134 Serial transmission circuit diagram from here

#define num_bytes = 100;
//Max number of bytes that can be sent

int incomingByte = 0; // for incoming serial data
int count = 0;
int printed = 0;

//Array that stores the data that is received from the arduino
char dataReceived[num_bytes];

void setup() {
  Serial.begin(9600); // opens Serial port and set baud rate to 9600
}

void loop() {
  // If data is available from the arduino
  while (Serial.available() > 0) 
  {
    //Set printed to be 0 so that the data can be printed out to the user
    printed = 0;
    // read the incoming byte:
    incomingByte = Serial.read();
    //Store the incoming byte in the dataReceived Array, convert the ascii decimal value to a char
    dataReceived[count] = char(incomingByte);

    //Increment count so that next byte is stored in next position in the array
    count++;
  }
  //If the new piece of data hasn't already been printed to the user
  if (printed== 0)
  {
    //iterate the array printing out the data stored
    for(int i = 0; i < 10; i++)
    {
      Serial.print(dataReceived[i]);
    }
    //set count back to 0 so that when new data is stored, it is stored at beginning of the array
    count = 0;
    //printed = 1 means that the data will not be printed again, only new data is printed out to avoid spamming serial monitor
    printed = 1;
  }
}
