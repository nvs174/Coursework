#include "rtos.hpp"         // for Rtos

#include "rccregisters.hpp" // for RCC

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
MeasureTask measureTask (bme, temp, press, hum, point);
int main()
{
  using namespace OsWrapper;
  Rtos::CreateThread(measureTask, "measureTask"); 
  Rtos::Start();
  return 0;
}
