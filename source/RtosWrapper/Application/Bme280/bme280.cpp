#ifndef BME280
#define BME280

#include "imeasurementscontroller.h"
#include "ispi.h"
#include "spi2registers.hpp"
#include "idatanotifyt.h"
#include "idatanotifyp.h"
#include "idatanotifyh.h"

#include <iostream>

class Bme280: public IMeasurementsController
{
  
public:
  //Bme280(ISpi& spi, IDataNotifyT& dataT, IDataNotifyP& dataP, IDataNotifyH& dataH) : mspi(spi), mdataT(dataT), mdataP(dataP), mdataH(dataH) {}
  Bme280(ISpi& spi, IDataNotifyT& dataT) : mspi(spi), mdataT(dataT) {}
  
  void Update() override 
  { /*
    mspi.ModeRead(BME280_REGISTER_DIG_T1);
    digRegT1 = SPI2::DR::Get();
    GPIOB::ODR::ODR12::High::Set();
    
    mspi.ModeRead(BME280_REGISTER_DIG_T3);
    digRegT3 = SPI2::DR::Get();
    GPIOB::ODR::ODR12::High::Set();
    
    mspi.ModeRead(BME280_REGISTER_TEMPDATA);
    registerCodeT = SPI2::DR::Get();
    GPIOB::ODR::ODR12::High::Set();
    
    mspi.ModeRead(BME280_REGISTER_PRESS);
    registerCodeP = SPI2::DR::Get();
    GPIOB::ODR::ODR12::High::Set();
    
    mspi.ModeRead(BME280_REGISTER_HUMIDDATA);
    registerCodeH = SPI2::DR::Get();
    GPIOB::ODR::ODR12::High::Set();
    
    mdataT.OnUpdate(registerCodeT, digRegT1, digRegT3);
    
    mdataP.OnUpdate(registerCodeP);
    
    mdataH.OnUpdate(registerCodeH);*/
    
    /*mspi.ModeRead(BME280_REG_ID);
    id = SPI2::DR::Get();
    GPIOB::ODR::ODR12::High::Set();
    
    if (id == 0) 
    {
      std::cout << "Id net" << std::endl; 
       ;
    }
    else 
    {
      std::cout << "Id yes" << std::endl;
    } */
    //mspi.ModeRead(BME280_REG_ID);
    //id = SPI2::DR::Get();
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
  
  IDataNotifyT& mdataT;
  
  //IDataNotifyP& mdataP;
  
  //IDataNotifyH& mdataH;
  
};
#endif