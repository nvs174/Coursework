#ifndef IDATANOTIFYP
#define IDATANOTIFYP
#include <iostream> // for int32_t
class IDataNotifyP
{
public:
  virtual void OnUpdate(int32_t registerCodeP) = 0;
};
#endif