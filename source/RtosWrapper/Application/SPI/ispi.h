#ifndef ISPI
#define ISPI

class ISpi
{
public:
  virtual void ModeWrite(uint8_t reg, uint8_t value) = 0;
  virtual int8_t ModeRead(uint8_t reg) = 0;
};
#endif