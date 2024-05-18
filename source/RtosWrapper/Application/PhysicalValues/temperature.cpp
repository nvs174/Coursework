#include "temperature.h"
void Temperature::OnUpdate(uint16_t digRegT1, int16_t digRegT3, int32_t registerCodeT) 
{
  adcT = registerCodeT;
  digT1 = digRegT1;
  digT3 = digRegT3;
}

 void Temperature::Calculation()
{
  constexpr auto bitShiftRight1 = 16.00f;
  constexpr auto bitShiftRight2 = 1024.00f;
  constexpr auto maxValueint16 = 65536.00f;
  constexpr auto divider = 10'000.0f;
  auto measuredX = ((static_cast<float>(adcT) / bitShiftRight1) - static_cast<float>(digT1));
  temperature = measuredX * static_cast<float>(digT1) + ((measuredX * measuredX * static_cast<float>(digT3)) / maxValueint16);
  temperature = temperature / bitShiftRight2;
  temperature = temperature / divider;
}
   float Temperature::GetData()
{
  return temperature;
}  
 


