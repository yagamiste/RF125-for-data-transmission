// -------------------  Send  Temperature and Humidity    ------------------

// 
#include <Arduino.h>
#include <DHT.h> 

// Define TX and RX pins for UART (change if needed)
#define TXD1 16
#define RXD1 17
#define buff_size 50

#define DHT_SENSOR_PIN  4 // ESP32 pin GPIO14 connected to DHT22 sensor
#define DHT_SENSOR_TYPE DHT22

DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

// Use Serial1 for UART communication
HardwareSerial mySerial(0);

uint8_t buff[buff_size];
uint8_t bytesRead;

uint8_t ID[] = {0x58, 0x49, 0x0D, 0x0A};
uint8_t start[] = {0x73, 0x74, 0x61, 0x72, 0x74, 0x0D, 0x0A};
uint8_t payloadCommand[] = {0x57, 0x02, 0x00, 0x00, 0x0D, 0x0A};
uint8_t stop[] = {0x73, 0x74, 0x6F, 0x70, 0x0D, 0x0A};
int count=0;

 /* ************ Sensing temparture function ******************* */
 /*
uin8t_t tempSensing(){

  float tempC = dht_sensor.readTemperature();
  
  uint8_t tempC_int = uint8_t(tempC);
  if ( isnan(tempC)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {

    Serial.print("Temperature: ");
    Serial.print(tempC_int);
      
    Serial.print("°C ");
    Serial.println();
  
  }
  return tempC_int;
}
*/ 

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 UART Transmitter");

  // ----------------- UART setup -------------------
  mySerial.begin(9600, SERIAL_8N1, RXD1, TXD1);  

  // ---------------- Initialize the DHT sensor --------------------
  dht_sensor.begin(); 
  
  // ---------------- Adding the sensed values to the Playload ----------------------- 
  payloadCommand[2]=uint8_t(dht_sensor.readTemperature());
  payloadCommand[3]=uint8_t(dht_sensor.readHumidity());
  
  // ---------------- Print the Temperature and Sensor ----------------
  printf("Temprature : %02x \n", payloadCommand[2] & 0xff);
  print("Humidity : %02x %", payloadCommand[3] & 0xff);

  // ------------ Loading the message in the transmitter --------------- 
  mySerial.write(payloadCommand, sizeof(payloadCommand));
  delay(3000); /// Waiting for the transmitter to receive the payloadCommand

  // ----------- Command to start the transmission ---------------------
  mySerial.write(start, sizeof(start));
  delay(1000);

}




void loop() {


   // *************** print uint8_t ********************/
   //payloadCommand[0]=51;
   //printf("%02x", payloadCommand[0] & 0xff);
  

    /******************************* Sensing ************************** */
  
  
  /*
  Serial.println("Sensing...");
  float humi  = dht_sensor.readHumidity();
  // read temperature in Celsius
  float tempC = dht_sensor.readTemperature();
  
  uint8_t tempC_int = uint8_t(tempC);
  uint8_t humi_int = uint8_t(humi);

  // check whether the reading is successful or not
  if ( isnan(tempC) || isnan(humi)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(humi_int);
    Serial.print("%");

    Serial.print("  |  ");
    Serial.print("Temperature: ");
    Serial.print(tempC_int);
  
    Serial.print("°C ");
    Serial.println();
    */
    /*
    // ************** Method 1 ************ 
    Serial.println("Modifying the playload");
    payloadCommand[2]= tempC_int ;
    /* *************** Method 2 **********

     // playload command to laod it in the memory **********
    Serial.println("Loading the data");
    mySerial.write(payloadCommand2, sizeof(payloadCommand2));
    delay(3000); // to let the time to receive the playload
    
    //  Start transmission 
      Serial.println("Start transmission");
      mySerial.write(start, sizeof(start));
      delay(9000);
      //mySerial.write(stop,sizeof(stop));
  }

  // wait 1 second between readings
  delay(1000);

  // Modifiying playload **************** 
  // NB: index start by zero !!!! 

  Serial.println("Modifying the playload");
    payloadCommand[2]= tempC_int ;
    payloadCommand[3]= humi_int ;
    printf("count =%d \n",count);

  //   playload command to laod it in the memory 
  Serial.println("Loading the data");
    mySerial.write(payloadCommand2, sizeof(payloadCommand2));
    delay(3000); // to let the time to receive the playload
    
  // Start transmission  
    Serial.println("Start transmission");
    mySerial.write(start, sizeof(start));
    delay(9000);
    //mySerial.write(stop,sizeof(stop));
  
  // Incrementing counter ******************
  count++; 
  */

}
