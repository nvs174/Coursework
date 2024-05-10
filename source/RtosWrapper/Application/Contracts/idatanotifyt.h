#ifndef IDATANOTIFYT
#define IDATANOTIFYT
#include <cstdint> // for std::int16_t
class IDataNotifyT
{
public:
  virtual void OnUpdate(std::uint16_t digRegT1, std::int16_t digRegT3, std::int32_t registerCodeT) = 0;
};
#endif