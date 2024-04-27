#ifndef HUMIDITY
#define HUMIDITY

#include "idatanotifyh.h" // for IDataNotifyH
#include "imeasurementsupdate.h" // for IMeasurementsUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider 
#include <iostream> // for std::

class Humidity: public IFloatDataProvider, public IMeasurementsUpdate, public IDataNotifyH
{
public:
  void UpdateCalc() override // uses IMeasurementsUpdate
  {
    measuredH = adcH * 0.008;
    std::cout << "Влажность 50%" << std::endl; // TODO удалить потом 
  }
    
  void  OnUpdate(int16_t registerCodeH)  override  // uses IDataNotifyH
  {
    adcH = registerCodeH;
  }
    
  void GetData(float* data)  override // uses IFloatDataProvider
  {
    measuredH = 22.0f;
    *data =  measuredH;// TODO удалить потом
  } 
private:
   int16_t adcH;
   float measuredH;  
};
#endif