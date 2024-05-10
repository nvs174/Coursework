#ifndef PRESS
#define PRESS
#include "idatanotifyp.h" // for IDataNotifyp
#include "imeasurementsupdate.h" // for IMeasurementsUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider       

class Press: public IFloatDataProvider, public IMeasurementsUpdate, public IDataNotifyP
{
public:
  void Calculation() override;  
  void OnUpdate(int32_t registerCodeP)  override;  
  float GetData() override;

private:
   int32_t adcP;
   float value;
    
};
#endif