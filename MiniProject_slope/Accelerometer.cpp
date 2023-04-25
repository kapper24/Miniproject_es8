#include "Accelerometer.h"

void Accelerometer::init()
{
   IMU.begin();
}

bool Accelerometer::GetAcceleration()
{
    if (IMU.accelerationAvailable())
    {
        IMU.readAcceleration(x, y, z);
        return (true);
    }
    return (false);   
}