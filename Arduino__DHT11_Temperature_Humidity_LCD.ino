//
//    FILE: dht11_test.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.2
// PURPOSE: DHT library test sketch for DHT11 && Arduino
//     URL: https://github.com/RobTillaart/DHTstable
//
// HISTORY:
// 0.1.2  add URL in header

#include <dht.h>

dht DHT;

#define DHT11_PIN A0
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup()
{
  Serial.begin(115200);
  Serial.println("DHT TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT_LIB_VERSION);
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");

  // Print a message to the LCD.
  

  lcd.begin(16, 2);
  //lcd.print("Temp:");
  delay(1000);
}

void loop()
{  
  
  // READ DATA
  Serial.print("DHT11, \t");
  int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
    Serial.print("OK,\t"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    Serial.print("Checksum error,\t"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.print("Time out error,\t"); 
    break;
    default: 
    Serial.print("Unknown error,\t"); 
    break;
  }
  // DISPLAY DATA
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  Serial.println(DHT.temperature, 1);
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
  lcd.setCursor(12, 0);
  lcd.print(DHT.temperature,1);
  lcd.setCursor(0, 1);
  lcd.print("Humidity:");
  lcd.setCursor(12, 1);
  lcd.print(DHT.humidity, 1);

  delay(2000);
}
//
// END OF FILE
//
