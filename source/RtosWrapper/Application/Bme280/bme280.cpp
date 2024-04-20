#ifndef BME280
#define BME280

#include "imeasurementscontroller.h"
#include "ispi.h"
#include "registerbme280.h"

#include <iostream>

class Bme280: public IMeasurementsController
{
  
public:
  Bme280(ISpi& spi) : mspi(spi) {}
  void Update() override 
  { 
    id = mspi.ModeRead(BME280_REG_ID);
 
    if (id == 0) 
    {
      std::cout << "net" << std::endl; 
    }
    else 
    {
      std::cout << "yes" << std::endl;
    } 
    
    
  }
  
  

private: 
  uint8_t id;
  uint16_t digRegT1;
  int16_t digRegT3;
  int32_t registerCodeT;
  int32_t registerCodeP;
  int16_t registerCodeH;
  
  ISpi& mspi;
};
#endif