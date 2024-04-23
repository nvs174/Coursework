#ifndef IDATANOTIFYH
#define IDATANOTIFYH
#include <iostream>
class IDataNotifyH
{
public:
  virtual void OnUpdate(int16_t registerCodeH) = 0;
};
#endif