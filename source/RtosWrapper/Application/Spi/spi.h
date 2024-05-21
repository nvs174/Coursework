#ifndef SPI
#define SPI
#include "ispi.h" // for mode Spi
#include "spi2fieldvalues.hpp" // for SPI2
#include "spi2registers.hpp"  // for SPI2
#include "gpiobregisters.hpp"  // for GPIOB
#include "registerbme280.h" // for register BME280

class Spi: public ISpi 
{
public:
  
  uint8_t ReadByte(uint8_t byte, uint8_t bytcount) override;
  void WriteByte(uint8_t byte, uint8_t value) override;
};

#endif