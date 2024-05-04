#ifndef IDATANOTIFYH
#define IDATANOTIFYH
#include <cstdint> // for std::int16_t
class IDataNotifyH
{
public:
  virtual void OnUpdate(std::int16_t registerCodeH) = 0;
};
#endif