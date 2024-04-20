#ifndef BME280
#define BME280

#include "imeasurementscontroller.h" // for Update 
#include "ispi.h" // for ModSPI
#include "spi2registers.hpp" // for SPI register


#include <iostream>

class Bme280: public IMeasurementsController
{
  
public:
  Bme280(ISpi& spi) : mspi(spi) {}
  
  void Update() override 
  { 
    auto id = mspi.ModeRead(BME280_REG_ID); // TODO чисто для проверки
 
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
  ISpi& mspi;
};
#endif