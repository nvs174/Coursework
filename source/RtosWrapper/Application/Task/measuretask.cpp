#include "measuretask.h"

void MeasureTask :: Execute() 
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
};