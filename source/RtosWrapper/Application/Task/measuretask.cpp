#ifndef MEASURETASK
#define MEASURETASK
#include "thread.hpp" // for OsWrapper::Thread<>
#include "imeasurementscontroller.h" // for update register
#include "imeasurementsupdate.h" // for update calculation

class MeasureTask: public OsWrapper::Thread<128> 
{
public:
  MeasureTask(IMeasurementsController& controller, IMeasurementsUpdate& updateT, IMeasurementsUpdate& updateH, IMeasurementsUpdate& updateP, IMeasurementsUpdate& updatePoint) : mController(controller), temperature(updateT), humidity(updateH), pressure(updateP), dewpoint(updatePoint) {}
  void Execute() override 
  {
    for (;;) 
    {
      mController.Update();
      temperature.Calculation();
      humidity.Calculation();
      pressure.Calculation();
      dewpoint.Calculation();
      Sleep(100ms);
    }
  }
private:
  IMeasurementsController& mController;
  IMeasurementsUpdate& temperature;
  IMeasurementsUpdate& humidity;
  IMeasurementsUpdate& pressure;
  IMeasurementsUpdate& dewpoint;
};

#endif