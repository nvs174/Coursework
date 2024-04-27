#ifndef BME280
#define BME280

#include "imeasurementscontroller.h" // for Update()
#include "idatanotifyt.h" // for mdataT(dataT)
#include "idatanotifyp.h" // for mdataP(dataP)
#include "idatanotifyh.h" // for mdataH(dataH)
#include "registerbme280.h" // for BME280_REGISTER_
#include "ispi.h" // for mspi(spi)
//#include "ibme280.h"


class Bme280: public IMeasurementsController//, public IBme280
{
  
public:
  Bme280(ISpi& spi, IDataNotifyT& dataT, IDataNotifyP& dataP, IDataNotifyH& dataH) : mspi(spi), mdataT(dataT), mdataP(dataP), mdataH(dataH) {}
  
  void Update() override 
  {
    mspi.ReadWord(BME280_REGISTER_DIG_T1, &digRegT1);
    mspi.ReadWord(BME280_REGISTER_DIG_T3, &digRegT3);
    mspi.ReadWord(BME280_REGISTER_TEMPDATA, &registerCodeT);
    mspi.ReadWord(BME280_REGISTER_PRESS, &registerCodeP);
    mspi.ReadWord(BME280_REGISTER_HUMIDDATA, &registerCodeH);
    
    mdataT.OnUpdate(digRegT1,digRegT3,registerCodeT);
    mdataP.OnUpdate(registerCodeP);
    mdataH.OnUpdate(registerCodeH);
  }
  
  void InitBme280() //override 
  {
    mspi.WriteByte(BME280_REG_SOFTRESET, BME280_SOFTRESET_VALUE); /*Перезагрузим датчик*/
    while (mspi.ReadByte(BME280_REGISTER_STATUS) & 0x09 & BME280_STATUS_IM_UPDATE); /*Проверяем статус датчика, готов ли датчик к работе*/
    
    /*Зададим время ожидания датчика*/
    resalt = mspi.ReadByte(BME280_REG_CONFIG) & ~BME280_STBY_MSK; /*Считаем данные из регистра*/
    resalt |= BME280_STBY_1000 & BME280_STBY_MSK; /*Перезапишем именно те биты, которые отвечают за время ожидания*/
    mspi.WriteByte(BME280_REG_CONFIG, resalt); /*Запишем новые данные в регистр конфигурации BME280*/
    
    /*Зададим постоянную времени фильтра*/
    resalt = mspi.ReadByte(BME280_REG_CONFIG) & ~BME280_FILTER_MSK; /*Считаем данные из регистра*/
    resalt |= BME280_FILTER_4 & BME280_FILTER_MSK; /*Перезапишем биты, которые отвечают за постоянную времени фильтра*/
    mspi.WriteByte(BME280_REG_CONFIG, resalt); /*Запишем новые данные в регистр конфигурации BME280*/
    
    /*Настроим параметры сбора данных температуры*/
    resalt = mspi.ReadByte(BME280_REG_CTRL_MEAS) & ~BME280_OSRS_T_MSK; /*Считаем данные из регистра*/
    resalt |= BME280_OSRS_T_x4 & BME280_OSRS_T_MSK; /*Перезапишем биты, которые отвечают за преддискретизацию температуры*/
    mspi.WriteByte(BME280_REG_CTRL_MEAS, resalt);/*Запишем новые данные в регистр параметров сбора данных*/

    /*Настроим параметры сбора данных влажности*/
    resalt = mspi.ReadByte(BME280_REG_CTRL_HUM) & ~BME280_OSRS_H_MSK; /*Считаем данные из регистра*/
    resalt |= BME280_OSRS_H_x1 & BME280_OSRS_H_MSK; /*Перезапишем биты, которые отвечают за преддискретизацию влажности*/
    mspi.WriteByte(BME280_REG_CTRL_HUM, resalt); /*Запишем новые данные в регистр параметров сбора данных*/

    /*Настроим режим работы*/
    resalt = mspi.ReadByte(BME280_REG_CTRL_MEAS) & ~BME280_MODE_MSK; /*Считаем данные из регистра параметров сбора данных*/
    resalt |= BME280_MODE_NORMAL & BME280_MODE_MSK; /*Перезапишем биты, которые отвечают за настройку режима работы BME280*/
    mspi.WriteByte(BME280_REG_CTRL_MEAS, resalt); /*Запишем новые данные в регистр параметров сбора данных*/
  }
private:
  uint16_t digRegT1;
  int16_t digRegT3;
  int32_t registerCodeT;
  int32_t registerCodeP;
  int16_t registerCodeH;
  uint8_t resalt;
  
  ISpi& mspi;  
  IDataNotifyT& mdataT;
  IDataNotifyP& mdataP;
  IDataNotifyH& mdataH;
};
#endif