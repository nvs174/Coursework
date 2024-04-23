#ifndef TEMPERATURE
#define TEMPERATURE

#include "idatanotifyt.h" // for IDataNotifyT
#include "imeasurementsupdate.h" // for IMeasurementsUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider 
#include <iostream>

class Temperature: public IFloatDataProvider, public IMeasurementsUpdate, public IDataNotifyT
{
  public:
  

  void UpdateCalc() override // uses IMeasurementsUpdate
  {
    measuredX = ((adcT / 16) - digT1);
    measuredT = measuredX * digT1 + ((measuredX * measuredX * digT3) / 65536);
    measuredT = measuredT / 1024;
    std::cout << "Температатура = 25 градусов" << std::endl; // TODO удалить потом 
    
  }
    
  void  OnUpdate(uint16_t digRegT1, int16_t digRegT3, int32_t registerCodeT)  override  // // uses IDataNotifyT
  {
    adcT = registerCodeT;
    
    digT1 = digRegT1;
    
    digT3 = digRegT3;
  }
    
  float GetData() override  // uses IFloatDataProvider
  {
    return measuredT;
  }  
private:
  float measuredX;
  float measuredT;
  uint16_t digT1;
  int16_t digT3;
  int32_t adcT; 
};
#endif