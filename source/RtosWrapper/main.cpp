#include "rtos.hpp"         // for Rtos

#include "rccregisters.hpp" // for RCC

#include "bme280.h" // for BME290
#include "sendtask.h" // for send task
#include "measuretask.h" // for Measure task
#include "humidity.h" // for Humidity 
#include "press.h" // for Press
#include "temperature.h" // for Temperature
#include "spi.h" // for SPI
#include "calculationdewpoint.h" // for DewPoint
#include "usart.h" // for USART
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
DewPoint point(temp, hum);
Spi spi;
Bme280 bme(spi, temp, press, hum);
Usart usart(temp, press, hum, point);

MeasureTask measureTask (bme, temp, press, hum, point);
int main()
{
  using namespace OsWrapper;
  Rtos::CreateThread(measureTask, "measureTask");  
  Rtos::Start();
  return 0;
}
