#ifndef TEMPERATURE
#define TEMPERATURE

#include "idatanotifyt.h" // for IDataNotifyT
#include "imeasurementsupdate.h" // for IMeasurementsUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider 
#include <iostream> // for std::

class Temperature: public IFloatDataProvider, public IMeasurementsUpdate, public IDataNotifyT
{
  public:
    
  void  OnUpdate(uint16_t digRegT1, int16_t digRegT3, int32_t registerCodeT)  override  // // uses IDataNotifyT
  {
    adcT = registerCodeT;
    digT1 = digRegT1;
    digT3 = digRegT3;
  }
  
   void UpdateCalc() override // uses IMeasurementsUpdate
  {
    auto measuredX = ((adcT / 16) - digT1);
    measuredT = measuredX * digT1 + ((measuredX * measuredX * digT3) / 65536);
    measuredT = measuredT / 1024;
    std::cout << "Температатура = 25 градусов" << std::endl; // TODO удалить потом 
  }
    
  void GetData(float* data) override // uses IFloatDataProvider
  {
    measuredT = 20.0f; // TODO удалить потом
    *data = measuredT;
  }  
  
private:
  float measuredT;
  uint16_t digT1;
  int16_t digT3;
  int32_t adcT; 
};
#endif