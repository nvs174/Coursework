#include "rtos.hpp"         // for Rtos
#include "mailbox.hpp"      // for Mailbox
#include "event.hpp"        // for Event

#include "rccregisters.hpp" // for RCC

#include "gpiobregisters.hpp"  // for GPIOB

#include "spi2registers.hpp" // for SPI2
#include "spi2fieldvalues.hpp" // for SPI2


#include "ifloatdataprovider.h" // for return of measured parameters.
#include "imeasurementsupdate.h" // for updating of measured parameters.
#include "temperature.h" // for temperature BME280
#include "registerbme280.h" // for register BME280
#include "bme280.h"         // for BME280
#include "imeasurementscontroller.h" // for update register
#include "ispi.h" // for ISPI
#include "spi.h" // for SPIMode
#include "measuretask.h"

#include "idatanotifyt.h"
#include "idatanotifyp.h"
#include "idatanotifyh.h"



std::uint32_t SystemCoreClock = 16'000'000U;


extern "C" {
int __low_level_init(void)
{
  RCC::AHB1ENR::GPIOBEN::Enable::Set();
  GPIOB::MODER::MODER12::Output::Set();
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
Temperature temp;

Bme280 bme (spi,temp);

MeasureTask measureTask (bme);


int main()
{
    
  
  using namespace OsWrapper;
  Rtos::CreateThread(measureTask, "measureTask");

  Rtos::Start();

  return 0;
}
