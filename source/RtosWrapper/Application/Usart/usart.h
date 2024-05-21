#ifndef USART
#define USART
#include "ifloatdataprovider.h" // for ifloatdataprovider
#include "itransfer.h" //  for itransfer 
#include "usart2registers.hpp" // for USART2
#include <iostream> // for std cout
#include <sstream> // for sstream
#include <string>
class Usart: public ITransfer
{
public:
  Usart(IFloatDataProvider& providerT, IFloatDataProvider& providerP, IFloatDataProvider& providerH, IFloatDataProvider& providerD) : mproviderT(providerT), mproviderP(providerP), mproviderH(providerH), mproviderD(providerD) {}
  void TransferData() override;
  
template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 2)
{
std::ostringstream out;
out.precision(n);
out << std::fixed << a_value;
return std::move(out).str();
}

private:
  float temperature;
  float pressure;
  float humidity;
  float dewPoint;
  IFloatDataProvider& mproviderT;
  IFloatDataProvider& mproviderP;
  IFloatDataProvider& mproviderH;
  IFloatDataProvider& mproviderD;
};

#endif