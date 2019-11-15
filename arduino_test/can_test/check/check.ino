//Written by Sandesh Banskota based on examples to test teensy 3.2 CAN
//circuit has pin 6 connected to standby

#include <FlexCAN.h>

//CAN_message_t is data structure type found in FlexCAN
static CAN_message_t msg;
static uint8_t hex[17] = "0123456789abcdef";

// -------------------------------------------------------------
static void hexDump(uint8_t dumpLen, uint8_t *bytePtr)
{
  uint8_t working;
  while( dumpLen-- ) {
    working = *bytePtr++;
    Serial.write( hex[ working>>4 ] );
    Serial.write( hex[ working&15 ] );
  }
  Serial.write('\r');
  Serial.write('\n');
}


void setup() {
  // put your setup code here, to run once:
  delay(1000);
  //print on serial to show start of test
  Serial.println(F("Hello Teensy 3.2 CAN Test."));

  //Can0 is already created and corresponds to the right pin on Teensy 3.1/2/etc
  //can find documentation on defaults and their corresponding on pawlesky
  Can0.begin();

  //need to change depending on whether correct or not
  pinMode(6,OUTPUT);
  digitalWrite(6,HIGH);


  
  
  //sfds
  
  msg.ext = 0;
  msg.id = 0x100;
  msg.len = 8;
  msg.buf[0] = 10;
  msg.buf[1] = 20;
  msg.buf[2] = 0;
  msg.buf[3] = 100;
  msg.buf[4] = 128;
  msg.buf[5] = 64;
  msg.buf[6] = 32;
  msg.buf[7] = 16;

  //



}

void loop() {
  // put your main code here, to run repeatedly:
  CAN_message_t inMsg;
  while (Can0.available()) 
  {
    Can0.read(inMsg);
    Serial.print("CAN bus 0: "); hexDump(8, inMsg.buf);
  }
  
  /*
  msg.buf[0]++;
  Can1.write(msg);
  msg.buf[0]++;
  Can1.write(msg);
  msg.buf[0]++;
  Can1.write(msg);
  msg.buf[0]++;
  Can1.write(msg);
  msg.buf[0]++;
  Can1.write(msg);  
  delay(20); 
  */

}
