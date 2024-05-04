#include "press.h"

void Press::Calculation() 
{
  constexpr auto bitShiftRight = 16.0f;
  constexpr auto resolutionPressure = 0.18f;
  value = (static_cast<float>(adcP) / bitShiftRight) * resolutionPressure;

}

void Press::OnUpdate(int32_t registerCodeP) 
{
  adcP = registerCodeP;
}

float Press::GetData() 
{
  return value;
};
