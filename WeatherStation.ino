/*
  Code for a slave arduino who will collect the wind data for weather station
  Based on: NMEA Wind Instrument by Tom Kuehn
  Uses the peet bros ananometer
*/

#include <Wire.h>
int windSnelheid = 0;
int windRichting = 0;

void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop()
{
  delay(2000);

  Wire.requestFrom(2, 4);    // request 4 bytes from slave device #2


  byte a, b, c, d;

  a = Wire.read();
  b = Wire.read();
  c = Wire.read();
  d = Wire.read();

  windRichting = a;
  windRichting = windRichting << 8 | b;
  Serial.print("Graden: ");
  Serial.print(windRichting);
  Serial.println("*");
  windSnelheid = c;
  windSnelheid = windSnelheid << 8 | d;
  float WSH = windSnelheid;
  WSH = WSH / 100;
  Serial.print("Snelheid: ");
  Serial.print(WSH);
  Serial.println("Kn");

  //Serial.println(a);
  //Serial.println(b);
  //Serial.println(c);
  //Serial.println(d);




  delay(500);
}
