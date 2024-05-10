#ifndef ISPI
#define ISPI
class ISpi
{
public: // TODO исправить функции, пока что используется как затычка
  virtual void WriteByte() = 0;
  virtual void ReadByte() = 0;
  virtual void ReadWord() = 0;
};
#endif