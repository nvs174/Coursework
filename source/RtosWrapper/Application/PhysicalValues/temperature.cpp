#ifndef TEMPERATURE
#define TEMPERATURE

#include "idatanotifyt.h" // for IDataNotifyT
#include "imeasurementsupdate.h" // for IMeasurementsUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider 
class Temperature: public IFloatDataProvider, public IMeasurementsUpdate, public IDataNotifyT
{
  public:
    
  void  OnUpdate(uint16_t digRegT1, int16_t digRegT3, int32_t registerCodeT)  override  // // uses IDataNotifyT
  {
    adcT = registerCodeT;
    digT1 = digRegT1;
    digT3 = digRegT3;
  }
  
   void Calculation() override // uses IMeasurementsUpdate
  {
    auto measuredX = ((static_cast<float>(adcT) / 16.0f) - static_cast<float>(digT1));
    temperature = measuredX * static_cast<float>(digT1) + ((measuredX * measuredX * static_cast<float>(digT3)) / 65536.0f);
    temperature = temperature / 1024.0f;
  }
    
  float GetData() override // uses IFloatDataProvider
  {
    return temperature;
  }  
  
private:
  float temperature;
  uint16_t digT1;
  int16_t digT3;
  int32_t adcT; 
};
#endif