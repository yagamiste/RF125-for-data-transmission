//Reception firebeetle

#include <Arduino.h>


// Define TX and RX pins for UART (change if needed)
#define TXD1 16
#define RXD1 17
#define buff_size 50
// Use Serial1 for UART communication
HardwareSerial mySerial(0);

uint8_t bytesRead;
uint8_t buff[buff_size];


void setup() {
  Serial.begin(115200); //Serial monitor
  mySerial.begin(9600, SERIAL_8N1, RXD1, TXD1);  // UART setup
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("ESP32 UART Receiver");
}

void loop() 
{
  if (mySerial.available() > 0)
    {
      bytesRead = mySerial.readBytes(buff, buff_size);  // Read until LF (0x0A)

      Serial.print("Received: \n");
      for (int i = 0; i < bytesRead; i++) 
      {
        Serial.print(buff[i], HEX);  // Print in HEX format
        Serial.print("  ");
      }
      Serial.println("\n");

      Serial.println("-----------------------------------------------");
    }
   else
   {
    Serial.println("No signal");
   }
  delay(3000);
}