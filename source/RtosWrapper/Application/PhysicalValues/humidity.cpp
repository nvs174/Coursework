#include "humidity.h"

void Humidity::Calculation() 
{
  constexpr auto resolutionHumidity = 0.008f;
  constexpr auto divider = -10.0f;
  value = (static_cast<float>(adcH) ) * resolutionHumidity / divider;
}

void Humidity::OnUpdate(int16_t registerCodeH)
{
  adcH = registerCodeH;
}

float Humidity::GetData() 
{
  return value;
};





