#include "Arduino_LSM6DS3.h"

class Accelerometer
{
public:
    void init();

    [[nodiscard]] bool GetAcceleration();

    float x{0};
    float y{0};
    float z{0};

private:
};