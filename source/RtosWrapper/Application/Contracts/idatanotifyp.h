#ifndef IDATANOTIFYP
#define IDATANOTIFYP
#include <iostream>
class IDataNotifyP
{
public:
  virtual void OnUpdate(int32_t registerCodeP) = 0;
};
#endif