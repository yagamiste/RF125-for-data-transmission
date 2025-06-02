// Packet transmission firebeetle

#include <Arduino.h>

// Define TX and RX pins for UART (change if needed)
#define TXD1 16
#define RXD1 17
#define buff_size 50

// Use Serial1 for UART communication
HardwareSerial mySerial(0);

uint8_t buff[buff_size];
uint8_t bytesRead;

// uint8_t ID[] = {0x52, 0x0D, 0x0A};
uint8_t payloadCommand[] = {0x57, 0x05, 0x01, 0x02, 0x03, 0x04, 0x05, 0x0D, 0x0A};

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600, SERIAL_8N1, RXD1, TXD1);  // UART setup
  
  Serial.println("ESP32 UART Transmitter");
}

void loop() {
  
  Serial.println("Sending data");
  mySerial.write(payloadCommand, sizeof(payloadCommand));
  delay(1000);
}