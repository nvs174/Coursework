#ifndef DEWPOINT
#define DEWPOINT

#include "imeasurementsupdate.h" // for IMeasurementsUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider 
#include <iostream> // for std::

class DewPoint: public IFloatDataProvider, public IMeasurementsUpdate
{
public:
  DewPoint(IFloatDataProvider& dataT, IFloatDataProvider& dataH) : mdataT(dataT), mdataH(dataH) {}
  void UpdateCalc() override // uses IMeasurementsUpdate
  {
    float measuredT;
    float measuredH; 
    float const a = 17.27f;
    float const b = 237.7f;
    float measuredY;
        
    mdataT.GetData(&measuredT);
    mdataH.GetData(&measuredH);
    measuredY = ((a * measuredT) / (b + measuredT)) + log(measuredH);
    measuredD = (b * measuredY) / (a - measuredY);
    std::cout << "“очка росы 222" << std::endl; // TODO удалить потом 
    
  }
   
    
  void GetData(float* data) override  // uses IFloatDataProviderD
  {
    measuredD = 23.0f; // TODO удалить потом
   *data = measuredD;
  }
private:
  
  float measuredD; 
  IFloatDataProvider& mdataT;
  IFloatDataProvider& mdataH;
};
#endif