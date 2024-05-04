#include "humidity.h"

void Humidity::Calculation() 
{
  constexpr auto resolutionHumidity = 0.008f;
  value = static_cast<float>(adcH) * resolutionHumidity;
}

void Humidity::OnUpdate(int16_t registerCodeH)
{
  adcH = registerCodeH;
}

float Humidity::GetData() 
{
  value = 22;
  return value;
};





