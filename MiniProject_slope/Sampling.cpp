#include "api/Common.h"
#include "Sampling.h"

Sampling::Sampling(long sampling_Time)
{
    Ts = sampling_Time;
    offset = sampling_Time;
}

bool Sampling::Sample()
{
  if (millis() - offset >= Ts)
  {
    offset = millis();
    return (true);
  }
  else
  {
    return (false);
  }
}

int Sampling::GetSamplingTime()
{
  return (Ts);
}