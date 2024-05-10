#ifndef ISPI
#define ISPI

#include <iostream>
class ISpi
{
public:
  virtual void WriteByte() = 0;
  virtual void ReadByte() = 0;
  virtual void ReadWord() = 0;
};
#endif