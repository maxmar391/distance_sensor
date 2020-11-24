#include <Wire.h> //Import wire library
#include <VL53L0X.h> //Import VL530X library

VL53L0X myDistanceSensor; //Initialize the sensor object

void setup()
{
    Wire.begin();
    
    Serial.begin(9600);
    Serial.println("VL53L0X Test, starting the sensor...");

    myDistanceSensor.init();
    myDistanceSensor.setTimeout(500);
    myDistanceSensor.startContinuous(); //Using continuous time mode place inter-measurement period in ms ex: .startContinuous(100)).

    delay(200);
}

void loop()
{
    int distance = myDistanceSensor.readRangeContinuousMillimeters();
    Serial.print("Distance =");
    Serial.print(distance);
    Serial.println(" mm");
    if (myDistanceSensor.timeoutOccurred())
	{
        Serial.println("TIMEOUT");
    }
    delay(1000);
}
