#ifndef IDATANOTIFYT
#define IDATANOTIFYT
#include <iostream>

class IDataNotifyT
{
public:
  virtual void OnUpdate(uint16_t digRegT1, int16_t digRegT3, int32_t registerCodeT) = 0;
};
#endif