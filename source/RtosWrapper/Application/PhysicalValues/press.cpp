#ifndef PRESS
#define PRESS
#include "idatanotifyp.h" // for IDataNotifyp
#include "imeasurementsupdate.h" // for IMeasurementsUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider       
class Press: public IFloatDataProvider, public IMeasurementsUpdate, public IDataNotifyP
{
public:
  void Calculation() override // uses IMeasurementsUpdate
  {
    value = (static_cast<float>(adcP) / 16.0f) * 0.18f;
  }
    
  void  OnUpdate(int32_t registerCodeP)  override  // uses IDataNotifyP
  {
    adcP = registerCodeP;
  }
    
  float GetData() override  // uses IFloatDataProvider
  {
   return value;
  } 
  
private:
   int32_t adcP;
   float value;
    
};
#endif