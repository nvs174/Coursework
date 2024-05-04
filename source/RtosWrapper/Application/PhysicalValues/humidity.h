#ifndef HUMIDITY
#define HUMIDITY
#include "idatanotifyh.h" // for IDataNotifyH
#include "imeasurementsupdate.h" // for IMeasurementsUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider 

class Humidity: public IFloatDataProvider, public IMeasurementsUpdate, public IDataNotifyH
{
public:
  void Calculation() override;
  void  OnUpdate(int16_t registerCodeH)  override;
  float GetData()  override;
  
private:
   int16_t adcH;
   float value;  
};
#endif