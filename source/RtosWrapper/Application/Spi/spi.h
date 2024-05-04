#ifndef SPI
#define SPI
#include "ispi.h" // for mode Spi

#include "spi2fieldvalues.hpp" // for SPI2
#include "spi2registers.hpp"
#include "gpiobregisters.hpp"  // for GPIOB

class Spi: public ISpi 
{
public:
  
   void WriteByte() override; 
   void ReadByte() override;
   void ReadWord() override; 
  
private:

};

#endif