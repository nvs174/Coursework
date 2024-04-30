#include "rtos.hpp"         // for Rtos

#include "rccregisters.hpp" // for RCC

#include "gpiobregisters.hpp"  // for GPIOB

#include "gpioaregisters.hpp" // for GPIOA

#include "usart2registers.hpp" // for USART2

#include "spi2fieldvalues.hpp" // for SPI2
#include "spi2registers.hpp"

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
  //_______________________Usart___________________________________________
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
  
  //_______________________SPI___________________________________________
  RCC::AHB1ENR::GPIOBEN::Enable::Set();
  RCC::APB1ENR::SPI2EN::Enable::Set();
  GPIOB::MODER::MODER12::Output::Set();
  GPIOB::ODR::ODR12::High::Set(); // логическая 1 на линии NSS
  
  //SPI2::CR1::SSI::Value1::Set();
  SPI2::CR1::MSTR::Master::Set();
  SPI2::CR1::RXONLY::FullDuplex::Set(); 
  SPI2::CR1::DFF::Data8bit::Set();
  SPI2::CR1::CPOL::High::Set(); // 1
  SPI2::CR1::CPHA::Phase2edge::Set(); // 1
  //SPI2::CR1::SSM::NssSoftwareEnable::Set(); // раз NssSoftwareEnable, то требуется самостоятельно дергать линию NSS
  SPI2::CR1::SSM::NssSoftwareDisable::Set();
  SPI2::CR2::SSOE::SsOutputEnable::Set();
  SPI2::CR1::BR::PclockDiv2::Set(); // делитель
  SPI2::CR1::LSBFIRST::MsbFisrt::Set(); // формат кадра
  SPI2::CR2::FRF::MotorolaMode::Set(); // 0
  SPI2::CR1::CRCEN::CrcCalcDisable::Set(); // 0
  SPI2::CR1::SPE::Enable::Set();
  
  
  
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
