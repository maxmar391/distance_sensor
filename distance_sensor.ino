#include <Wire.h>
#include "SparkFun_VL53L1X.h"

//Optional interrupt and shutdown pins.
//#define SHUTDOWN_PIN 2
//#define INTERRUPT_PIN 3

SFEVL53L1X distanceSensor;

void setup(void)
{
  Wire.begin();

  Serial.begin(9600);
  Serial.println("VL53L1X Sensor Test");

  if (distanceSensor.init() == false)
    Serial.println("Sensor online!");
}

void loop(void)
{
  distanceSensor.startRanging(); //Write configuration bytes to initiate measurement
  int distance = distanceSensor.getDistance(); //Get the result of the measurement from the sensor
  distanceSensor.stopRanging();

  Serial.print("Distance(mm): ");
  Serial.println(distance);

  delay(1000);
}
