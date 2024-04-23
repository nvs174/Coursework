#ifndef ISPI
#define ISPI

#include <iostream>
class ISpi
{
public:
  virtual void WriteByte(uint8_t reg, uint8_t value) = 0;
  virtual uint8_t ReadByte(uint8_t reg) = 0;
  virtual void ReadWord(uint8_t reg, int16_t* value) = 0;
  virtual void ReadWord(uint8_t reg, uint16_t* value) = 0;
  virtual void ReadWord(uint8_t reg, int32_t* value) = 0;
};
#endif