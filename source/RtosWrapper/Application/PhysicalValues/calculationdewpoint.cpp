#include "calculationdewpoint.h"


void DewPoint::Calculation()
{
  constexpr float a = 17.27f; // �������� ������ � ���������
  constexpr float b = 237.7f; // �������� ������ � ���������, �������
  const auto temperature = mdataT.GetData();
  const auto humidity = mdataH.GetData();
  float measuredY = ((a * temperature) / (b + temperature)); //+ log(humidity);
  value = (b * measuredY) / (a - measuredY);
}
 
  
float DewPoint::GetData()
{
  return value;
};