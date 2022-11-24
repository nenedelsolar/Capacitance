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


CapacitiveSensor cs_40_31 = CapacitiveSensor(40, 31);       // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor cs_40_32 = CapacitiveSensor(40, 32);       // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor cs_40_33 = CapacitiveSensor(40, 33);       // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor cs_40_34 = CapacitiveSensor(40, 34);

CapacitiveSensor cs_41_35 = CapacitiveSensor(41, 35);
CapacitiveSensor cs_41_36 = CapacitiveSensor(41, 36);
CapacitiveSensor cs_41_37 = CapacitiveSensor(41, 37);
CapacitiveSensor cs_41_38 = CapacitiveSensor(41, 38);

void setup()
{
  cs_40_31.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  cs_41_35.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Firmata.begin(57600);
}

void loop()
{

  long total1 = cs_40_31.capacitiveSensor(30);
  long total2 = cs_40_32.capacitiveSensor(30);
  long total3 = cs_40_33.capacitiveSensor(30);
  long total4 = cs_40_34.capacitiveSensor(30);

  long total5 = cs_41_35.capacitiveSensor(30);
  long total6 = cs_41_36.capacitiveSensor(30);
  long total7 = cs_41_37.capacitiveSensor(30);
  long total8 = cs_41_38.capacitiveSensor(30);

  // here I am sending the result as analog value. the first number normaly indicates the pin number. it can go up to 15
  Firmata.sendAnalog(1, total1);
  Firmata.sendAnalog(2, total2);
  Firmata.sendAnalog(3, total3);
  Firmata.sendAnalog(4, total4);

  Firmata.sendAnalog(5, total5);
  Firmata.sendAnalog(6, total6);
  Firmata.sendAnalog(7, total7);
  Firmata.sendAnalog(8, total8);


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
  Serial.print(" ");
  Serial.print(total8);                  // print sensor output 1
  Serial.println(" ");

  delay(10);                             // arbitrary delay to limit data to serial port
}
