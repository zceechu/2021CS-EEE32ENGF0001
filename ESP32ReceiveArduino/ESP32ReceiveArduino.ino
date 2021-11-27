// ESP 32 Serial read program.
// https://www.arduino.cc/reference/en/language/functions/communication/serial/read/ - Some of the program inspired from here
// https://icircuit.net/arduino-interfacing-arduino-uno-esp32/2134 - Serial transmission circuit diagram from here

#include <string.h>

#define INPUT_SIZE 10


// https://stackoverflow.com/questions/19206660/how-to-write-own-isnumber-function
bool isnumber(char *s) {
   char* e = NULL;
   (void) strtol(s, &e, 0);
   return e != NULL && *e == (char)0;
}


// Compares the input instruction and returns a corresponding int
int encode_instr(char *arg) {
  if (strcasecmp(arg, "READ") == 0) {
    return 0;
  } else if (strcasecmp(arg, "SET") == 0) {
    return 1;
  } else if (strcasecmp(arg, "STOP") == 0) {
    return 2;
  } else {
    return -1;
  }
}


void write_arduino() {
  // Get next command from Serial (add 1 for final 0)
  char input[INPUT_SIZE + 1];
  byte size = Serial.readBytes(input, INPUT_SIZE);
  
  // Add the final 0 to end the C string
  input[size] = 0;

//  Serial.print("INPUT: ");
//  Serial.println(input);

  // Declare vars for instruction and arguments
  int instr;
  char *arg = strtok(input, " ");

  // Iterate through input, splitting it up based on space char delimiter.
  while (arg != 0) {
    // If the argument is a number, don't try parsing it as an instruction
    if (isnumber(arg)) {
      Serial.println(arg);
    } else {
        // Assign the instr and check if it is valid
        instr = encode_instr(arg);
        if (instr >= 0) {
          Serial.println(instr);
        } else {
          Serial.println("Invalid input.");
        }
    }
    
    // Continue to next argument
    arg = strtok(0, " ");
  }
}


void setup() {
  Serial.begin(9600); // opens Serial port and set baud rate to 9600
}


void loop() {
  // Return early if there's no data on the Serial port
  if (Serial.available() < 1) {return;}

  write_arduino();
  
}
