#include "usart.h"

void Usart::TransferData()
{
  temperature = mproviderT.GetData();
  pressure = mproviderT.GetData();
  humidity = mproviderT.GetData();
  dewPoint = mproviderT.GetData();
  std::size_t i = 0;
  constexpr auto temperatureText = "Temperature: ";
  constexpr auto pressText = "Press: ";
  constexpr auto humidityText = "Humidity: ";
  constexpr auto dewPointText = "DewPoint: ";
  constexpr auto spaceText = " ";
  std::string message{ (temperatureText) + to_string_with_precision(temperature) + spaceText + pressText + to_string_with_precision(pressure) + spaceText + (humidityText) + to_string_with_precision(humidity) + spaceText + dewPointText + to_string_with_precision(dewPoint) };
  
   while(!USART2::SR::TXE::DataRegisterEmpty::IsSet())
  {
  }
  USART2::DR::Write(message[i++]);

  if(i >= message.length())
  {
  i = 0;
  }
};