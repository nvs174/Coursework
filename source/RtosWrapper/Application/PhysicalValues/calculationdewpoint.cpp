#include "calculationdewpoint.h"
#include <iostream> // for log()

void DewPoint::Calculation()
{
  constexpr float a = 17.27f; // значение взятые с википедии
  constexpr float b = 237.7f; // значение взятые с википедии, градусы
  constexpr auto divider = 10.0f;
  auto humidity = mdataH.GetData();
  auto temperature = mdataT.GetData();
  float measuredY = ((a * temperature) / (b + temperature))+ std::log(humidity);
  value = (b * measuredY) / (a - measuredY);
  value = value / divider;  
}

float DewPoint::GetData()
{
  return value;
};