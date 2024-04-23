#ifndef HUMIDITY
#define HUMIDITY

#include "idatanotifyH.h" // for IDataNotifyH
#include "imeasurementsupdate.h" // for IMeasurementsUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider 
#include <iostream>

class Humidity: public IFloatDataProvider, public IMeasurementsUpdate, public IDataNotifyH
{
public:
  void UpdateCalc() override // uses IMeasurementsUpdate
  {
    std::cout << "Влажность 50%" << std::endl; // TODO удалить потом 
    
  }
    
  void  OnUpdate(int16_t registerCodeH)  override  // uses IDataNotifyH
  {
    
  }
    
  float GetData() override  // uses IFloatDataProvider
  {
   return 1;
  } 
};
#endif