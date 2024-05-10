#ifndef TEMPERATURE
#define TEMPERATURE

#include "idatanotifyt.h" // for IDataNotifyT
#include "imeasurementsupdate.h" // for IMeasurementsUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider 

class Temperature: public IFloatDataProvider, public IMeasurementsUpdate, public IDataNotifyT
{
  public:
  void  OnUpdate(uint16_t digRegT1, int16_t digRegT3, int32_t registerCodeT)  override;
   void Calculation() override;  
  float GetData() override;
private:
  float temperature;
  uint16_t digT1;
  int16_t digT3;
  int32_t adcT; 
};
#endif