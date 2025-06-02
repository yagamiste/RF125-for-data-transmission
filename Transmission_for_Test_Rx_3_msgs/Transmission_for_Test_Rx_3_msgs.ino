// On change f les messages                      ----
// ******************* Result of the experiments: ****************** 
// Reeceived message = 8 * length of the playload i 
#include <Arduino.h>

// Define TX and RX pins for UART (change if needed)
#define TXD1 16
#define RXD1 17
#define buff_size 50

// Use mySerial(0) for UART communication
HardwareSerial mySerial(0);

uint8_t buff[buff_size];
uint8_t bytesRead;

uint8_t ID[] = {0x58, 0x49, 0x0D, 0x0A};
uint8_t start[] = {0x73, 0x74, 0x61, 0x72, 0x74, 0x0D, 0x0A};

uint8_t payloadCommand[] = {0x57, 0x05,0x01, 0x00,0x00,0x00,0x05, 0x0D, 0x0A};

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 UART Transmitter");
  Serial.println("Sending data");
  mySerial.begin(9600, SERIAL_8N1, RXD1, TXD1);  // UART setup
  mySerial.write(payloadCommand, sizeof(payloadCommand));
  delay(3000); // to let the time to receive the playload
  //mySerial.write(ID, sizeof(ID));
  //delay(1000); // to let the time to receive the playload
  mySerial.write(start, sizeof(start));
  delay(1000);
}

void loop() {
  
}