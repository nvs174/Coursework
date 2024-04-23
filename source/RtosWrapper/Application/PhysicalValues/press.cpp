#ifndef PRESS
#define PRESS

#include "idatanotifyp.h" // for IDataNotifyp
#include "imeasurementsupdate.h" // for IMeasurementsUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider 
#include <iostream>

class Press: public IFloatDataProvider, public IMeasurementsUpdate, public IDataNotifyP
{
public:
  void UpdateCalc() override // uses IMeasurementsUpdate
  {
    std::cout << "Давление = 5" << std::endl; // TODO удалить потом 
    
  }
    
  void  OnUpdate(int32_t registerCodeP)  override  // uses IDataNotifyP
  {
    
  }
    
  float GetData() override  // uses IFloatDataProvider
  {
   return 1;
  } 
};
#endif