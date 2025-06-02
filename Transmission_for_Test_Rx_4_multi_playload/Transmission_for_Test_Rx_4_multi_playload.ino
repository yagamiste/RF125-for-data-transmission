// On met les playloads f loop                      ----
// ******************* Result of the experiments: ****************** 
// 
#include <Arduino.h>

// Define TX and RX pins for UART (change if needed)
#define TXD1 16
#define RXD1 17
#define buff_size 50
int i=0;

// Use Serial1 for UART communication
HardwareSerial mySerial(0);

uint8_t buff[buff_size];
uint8_t bytesRead;

uint8_t ID[] = {0x58, 0x49, 0x0D, 0x0A};
uint8_t start[] = {0x73, 0x74, 0x61, 0x72, 0x74, 0x0D, 0x0A};

uint8_t payloadCommand[] = {0x57, 0x02,0x01, 0x05, 0x0D, 0x0A};
uint8_t payloadCommand2[] = {0x57, 0x01, 0x07, 0x0D, 0x0A};
uint8_t stop[] = {0x73, 0x74, 0x6F, 0x70, 0x0D, 0x0A};

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 UART Transmitter");
  mySerial.begin(9600, SERIAL_8N1, RXD1, TXD1);  // UART setup
}

void loop() {
  fori = 1; i <= 10; i++)
  if(3*i+j==0)
  {
    // ****************** First playload *************************
    Serial.println("Sending data 1");
    payloadCommand[2]=0;
    mySerial.write(payloadCommand2, sizeof(payloadCommand2));
    delay(3000); // to let the time to receive the playload
    
    mySerial.write(start, sizeof(start));
    delay(9000);
    mySerial.write(stop,sizeof(stop));
  }
  if(i==1){
  // ****************** Second playload *************************
    
    Serial.println("Sending data 2");
    payloadCommand[2]=1;
    mySerial.write(payloadCommand2, sizeof(payloadCommand2));
    delay(3000); // to let the time to receive the playload

    mySerial.write(start, sizeof(start));
    delay(9000);
    mySerial.write(stop,sizeof(stop));
  }
    if(i==2){
  // ****************** Second playload *************************
    
    Serial.println("Sending data 3");
    payloadCommand[2]=2;
    mySerial.write(payloadCommand2, sizeof(payloadCommand2));
    delay(3000); // to let the time to receive the playload

    mySerial.write(start, sizeof(start));
    delay(9000);
    mySerial.write(stop,sizeof(stop));
  }
    i++;
  }
  

