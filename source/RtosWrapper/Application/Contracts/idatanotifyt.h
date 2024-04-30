#ifndef IDATANOTIFYT
#define IDATANOTIFYT
#include <iostream> // for uint16_t, int16_t, int32_t
class IDataNotifyT
{
public:
  virtual void OnUpdate(uint16_t digRegT1, int16_t digRegT3, int32_t registerCodeT) = 0;
};
#endif