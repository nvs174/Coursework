#include "spi.h"

uint8_t Spi::ReadByte(uint8_t byte, uint8_t bytcount) 
{  
  uint8_t rx[2] = {0};
  uint8_t resalt;
  while(!SPI2::SR::BSY::NotBusy::IsSet()) {}
  GPIOB::ODR::ODR12::High::Set();
  GPIOB::ODR::ODR12::Low::Set();

  for(uint8_t i = 0; i < bytcount + 1; i++) 
  {
    SPI2::DR::Write(byte | SPI_READ);
    while(!SPI2::SR::BSY::NotBusy::IsSet()) {}
    rx[i] = SPI2::DR::Get();
  }
  GPIOB::ODR::ODR12::High::Set();
  resalt = rx[1];
  return resalt;
}

void Spi::WriteByte(uint8_t byte, uint8_t value) 
{
  while(!SPI2::SR::BSY::NotBusy::IsSet()) {}
  GPIOB::ODR::ODR12::High::Set();
  GPIOB::ODR::ODR12::Low::Set();
  SPI2::DR::Write(byte & SPI_WRITE);
  while(!SPI2::SR::TXE::TxBufferEmpty::IsSet()) {}
  SPI2::DR::Write(value);
  while(!SPI2::SR::BSY::NotBusy::IsSet()) {}
  GPIOB::ODR::ODR12::High::Set();
};

