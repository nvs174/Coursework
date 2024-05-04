#include "temperature.h"

void Temperature::OnUpdate(uint16_t digRegT1, int16_t digRegT3, int32_t registerCodeT) 
{
  adcT = registerCodeT;
  digT1 = digRegT1;
  digT3 = digRegT3;
}

 void Temperature::Calculation()
{
  auto bitShiftRight1 = 16.0f;
  auto bitShiftRight2 = 1024.0f;
  auto maxValueint16 = 65536.0f;
  auto measuredX = ((static_cast<float>(adcT) / bitShiftRight1) - static_cast<float>(digT1));
  temperature = measuredX * static_cast<float>(digT1) + ((measuredX * measuredX * static_cast<float>(digT3)) / maxValueint16);
  temperature = temperature / bitShiftRight2;
}
   float Temperature::GetData()
{
  temperature = 23;
  return temperature;
}  
 


