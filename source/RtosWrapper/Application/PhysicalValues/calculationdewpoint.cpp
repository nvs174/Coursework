#ifndef DEWPOINT
#define DEWPOINT
#include "imeasurementsupdate.h" // for IMeasurementsUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider 
class DewPoint: public IFloatDataProvider, public IMeasurementsUpdate
{
public:
  DewPoint(IFloatDataProvider& dataT, IFloatDataProvider& dataH) : mdataT(dataT), mdataH(dataH) {}
  void Calculation() override // uses IMeasurementsUpdate
  {
    constexpr float a = 17.27f;
    constexpr float b = 237.7f;        
    const auto temperature = mdataT.GetData();
    const auto humidity = mdataH.GetData();
    float measuredY = ((a * temperature) / (b + temperature)) + log(humidity);
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