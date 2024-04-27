#ifndef USART
#define USART

#include "ifloatdataprovider.h"
#include "itransfer.h"
#include "usart2registers.hpp" // for USART2
#include <iostream> // for std cout
#include <sstream> // for sstream

class Usart: public ITransfer
{
public:
  Usart(IFloatDataProvider& providerT, IFloatDataProvider& providerP, IFloatDataProvider& providerH, IFloatDataProvider& providerD) : mproviderT(providerT), mproviderP(providerP), mproviderH(providerH), mproviderD(providerD) {}
  void TransferData() override 
  {
    mproviderT.GetData(&measuredT);
    mproviderP.GetData(&measuredP);
    mproviderH.GetData(&measuredH);
    mproviderD.GetData(&measuredD);
    std::size_t i = 0;
    constexpr auto temperatureText = "Temperature: ";
    constexpr auto pressText = "Press: ";
    constexpr auto humidityText = "Humidity: ";
    constexpr auto dewPointText = "DewPoint: ";
    constexpr auto spaceText = " ";
    std::string message{ (temperatureText) + to_string_with_precision(measuredT) + spaceText + pressText + to_string_with_precision(measuredP) + spaceText + (humidityText) + to_string_with_precision(measuredH) + spaceText + dewPointText + to_string_with_precision(measuredD) };
    
     while(!USART2::SR::TXE::DataRegisterEmpty::IsSet())
    {
    }
    USART2::DR::Write(message[i++]);

    if(i >= message.length())
    {
    i = 0;
    }

  
  }
  
template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 2)
{
std::ostringstream out;
out.precision(n);
out << std::fixed << a_value;
return std::move(out).str();
}
  
  
private:
  float measuredT;
  float measuredP;
  float measuredH;
  float measuredD;
  IFloatDataProvider& mproviderT;
  IFloatDataProvider& mproviderP;
  IFloatDataProvider& mproviderH;
  IFloatDataProvider& mproviderD;
};

#endif