#ifndef DEWPOINT
#define DEWPOINT

#include "imeasurementsupdate.h" // for IMeasurementsUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider 
#include <iostream> // for std::

class DewPoint: public IFloatDataProvider, public IMeasurementsUpdate
{
public:
  DewPoint(IFloatDataProvider& dataT, IFloatDataProvider& dataH) : mdataT(dataT), mdataH(dataH) {}
  void Calculation() override // uses IMeasurementsUpdate
  {
    constexpr float a = 17.27f;
    constexpr float b = 237.7f;        
    const auto measuredT = mdataT.GetData();
    const auto measuredH = mdataH.GetData();
    float measuredY = ((a * measuredT) / (b + measuredT)) + log(measuredH);
    value = (b * measuredY) / (a - measuredY);
  }
   
    
  float GetData() override  // uses IFloatDataProviderD
  {
    return value;
  }
private:
  
  float value; 
  IFloatDataProvider& mdataT;
  IFloatDataProvider& mdataH;
};
#endif