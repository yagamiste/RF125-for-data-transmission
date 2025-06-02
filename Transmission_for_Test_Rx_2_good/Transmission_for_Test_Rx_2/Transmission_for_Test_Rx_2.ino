#include <Arduino.h>

// Define TX and RX pins for UART (change if needed)
#define TXD1 16
#define RXD1 17

// Use Serial1 for UART communication
HardwareSerial mySerial(0);

// -------------- define the command to start the transmission -------------------
uint8_t start[] = {0x73, 0x74, 0x61, 0x72, 0x74, 0x0D, 0x0A};

// -------------- define the message to sent -------------------
uint8_t payloadCommand[] = {0x57, 0x01, 0x01, 0x0D, 0x0A};

void setup() {
  Serial.begin(115200);
  // ----------- Printing when the transmission start --------------
  Serial.println("ESP32 UART Transmitter");
  Serial.println("Sending data");

  // ------------ UART setup --------------------
  mySerial.begin(9600, SERIAL_8N1, RXD1, TXD1);

  // ------------ Loading the message in the transmitter --------------- 
  mySerial.write(payloadCommand, sizeof(payloadCommand));
  delay(3000); // Waiting for the transmitter to receive the payloadCommand

  // ----------- Command to start the transmission ---------------------
  mySerial.write(start, sizeof(start));
  delay(1000);
}

void loop() {

}
