#include "bme280.h"

void Bme280::Update() 
{
  //GPIOB::ODR::ODR12::High::Set();
  // TODO удалить до
  uint8_t rx[1] = {5};
  while(!SPI2::SR::BSY::NotBusy::IsSet()) {}
  GPIOB::ODR::ODR12::Low::Set();
  SPI2::DR::Write(BME280_REG_ID);
  rx[0] = SPI2::DR::Get();
  while(!SPI2::SR::BSY::NotBusy::IsSet()) {}
  
  GPIOB::ODR::ODR12::High::Set();
  // TODO сюда   
  
  
  
  
  
  
  
  
  
  
  
  //resalt = mspi.ReadByte(BME280_REG_ID);
  
  //mspi.ReadWord(BME280_REGISTER_DIG_T1, &digRegT1);
  //mspi.ReadWord(BME280_REGISTER_DIG_T3, &digRegT3);
  //mspi.ReadWord(BME280_REGISTER_TEMPDATA, &registerCodeT);
  //mspi.ReadWord(BME280_REGISTER_PRESS, &registerCodeP);
  //mspi.ReadWord(BME280_REGISTER_HUMIDDATA, &registerCodeH);
  
  mdataT.OnUpdate(digRegT1,digRegT3,registerCodeT);
  mdataP.OnUpdate(registerCodeP);
  mdataH.OnUpdate(registerCodeH);
};
