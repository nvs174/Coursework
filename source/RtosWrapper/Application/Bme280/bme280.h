#ifndef BME280
#define BME280

#include "imeasurementscontroller.h" // for Update()
#include "idatanotifyt.h" // for mdataT(dataT)
#include "idatanotifyp.h" // for mdataP(dataP)
#include "idatanotifyh.h" // for mdataH(dataH)
#include "registerbme280.h" // for BME280_REGISTER_
#include "spi.h" // for spi
#include "ibme280.h" // for Init BME280

class Bme280: public IMeasurementsController, public IBme280
{
  
public:
  Bme280(ISpi& spi, IDataNotifyT& dataT, IDataNotifyP& dataP, IDataNotifyH& dataH) : mspi(spi), mdataT(dataT), mdataP(dataP), mdataH(dataH) {}
  
  void Update() override;
  void InittBme280() override;
  
private:
  uint16_t digRegT1;
  int16_t digRegT3;
  int32_t registerCodeT;
  int32_t registerCodeP;
  int16_t registerCodeH;
  uint8_t resalt;
  
  ISpi& mspi;  
  IDataNotifyT& mdataT;
  IDataNotifyP& mdataP;
  IDataNotifyH& mdataH;
};
#endif