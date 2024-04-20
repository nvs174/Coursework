#ifndef MEASURETASK
#define MEASURETASK

#include "thread.hpp" // for OsWrapper::Thread<>
#include "imeasurementscontroller.h" // for update register


class MeasureTask: public OsWrapper::Thread<128> 
{
public:
    MeasureTask(IMeasurementsController& controller) : mController(controller){}
  virtual void Execute() override 
  {
    for (;;) 
    {
      mController.Update();
      Sleep(100ms);
    }
  
  }
  
  
private:
  IMeasurementsController& mController;
};

#endif
