#include "calculationdewpoint.h"


void DewPoint::Calculation()
{
  constexpr float a = 17.27f; // значение взятые с википедии
  constexpr float b = 237.7f; // значение взятые с википедии, градусы
  auto temperature = mdataT.GetData();
  auto humidity = mdataH.GetData();
  float measuredY = ((a * temperature) / (b + temperature)); //TODO поправить + log(humidity);
  value = (b * measuredY) / (a - measuredY);
}
 
  
float DewPoint::GetData()
{
  return value;
};