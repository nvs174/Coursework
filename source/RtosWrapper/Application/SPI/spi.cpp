#ifndef SPI
#define SPI
#include "ispi.h" // for mode Spi

class Spi: public ISpi 
{
public:
  
  void WriteByte(uint8_t reg,uint8_t valu) override 
  {
    std::cout << "�������� ��� � ��������� �������" << std::endl; // TODO ������
  }
  uint8_t ReadByte(uint8_t reg) override 
  {
    std::cout << "������� ���� ���������� ��������" << std::endl; // TODO ������
    return 1;
  }
  void ReadWord(uint8_t reg, int16_t *value) override 
  {
    std::cout << "Dig_T3, ��������� ���� (2)" << std::endl; // TODO ������
    *value = 1;
  }
  
  
  void ReadWord(uint8_t reg, uint16_t *value) override 
  {
    std::cout << "Dig_T1, ��������� ���� (1)" << std::endl; // TODO ������
    *value = 2;
  }
  void ReadWord(uint8_t reg, int32_t *value) override // TODO ������
  {
    std::cout << "��������, ���� ���� (3)" << std::endl; // TODO ������
    *value = 3;
  }
  
  
private:

};

#endif