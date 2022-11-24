#include <CapacitiveSensor.h>
#include <Firmata.h>
/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */
 
 /*
 + send capacitive sensing result via Firmata to your computer
 */


CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_4_10 = CapacitiveSensor(4,10);  

CapacitiveSensor   cs_4_3 = CapacitiveSensor(4,3);
CapacitiveSensor   cs_4_5 = CapacitiveSensor(4,5);
CapacitiveSensor   cs_4_7 = CapacitiveSensor(4,7);

void setup()                    
{
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Firmata.begin(57600);
}

void loop()                    
{
 
    long total1 =  cs_4_2.capacitiveSensor(30);
    long total2 =  cs_4_6.capacitiveSensor(30);
    long total3 =  cs_4_8.capacitiveSensor(30);
    long total4 =  cs_4_10.capacitiveSensor(30);
    
    long total5 =  cs_4_3.capacitiveSensor(30);
    long total6 =  cs_4_5.capacitiveSensor(30);
    long total7 =  cs_4_7.capacitiveSensor(30);
     
// here I am sending the result as analog value. the first number normaly indicates the pin number. it can go up to 15
      Firmata.sendAnalog(0,total1);
      Firmata.sendAnalog(1,total2);
      Firmata.sendAnalog(2,total3);
      Firmata.sendAnalog(3,total4);
      
      Firmata.sendAnalog(4,total5);
      Firmata.sendAnalog(5,total6);
      Firmata.sendAnalog(6,total7);

    Serial.print(total1);                  // print sensor output 1
    Serial.print(" ");
    Serial.print(total2);                  // print sensor output 1
    Serial.print(" ");
    Serial.print(total3);                  // print sensor output 1
    Serial.print(" ");
    Serial.print(total4);                  // print sensor output 1
    Serial.print(" ");
    Serial.print(total5);                  // print sensor output 1
    Serial.print(" ");
    Serial.print(total6);                  // print sensor output 1
    Serial.print(" ");
    Serial.print(total7);                  // print sensor output 1
    Serial.println(" ");

    delay(10);                             // arbitrary delay to limit data to serial port 
}
