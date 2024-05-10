#ifndef DEWPOINT
#define DEWPOINT

#include "imeasurementsupdate.h" // for IMeasurementsUpdate
#include "ifloatdataprovider.h" // for IFloatDataProvider 


class DewPoint: public IFloatDataProvider, public IMeasurementsUpdate
{
public:
  DewPoint(IFloatDataProvider& dataT, IFloatDataProvider& dataH) : mdataT(dataT), mdataH(dataH) {}
  void Calculation() override;
  float GetData() override;
private:
  float value; 
  IFloatDataProvider& mdataT;
  IFloatDataProvider& mdataH;
};
#endif