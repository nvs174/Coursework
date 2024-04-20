#ifndef MEASURETASK
#define MEASURETASK

#include "thread.hpp" // for OsWrapper::Thread<>
#include "imeasurementscontroller.h" // for update register


class MeasureTask: public OsWrapper::Thread<128> 
{
public:
  //MeasureTask(IMeasurementsController& controller, IMeasurementsUpdate& update) : mController(controller), mUpdate(mUpdate) {}
  MeasureTask(IMeasurementsController& controller) : mController(controller){}
  virtual void Execute() override 
  {
    for (;;) 
    {
      mController.Update();
      //mUpdate.UpdateCalc();
      Sleep(100ms);
    }
  
  }
  
  
private:
  IMeasurementsController& mController;
  //IMeasurementsUpdate& mUpdate;

};

#endif
