#ifndef ISPI
#define ISPI

class ISpi
{
public:
  virtual void ModeWrite(uint8_t reg, uint8_t value) = 0;
  virtual int8_t ModeRead(uint8_t reg) = 0;
  virtual uint16_t ModeReadGidT1(uint8_t reg) = 0;
  virtual int16_t ModeReadGidT3(uint8_t reg) = 0;
  virtual int16_t ModeReadGidT3(uint8_t reg) = 0;
  virtual int32_t ModeReadTempPress(uint8_t Reg) = 0;
  virtual int16_t ModeReadHam(uint8_t Reg) = 0;
};
#endif