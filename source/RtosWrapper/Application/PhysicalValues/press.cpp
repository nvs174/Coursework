#ifndef PRESS
#define PRESS

#include "idatanotifyp.h" // for IDataNotifyp
#include "imeasurementsupdate.h" // for IMeasurementsUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider 
#include <iostream> // for std::

class Press: public IFloatDataProvider, public IMeasurementsUpdate, public IDataNotifyP
{
public:
  void UpdateCalc() override // uses IMeasurementsUpdate
  {
    measuredP = (adcP / 16) * 0.18f;
    std::cout << "�������� = 5" << std::endl; // TODO ������� ����� 
  }
    
  void  OnUpdate(int32_t registerCodeP)  override  // uses IDataNotifyP
  {
    adcP = registerCodeP;
  }
    
  void GetData(float* data) override  // uses IFloatDataProvider
  {
    measuredP = 21.0f;
   *data = measuredP;
  } 
private:
   int32_t adcP;
   float measuredP;
    
};
#endif