#ifndef SPI
#define SPI
#include "ispi.h" // for mode Spi

class Spi: public ISpi 
{
public:
  
  void WriteByte(uint8_t reg,uint8_t value) override 
  {
    std::cout << "записали бит в указанный регистр" << std::endl; // TODO убрать
  }
  uint8_t ReadByte(uint8_t reg) override 
  {
    std::cout << "считали байт указанного регистра" << std::endl; // TODO убрать
    return 1;
  }
  void ReadWord(uint8_t reg, int16_t *value) override 
  {
    std::cout << "Dig_T3, влажность есть (2)" << std::endl; // TODO убрать
    *value = 1;
  }
  
  
  void ReadWord(uint8_t reg, uint16_t *value) override 
  {
    std::cout << "Dig_T1, влажность есть (1)" << std::endl; // TODO убрать
    *value = 2;
  }
  void ReadWord(uint8_t reg, int32_t *value) override // TODO убрать
  {
    std::cout << "давление, темп есть (3)" << std::endl; // TODO убрать
    *value = 3;
  }
  
  
private:

};

#endif