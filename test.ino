#include <Wire.h>
#include "SparkFunBME280.h"

BME280 myBME280;

void setup()
{
    Wire.begin();
    Serial.begin(115200);

    if (!myBME280.beginI2C())
    {
        Serial.println("BME280 did not respond. Check wiring!");
        while (1)
            ;
    }
}

void loop()
{
    Serial.print("Humidity [%]: ");
    Serial.println(myBME280.readFloatHumidity());

    Serial.print("Atmospheric Pressure [hPa]: ");
    Serial.println(myBME280.readFloatPressure() / 100.0);

    delay(2000);
}
