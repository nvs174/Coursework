#ifndef SPI
#define SPI
#include "ispi.h" // for ModSPI
#include "spi2registers.hpp" // for SPI2
#include "gpiobregisters.hpp"  // for GPIOB
class Spi: public ISpi 
{
public:
  void ModeWrite(uint8_t reg, uint8_t value) override 
  {
    tx[1]={0};
    rx[1] = {0};
    tx[0] = reg | 0x7F;
    rx[0] = value;
    GPIOB::ODR::ODR12::Low::Set();
    SPI2::DR::Write(tx[0]);
    SPI2::DR::Write(rx[0]);
    while(!SPI2::SR::BSY::NotBusy::IsSet()) {}
    GPIOB::ODR::ODR12::High::Set();
  }
  

  int8_t ModeRead(uint8_t reg) override 
  {
    tx[1]={0};
    tx[0]= reg | 0x80;
    GPIOB::ODR::ODR12::Low::Set();
    SPI2::DR::Write(tx[0]);
    while(!SPI2::SR::BSY::NotBusy::IsSet()) {}
    GPIOB::ODR::ODR12::High::Set();
    return static_cast<std::uint8_t> (SPI2::DR::Get());
  }
  
  
  uint16_t ModeReadGidT1(uint8_t reg) override 
  {
    tx[1]={0};
    tx[0]= reg | 0x80;
    GPIOB::ODR::ODR12::Low::Set();
    SPI2::DR::Write(tx[0]);
    while(!SPI2::SR::BSY::NotBusy::IsSet()) {}
    GPIOB::ODR::ODR12::High::Set();
    return static_cast<std::uint16_t> (SPI2::DR::Get());
  }
  
  int16_t ModeReadGidT3(uint8_t reg) override 
  {
    tx[1]={0};
    tx[0]= reg | 0x80;
    GPIOB::ODR::ODR12::Low::Set();
    SPI2::DR::Write(tx[0]);
    while(!SPI2::SR::BSY::NotBusy::IsSet()) {}
    GPIOB::ODR::ODR12::High::Set();
    return static_cast<std::int16_t> (SPI2::DR::Get());
  }
 
  int32_t ModeReadTempPress(uint8_t reg) override 
  {
    tx[1]={0};
    tx[0]= reg | 0x80;
    GPIOB::ODR::ODR12::Low::Set();
    SPI2::DR::Write(tx[0]);
    while(!SPI2::SR::BSY::NotBusy::IsSet()) {}
    GPIOB::ODR::ODR12::High::Set();
    return static_cast<std::int32_t> (SPI2::DR::Get());
  
  }
  
  
  int16_t ModeReadHam(uint8_t reg) override 
  {
    tx[1]={0};
    tx[0]= reg | 0x80;
    GPIOB::ODR::ODR12::Low::Set();
    SPI2::DR::Write(tx[0]);
    while(!SPI2::SR::BSY::NotBusy::IsSet()) {}
    GPIOB::ODR::ODR12::High::Set();
    return static_cast<std::int16_t> (SPI2::DR::Get());
  }
  
  
private:
  uint8_t tx[1];
  uint8_t rx[1];
 
};

#endif