/*Взял от сюда: https://github.com/KBMudrov/BME280_T*/
/*Информация о регистрах взята из "BME280 Combined humidity and pressure sensor"*/
#define BME280_ADDRESS 0x76<<1 /*I2C Адрес BME280, p.32, 6.2*/
#define BME280_REG_ID 0xD0 /*ID регистр BME280, p.26, 5.2*/
#define BME280_ID 0x60 /*Информация, читаемая от BME280 в ID регистре, 27, 5.4.1*/
#define BME280_REG_SOFTRESET 0xE0 /*Регистр для перезагрузки BME280, p.27, 5.4.2*/
#define BME280_SOFTRESET_VALUE 0xB6 /*Значение, записываемое в регистр для перезагрузки BME280, p.27, 5.4.2*/
#define BME280_REGISTER_STATUS 0XF3 /*Регистр статуса BME280, p.28, 5.4.4*/
#define BME280_STATUS_MEASURING 0X08 /*Значение из регистра статуса при запуске измерения BME280, p.28, 5.4.4*/
#define BME280_STATUS_IM_UPDATE 0X01 /*Значение из регистра статуса при окончании измерения BME280, p.28, 5.4.4*/
#define BME280_REGISTER_DIG_T1 0x88/*Регистр, откуда читаем калибровочное значение 1, p.24, 4.2.2*/
#define BME280_REGISTER_DIG_T2 0x8A/*Регистр, откуда читаем калибровочное значение 2, p.24, 4.2.2*/
#define BME280_REGISTER_DIG_T3 0x8C/*Регистр, откуда читаем калибровочное значение 3, p.24, 4.2.2*/

#define BME280_REGISTER_DIG_H1 0xA1/*Регистр, откуда читаем калибровочное значение H 1, p.24, 4.2.2*/
#define BME280_REGISTER_DIG_H2 0xE1/*Регистр, откуда читаем калибровочное значение H 2, p.24, 4.2.2*/
#define BME280_REGISTER_DIG_H3 0xE3/*Регистр, откуда читаем калибровочное значение H 3, p.24, 4.2.2*/
#define BME280_REGISTER_DIG_H4 0xE4/*Регистр, откуда читаем калибровочное значение H 4, p.24, 4.2.2*/
#define BME280_REGISTER_DIG_H5 0xE5/*Регистр, откуда читаем калибровочное значение H 5, p.24, 4.2.2*/
#define BME280_REGISTER_DIG_H6 0xE7/*Регистр, откуда читаем калибровочное значение H 6, p.24, 4.2.2*/
//------------------------------------------------//
#define BME280_REG_CONFIG 0xF5 /*Регистр конфигурации BME280, задаём время ожидания, значение постоянной времени
фильтра BME280, p.29, 5.4.6*/
#define BME280_STBY_MSK 0xE0/*Вспомогательная "маска" для параметрирования времени ожидания*/
/*Время ожидания t_standby, мс, p.30*/
#define BME280_STBY_0_5 0x00
#define BME280_STBY_62_5 0x20
#define BME280_STBY_125 0x40
#define BME280_STBY_250 0x60
#define BME280_STBY_500 0x80
#define BME280_STBY_1000 0xA0
#define BME280_STBY_10 0xC0
#define BME280_STBY_20 0xE0
//------------------------------------------------//
#define BME280_FILTER_MSK 0x1C/*Вспомогательная "маска" для параметрирования постоянной времени фильтра*/
/*Постоянная времени фильтра, p.30, 5.4.6., p.30*/
#define BME280_FILTER_OFF 0x00
#define BME280_FILTER_2 0x04
#define BME280_FILTER_4 0x08
#define BME280_FILTER_8 0x0C
#define BME280_FILTER_16 0x10
//------------------------------------------------//
#define BME280_REG_CTRL_MEAS 0xF4 /*Регистр параметров сбора данных давления и температуры, p.28, 5.4.5*/
/*p.29, 5.4.5*/

#define BME280_REG_CTRL_HUM 0xF2 // /*Регистр параметров сбора данных влажности, p.27, 5.4.3*/

#define BME280_OSRS_T_MSK 0xE0/*Вспомогательная "маска" для параметрирования преддискретизации*/
/*Параметр преддискретизации температуры, p.29*/
#define BME280_OSRS_T_SKIP 0x00
#define BME280_OSRS_T_x1 0x20
#define BME280_OSRS_T_x2 0x40
#define BME280_OSRS_T_x4 0x60
#define BME280_OSRS_T_x8 0x80
#define BME280_OSRS_T_x16 0xA0


#define BME280_OSRS_H_MSK 0x07/*Вспомогательная "маска" для параметрирования преддискретизации (Table 19)*/
/*Параметр преддискретизации влажности, p.28*/
#define BME280_OSRS_H_SKIP 0x00
#define BME280_OSRS_H_x1 0x01
#define BME280_OSRS_H_x2 0x02
#define BME280_OSRS_H_x4 0x03
#define BME280_OSRS_H_x8 0x04
#define BME280_OSRS_H_x16 0x05
//------------------------------------------------//
#define BME280_MODE_MSK 0x03/*Вспомогательная "маска" для параметрирования режима работы BME280*/
/*Режим работы датчика, p.29*/
#define BME280_MODE_SLEEP 0x00
#define BME280_MODE_FORCED 0x01
#define BME280_MODE_NORMAL 0x03
//------------------------------------------------//
#define BME280_REGISTER_TEMPDATA 0xFA/*Регистр, откуда читаются данные температуры BME280, p.31, 5.4.8*/

#define BME280_REGISTER_HUMIDDATA 0xFD/*Регистр, откуда читаются данные влажности BME280, p.31, 5.4.9*/

#define BME280_REGISTER_PRESS 0xF7 
//------------------------------------------------
#define be24toword(a) ((((a)>>16)&0x000000ff)|((a)&0x0000ff00)|(((a)<<16)&0x00ff0000))/*Функция перестановки байтов*/

#define be16toword(a) ((((a)>>8)&0xff)|(((a)<<8)&0xff00))/*Функция перестановки байтов*/


#define SPI_WRITE 0x7F
#define SPI_READ 0x80