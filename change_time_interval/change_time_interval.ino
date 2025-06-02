// setting time interval to 1s
#include <Arduino.h>

// Define TX and RX pins for UART (change if needed)
#define TXD1 16
#define RXD1 17
#define buff_size 50

// Use Serial1 for UART communication
HardwareSerial mySerial(0);

uint8_t buff[buff_size];
uint8_t bytesRead;

uint8_t ID[] = {0x58, 0x49, 0x0D, 0x0A};
uint8_t start[] = {0x73, 0x74, 0x61, 0x72, 0x74, 0x0D, 0x0A};

uint8_t payloadCommand[] = {0x57, 0x01, 0x00, 0x0D, 0x0A};
// 6 secondes = 6000 ms = 0x1770 
// 100 ms = 0x0064  
uint8_t setTimeInterval[] = {0x53, 0x00, 0x64, 0x0D, 0x0A};

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 UART Transmitter");
  mySerial.begin(9600, SERIAL_8N1, RXD1, TXD1);  // UART setup
  mySerial.write(setTimeInterval , sizeof(setTimeInterval));
  delay(3000); // to let the time to receive the playload
  //mySerial.write(ID, sizeof(ID));
  //delay(1000); // to let the time to receive the playload
  mySerial.write(start, sizeof(start));
  delay(1000);
}

void loop() {
}