#include "bme280.h"

void Bme280::Update() 
{
  //TODO получить данные по SPI;
  
  
  mdataT.OnUpdate(digRegT1,digRegT3,registerCodeT);
  mdataP.OnUpdate(registerCodeP);
  mdataH.OnUpdate(registerCodeH); 
};
