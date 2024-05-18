#ifndef ISPI
#define ISPI

#include <iostream>
class ISpi
{
public:
  virtual uint8_t ReadByte(uint8_t byte, uint8_t bytcount) = 0;
  virtual void WriteByte(uint8_t byte, uint8_t value) = 0;
};
#endif