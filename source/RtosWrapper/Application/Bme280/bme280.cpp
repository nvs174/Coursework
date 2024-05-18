#include "bme280.h"
void Bme280::InittBme280() 
{
  mspi.WriteByte(BME280_REG_SOFTRESET, BME280_SOFTRESET_VALUE); //Перезагрузим датчик
  while (mspi.ReadByte(BME280_REGISTER_STATUS, 2) & 0x09 & BME280_STATUS_IM_UPDATE); //Проверяем статус датчика, готов ли датчик к работе
 
  digRegT1 = mspi.ReadByte(BME280_REGISTER_DIG_T1, 2) << 8;
  digRegT1 |= mspi.ReadByte(BME280_REGISTER_DIG_T1 + 1, 2);
  
  digRegT3 = mspi.ReadByte(BME280_REGISTER_DIG_T3, 2) << 8;
  digRegT3 |= mspi.ReadByte(BME280_REGISTER_DIG_T3 + 1, 2);
  
  //Зададим время ожидания датчика
  resalt = mspi.ReadByte(BME280_REG_CONFIG, 2) & ~BME280_STBY_MSK; //Считаем данные из регистра
  resalt |= BME280_STBY_1000 & BME280_STBY_MSK; //Перезапишем именно те биты, которые отвечают за время ожидания
  mspi.WriteByte(BME280_REG_CONFIG, resalt); //Запишем новые данные в регистр конфигурации BME280

  //Зададим постоянную времени фильтра
  resalt = mspi.ReadByte(BME280_REG_CONFIG, 2) & ~BME280_FILTER_MSK; //Считаем данные из регистра
  resalt |= BME280_FILTER_4 & BME280_FILTER_MSK; //Перезапишем биты, которые отвечают за постоянную времени фильтра
  mspi.WriteByte(BME280_REG_CONFIG, resalt); //Запишем новые данные в регистр конфигурации BME280

  //Настроим параметры сбора данных температуры и давления 
  resalt = mspi.ReadByte(BME280_REG_CTRL_MEAS, 2) & ~BME280_OSRS_T_MSK; //Считаем данные из регистра
  resalt |= BME280_OSRS_T_x4 & BME280_OSRS_T_MSK; //Перезапишем биты, которые отвечают за преддискретизацию температуры
  resalt |= 0x6C; //Перезапишем биты, которые отвечают за преддискретизацию давления
  mspi.WriteByte(BME280_REG_CTRL_MEAS, resalt); //Запишем новые данные в регистр параметров сбора данных

  //Настроим параметры сбора данных влажности
  resalt = mspi.ReadByte(BME280_REG_CTRL_HUM, 2) & ~BME280_OSRS_H_MSK; //Считаем данные из регистра
  resalt |= BME280_OSRS_H_x1 & BME280_OSRS_H_MSK; //Перезапишем биты, которые отвечают за преддискретизацию влажности
  mspi.WriteByte(BME280_REG_CTRL_HUM, resalt); //Запишем новые данные в регистр параметров сбора данных

  //Настроим режим работы
  resalt = mspi.ReadByte(BME280_REG_CTRL_MEAS, 2) & ~BME280_MODE_MSK; //Считаем данные из регистра параметров сбора данных
  resalt |= BME280_MODE_NORMAL & BME280_MODE_MSK; //Перезапишем биты, которые отвечают за настройку режима работы BME280
  mspi.WriteByte(BME280_REG_CTRL_MEAS, resalt); //Запишем новые данные в регистр параметров сбора данных 
}


void Bme280::Update() 
{
  registerCodeT = mspi.ReadByte(BME280_REGISTER_TEMPDATA, 2) << 8;
  registerCodeT = registerCodeT << 4;
  registerCodeT |= mspi.ReadByte(BME280_REGISTER_TEMPDATA + 1, 2) << 4;
  registerCodeT |= mspi.ReadByte(BME280_REGISTER_TEMPDATA + 2, 2) >> 4;
 
  registerCodeP = mspi.ReadByte(BME280_REGISTER_PRESS, 2) << 8;
  registerCodeP = registerCodeT << 4;
  registerCodeP |= mspi.ReadByte(BME280_REGISTER_PRESS + 1, 2) << 4;
  registerCodeP |= mspi.ReadByte(BME280_REGISTER_PRESS + 2, 2) >> 4;
 
  registerCodeH = mspi.ReadByte(BME280_REGISTER_HUMIDDATA, 2) << 8;
  registerCodeH |= mspi.ReadByte(BME280_REGISTER_HUMIDDATA + 1, 2);
  
  mdataT.OnUpdate(digRegT1,digRegT3,registerCodeT);
  mdataP.OnUpdate(registerCodeP);
  mdataH.OnUpdate(registerCodeH);
};
