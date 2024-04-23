#ifndef IDATANOTIFY
#define IDATANOTIFY

class IDataNotify 
{
public:
  
  virtual void OnUpdate(uint16_t digRegT1, int16_t digRegT3, int32_t registerCodeT)
  //virtual bool OnUpdate() = 0;
  //uint16_t digRegT1;
  //int16_t digRegT3;
  //int32_t registerCodeT;
  //int32_t registerCodeP;
  //int16_t registerCodeH;
  
};
#endif