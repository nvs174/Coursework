#ifndef HUMIDITY
#define HUMIDITY
#include "idatanotifyh.h" // for IDataNotifyH
#include "imeasurementsupdate.h" // for IMeasurementsUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider 

class Humidity: public IFloatDataProvider, public IMeasurementsUpdate, public IDataNotifyH
{
public:
  void Calculation() override // uses IMeasurementsUpdate
  {
    value = static_cast<float>(adcH) * 0.008f;
  }
    
  void  OnUpdate(int16_t registerCodeH)  override  // uses IDataNotifyH
  {
    adcH = registerCodeH;
  }
    
  float GetData()  override // uses IFloatDataProvider
  {
    return value;
  } 
  
private:
   int16_t adcH;
   float value;  
};
#endif