#include "Accelerometer.h"
#include "Sampling.h"

// main

constexpr struct
{
  struct
  {
    const int baud {115200};
  } Serial;

  struct
  {
    const unsigned int sampling_milisecond {100};
  }Sample;


  struct
  {
    float Acc_x_bias {0.3899};
    float Acc_y_bias {0.0897};
    float Acc_z_bias {0.9197}; 
  }accelerometer;

}
Constant;
Accelerometer accelerometer;
Sampling sampler(Constant.Sample.sampling_milisecond);

template <typename T> 
void log(String name, T value,String unit, int decimal = 2 ) 
{
  Serial.print(name + ",");
  Serial.print(value,decimal);
  Serial.print(+","+unit + ",");
}

void log_newline(int nr = 1)
{
  for (int i = 1; i<= nr; i++)
  {
    Serial.println();
  }
}

void init_start()
{
  pinMode(13,OUTPUT);
  delay(10000);
  digitalWrite(13,HIGH);
}



void setup()
{
  
  // put your setup code here, to run once:
  

  Serial.begin(Constant.Serial.baud);
  accelerometer.init();
  init_start();
  
  log<int>("Sampling time",sampler.GetSamplingTime(),"mS",1); 
  log_newline(2);


  
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (sampler.Sample())
  {
    if (accelerometer.GetAcceleration())
    {
      log<float>("AccX",accelerometer.x-Constant.accelerometer.Acc_x_bias,"G");
      log<float>("Accy",accelerometer.y-Constant.accelerometer.Acc_y_bias,"G");
      log<float>("Accz",accelerometer.z-Constant.accelerometer.Acc_z_bias,"G");
    }

      log<int>("Time",millis(),"mS",1);
  
    log_newline();
  }
    
}
