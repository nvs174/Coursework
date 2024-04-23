#ifndef MEASURETASK
#define MEASURETASK

#include "thread.hpp" // for OsWrapper::Thread<>
#include "imeasurementscontroller.h" // for update register
#include "imeasurementsupdate.h"

class MeasureTask: public OsWrapper::Thread<128> 
{
public:
  MeasureTask(IMeasurementsController& controller, IMeasurementsUpdate& updateT, IMeasurementsUpdate& updateH, IMeasurementsUpdate& updateP, IMeasurementsUpdate& updatePoint) : mController(controller), mUpdateT(updateT), mUpdateH(updateH), mUpdateP(updateP), mUpdatePoint(updatePoint) {}
  void Execute() override 
  {
    for (;;) 
    {
      mController.Update();
      mUpdateT.UpdateCalc();
      mUpdateH.UpdateCalc();
      mUpdateP.UpdateCalc();
      mUpdatePoint.UpdateCalc();
      Sleep(100ms);
    }
  }
private:
  IMeasurementsController& mController;
  IMeasurementsUpdate& mUpdateT;
  IMeasurementsUpdate& mUpdateH;
  IMeasurementsUpdate& mUpdateP;
  IMeasurementsUpdate& mUpdatePoint;
};

#endif