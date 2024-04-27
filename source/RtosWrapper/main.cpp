#include "rtos.hpp"         // for Rtos

#include "rccregisters.hpp" // for RCC

#include "gpiobregisters.hpp"  // for GPIOB

#include "gpioaregisters.hpp" // for GPIOA

#include "usart2registers.hpp" // for USART2

#include "spi2fieldvalues.hpp" // for SPI2
#include "spi2registers.hpp"


//#include "imeasurementscontroller.h"
//#include "ifloatdataprovider.h"
//#include "imeasurementsupdate.h"
//#include "idatanotifyt.h"
//#include "idatanotifyp.h"
//#include "idatanotifyh.h"
//#include "ispi.h"
//#include "idatanotifyt.h"
//#include "ibme280.h"
//#include "registerbme280.h"

#include "bme280.cpp"
#include "sendtask.cpp"
#include "measuretask.cpp"
#include "humidity.cpp"
#include "press.cpp"
#include "temperature.cpp"
#include "spi.cpp"
#include "calculationdewpoint.cpp"
#include "usart.cpp"
std::uint32_t SystemCoreClock = 16'000'000U;


extern "C" {
int __low_level_init(void)
{
  RCC::APB1ENR::USART2EN::Enable::Set(); // подключение к тактированию
  GPIOA::MODER::MODER2::Alternate::Set(); // конфигурация портов, альтернативная функция
  GPIOA::MODER::MODER3::Alternate::Set(); // конфигурация портов, альтернативная функция
  GPIOA::OTYPER::OT2::OutputPushPull::Set();
  GPIOA::OTYPER::OT3::OutputPushPull::Set();
  GPIOA::PUPDR::PUPDR2::PullUp::Set(); // подтяжка к 1  
  GPIOA::PUPDR::PUPDR3::PullUp::Set(); // подтжка к 1 
  
  GPIOA::AFRL::AFRL2::Af7::Set();
  GPIOA::AFRL::AFRL3::Af7::Set();
  
  USART2::BRR::DIV_Mantissa::Set(104);
  USART2::BRR::DIV_Fraction::Value2::Set();
  USART2::CR2::STOP::Value0::Set();
    
  USART2::CR1::OVER8::OversamplingBy16::Set(); // Режим дискретизации? 1/16
  USART2::CR1::M::Data8bits::Set();
  
  USART2::CR1::TE::Enable::Set();
  USART2::CR1::UE::Enable::Set();
  
  SPI2::CR1::BR::PclockDiv2::Set();
  
  
  return 1;
}
}

Temperature temp;
Press press;
Humidity hum;
DewPoint point(temp,hum);
Spi spi;

Bme280 bme(spi, temp, press, hum);
Usart usart(temp, press, hum, point);

MeasureTask measureTask (bme, temp, press, hum, point);
SendTask sendtask(usart);

int main()
{
  bme.InitBme280();
  using namespace OsWrapper;
  Rtos::CreateThread(measureTask, "measureTask");
  Rtos::CreateThread(sendtask, "sendTask");
  
  Rtos::Start();

  return 0;
}
