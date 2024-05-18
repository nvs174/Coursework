#include "press.h"
#include <iostream> // TODO удалить
void Press::Calculation() 
{
  constexpr auto bitShiftRight = 16.0f;
  constexpr auto resolutionPressure = 0.18f;
  constexpr auto  calibMRSTST= 1.333f;
  constexpr auto divider = 100.0f;
  value = (static_cast<float>(adcP) / bitShiftRight) * resolutionPressure;
  value = (value / divider) / calibMRSTST;
}

void Press::OnUpdate(int32_t registerCodeP) 
{
  adcP = registerCodeP;
}

float Press::GetData() 
{
  return value;
};
