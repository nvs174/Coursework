#include "rtos.hpp"         // for Rtos
#include "rccregisters.hpp" // for RCC
#include "gpiobregisters.hpp"  // for GPIOB
#include "spi2fieldvalues.hpp" // for SPI2
#include "registerbme280.h" // for register BME280
#include "imeasurementscontroller.h" // for update register
#include "ispi.h" // for ISPI

std::uint32_t SystemCoreClock = 16'000'000U;

extern "C" {
int __low_level_init(void)
{
  RCC::AHB1ENR::GPIOBEN::Enable::Set();
  RCC::APB1ENR::SPI2EN::Enable::Set();
  GPIOB::MODER::MODER12::Output::Set(); // TODO исправлю в конце 
  GPIOB::ODR::ODR12::High::Set();
  SPI2::CR1::MSTR::Master::Set();  
  SPI2::CR1::RXONLY::FullDuplex::Set(); 
  SPI2::CR1::DFF::Data8bit::Set();
  SPI2::CR1::CPOL::High::Set();
  SPI2::CR1::CPHA::Phase2edge::Set();
  SPI2::CR1::SSM::NssSoftwareEnable::Set();
  SPI2::CR1::BR::PclockDiv2::Set();
  SPI2::CR1::LSBFIRST::MsbFisrt::Set();
  SPI2::CR2::FRF::MotorolaMode::Set();
  SPI2::CR1::CRCEN::CrcCalcDisable::Set();
  SPI2::CR1::SPE::Enable::Set();
  return 1;
}
}
Spi spi;
Bme280 bme (spi);
MeasureTask measureTask (bme);
int main()
{
  using namespace OsWrapper;
  Rtos::CreateThread(measureTask, "measureTask");

  Rtos::Start();

  return 0;
}
