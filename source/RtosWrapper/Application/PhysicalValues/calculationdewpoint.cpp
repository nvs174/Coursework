#ifndef DEWPOINT
#define DEWPOINT

#include "imeasurementsupdate.h" // for IMeasurementsUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider 
#include <iostream>

class DewPoint: public IFloatDataProvider, public IMeasurementsUpdate
{
public:
  void UpdateCalc() override // uses IMeasurementsUpdate
  {
    std::cout << "����� ���� 222" << std::endl; // TODO ������� ����� 
    
  }
   
    
  float GetData() override  // uses IFloatDataProvider
  {
   return 1;
  } 
};
#endif