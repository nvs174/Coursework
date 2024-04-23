#include "rtos.hpp"         // for Rtos

#include "rccregisters.hpp" // for RCC

#include "gpiobregisters.hpp"  // for GPIOB

#include "spi2fieldvalues.hpp" // for SPI2


#include "imeasurementscontroller.h"
#include "ifloatdataprovider.h"
#include "imeasurementsupdate.h"
#include "idatanotifyt.h"
#include "idatanotifyp.h"
#include "idatanotifyh.h"
#include "ispi.h"
#include "idatanotifyt.h"
#include "ibme280.h"
#include "registerbme280.h"

#include "bme280.cpp"
#include "measuretask.cpp"
#include "humidity.cpp"
#include "press.cpp"
#include "temperature.cpp"
#include "spi.cpp"
#include "calculationdewpoint.cpp"
std::uint32_t SystemCoreClock = 16'000'000U;


extern "C" {
int __low_level_init(void)
{
  return 1;
}
}

Temperature temp;
Press press;
Humidity hum;
DewPoint point;
Spi spi;
Bme280 bme(spi, temp, press, hum);
MeasureTask measureTask (bme, temp, press, hum, point);

int main()
{
    
  using namespace OsWrapper;
  Rtos::CreateThread(measureTask, "measureTask");
  
  Rtos::Start();

  return 0;
}
