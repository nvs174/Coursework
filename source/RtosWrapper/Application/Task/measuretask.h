#ifndef MEASURETASK
#define MEASURETASK

#include "thread.hpp" // for OsWrapper::Thread<>
#include "imeasurementscontroller.h" // for update register
#include "imeasurementsupdate.h" // for update Calculation
using namespace OsWrapper;

class MeasureTask: public OsWrapper::Thread<512> 
{
public:
  MeasureTask(IMeasurementsController& controller, IMeasurementsUpdate& updateT, IMeasurementsUpdate& updateH, IMeasurementsUpdate& updateP, IMeasurementsUpdate& updatePoint) : mController(controller), temperature(updateT), humidity(updateH), pressure(updateP), dewpoint(updatePoint) {}
  virtual void Execute() override;
private:
  IMeasurementsController& mController;
  IMeasurementsUpdate& temperature;
  IMeasurementsUpdate& humidity;
  IMeasurementsUpdate& pressure;
  IMeasurementsUpdate& dewpoint;
};

#endif