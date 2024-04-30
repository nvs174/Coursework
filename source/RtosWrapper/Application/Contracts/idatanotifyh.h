#ifndef IDATANOTIFYH
#define IDATANOTIFYH
#include <iostream> // for int16_t
class IDataNotifyH
{
public:
  virtual void OnUpdate(int16_t registerCodeH) = 0;
};
#endif