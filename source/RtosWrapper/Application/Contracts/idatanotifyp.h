#ifndef IDATANOTIFYP
#define IDATANOTIFYP
#include <cstdint> // for std::int32_t
class IDataNotifyP
{
public:
  virtual void OnUpdate(std::int32_t registerCodeP) = 0;
};
#endif