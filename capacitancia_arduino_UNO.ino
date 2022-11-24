#include <CapacitiveSensor.h>

#define EOL_DELIMITER "\n"
#define RESET 'r'

CapacitiveSensor cs_2_3 = CapacitiveSensor(2,3);       // 10 megohm resistor between pins 2 & 3, pin 3 is sensor pin 
CapacitiveSensor cs_2_4 = CapacitiveSensor(2,4);       // 10 megohm resistor between pins 2 & 4, pin 4 is sensor pin
CapacitiveSensor cs_2_5 = CapacitiveSensor(2,5);       // 10 megohm resistor between pins 2 & 5, pin 5 is sensor pin
CapacitiveSensor cs_9_6 = CapacitiveSensor(9,6);       // 10 megohm resistor between pins 9 & 6, pin 6 is sensor pin
CapacitiveSensor cs_9_7 = CapacitiveSensor(9,7);       // 10 megohm resistor between pins 9 & 7, pin 7 is sensor pin
CapacitiveSensor cs_9_8 = CapacitiveSensor(9,8);       // 10 megohm resistor between pins 9 & 8, pin 8 is sensor pin
CapacitiveSensor cs_13_10 = CapacitiveSensor(13,10);   // 10 megohm resistor between pins 13 & 10, pin 10 is sensor pin    
CapacitiveSensor cs_13_11 = CapacitiveSensor(13,11);   // 10 megohm resistor between pins 13 & 11, pin 11 is sensor pin
CapacitiveSensor cs_13_12 = CapacitiveSensor(13,12);   // 10 megohm resistor between pins 13 & 12, pin 12 is sensor pin    

int incoming = 0;

void setup()                    
{
   Serial.begin(57600);
   Serial.print("INITIALIZING");
   Serial.print(EOL_DELIMITER);
   
   cs_2_3.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on sensor 1
   cs_2_4.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on sensor 2
   cs_2_5.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on sensor 3
   cs_9_6.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on sensor 4
   cs_9_7.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on sensor 5
   cs_9_8.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on sensor 6
   cs_13_10.set_CS_AutocaL_Millis(0xFFFFFFFF);   // turn off autocalibrate on sensor 7
   cs_13_11.set_CS_AutocaL_Millis(0xFFFFFFFF);   // turn off autocalibrate on sensor 8
   cs_13_12.set_CS_AutocaL_Millis(0xFFFFFFFF);   // turn off autocalibrate on sensor 9
   
   Serial.print("READY");
   Serial.print(EOL_DELIMITER);
}

void loop()                    
{
    //check if there are any bytes available on the Serial port
    if( Serial.available() > 0)
    {
        //read a single byte.
        incoming = Serial.read();
        //Calling Serial.read() remove the byte from the Serial
        //buffer. In this case, if there are multiple bytes that
        //were sent, the next one will be handled on the next loop.
        //You could also grab it by calling Serial.read() again

        //check if the incoming byte was a command to recalibrate the sensors
        if(incoming == RESET)
        {
            Serial.print("init reset");
            Serial.print(EOL_DELIMITER);
            
            cs_2_3.reset_CS_AutoCal();     // calibrate sensor 1
            cs_2_4.reset_CS_AutoCal();     // calibrate sensor 2
            cs_2_5.reset_CS_AutoCal();     // calibrate sensor 3
            cs_9_6.reset_CS_AutoCal();     // calibrate sensor 4
            cs_9_7.reset_CS_AutoCal();     // calibrate sensor 5
            cs_9_8.reset_CS_AutoCal();     // calibrate sensor 6
            cs_13_10.reset_CS_AutoCal();   // calibrate sensor 7
            cs_13_11.reset_CS_AutoCal();   // calibrate sensor 8
            cs_13_12.reset_CS_AutoCal();   // calibrate sensor 9
   
            Serial.print("reset complete");
            Serial.print(EOL_DELIMITER);
        }
    }
  
    // NOTE the ID's are double Digits to differentiate between connected Ardionos
    // Arduino 2 would have ID's like 21, 22, 23, 24, ... etc.
    // Choose what ID name you like to distinguish between Sensors
    
    long total1 = cs_2_3.capacitiveSensor(30);   // read the Sensor with 30 samples
    Serial.print("11,");   //print sensor ID#    
    Serial.print(total1);  // print sensor 1 value
    Serial.print(EOL_DELIMITER);
    
    long total2 = cs_2_4.capacitiveSensor(30);   // read the Sensor with 30 samples
    Serial.print("12,");   //print sensor ID#    
    Serial.print(total2);  // print sensor 2 value
    Serial.print(EOL_DELIMITER);
    
    long total3 = cs_2_5.capacitiveSensor(30);   // read the Sensor with 30 samples
    Serial.print("13,");   //print sensor ID#    
    Serial.print(total3);  // print sensor 3 value
    Serial.print(EOL_DELIMITER);
    
    long total4 = cs_9_6.capacitiveSensor(30);   // read the Sensor with 30 samples
    Serial.print("14,");   //print sensor ID#    
    Serial.print(total4);  // print sensor 4 value
    Serial.print(EOL_DELIMITER);
    
    long total5 = cs_9_7.capacitiveSensor(30);   // read the Sensor with 30 samples
    Serial.print("15,");   //print sensor ID#    
    Serial.print(total5);  // print sensor 5 value
    Serial.print(EOL_DELIMITER);
    
    long total6 = cs_9_8.capacitiveSensor(30);   // read the Sensor with 30 samples
    Serial.print("16,");   //print sensor ID#    
    Serial.print(total6);  // print sensor 6 value
    Serial.print(EOL_DELIMITER);
    
    long total7 = cs_13_10.capacitiveSensor(30); // read the Sensor with 30 samples
    Serial.print("17,");   //print sensor ID#    
    Serial.print(total7);  // print sensor 7 value
    Serial.print(EOL_DELIMITER);
    
    long total8 = cs_13_11.capacitiveSensor(30); // read the Sensor with 30 samples
    Serial.print("18,");   //print sensor ID#    
    Serial.print(total8);  // print sensor 8 value
    Serial.print(EOL_DELIMITER);
    
    long total9 = cs_13_12.capacitiveSensor(30); // read the Sensor with 30 samples
    Serial.print("19,");   //print sensor ID#    
    Serial.print(total9);  // print sensor 9 value
    Serial.print(EOL_DELIMITER);

    delay(10);  // arbitrary delay to limit data to serial port 
}
