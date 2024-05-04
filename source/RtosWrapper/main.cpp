#include "rtos.hpp"         // for Rtos

#include "rccregisters.hpp" // for RCC

#include "bme280.cpp" // for BME290
#include "sendtask.cpp" // for send task
#include "measuretask.cpp" // for Measure task
#include "humidity.cpp" // for Humidity 
#include "press.cpp" // for Press
#include "temperature.cpp" // for Temperature
#include "spi.cpp" // for SPI
#include "calculationdewpoint.cpp" // for DewPoint
#include "usart.cpp" // for USART
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
MeasureTask measureTask (bme, temp, press, hum, point);
int main()
{
  using namespace OsWrapper;
  Rtos::CreateThread(measureTask, "measureTask"); 
  Rtos::Start();
  return 0;
}
