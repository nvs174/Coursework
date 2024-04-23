#ifndef BME280
#define BME280

#include "imeasurementscontroller.h" // for Update()
#include "idatanotifyt.h" // for mdataT(dataT)
#include "idatanotifyp.h" // for mdataP(dataP)
#include "idatanotifyh.h" // for mdataH(dataH)
#include "registerbme280.h" // for BME280_REGISTER_
#include "ispi.h" // for mspi(spi)
#include "ibme280.h"


class Bme280: public IMeasurementsController, public IBme280
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
  
  void InitBme280() override 
  {
    mspi.WriteByte(BME280_REG_SOFTRESET, BME280_SOFTRESET_VALUE); /*������������ ������*/
    while (mspi.ReadByte(BME280_REGISTER_STATUS) & 0x09 & BME280_STATUS_IM_UPDATE); /*��������� ������ �������, ����� �� ������ � ������*/
    
    /*������� ����� �������� �������*/
    resalt = mspi.ReadByte(BME280_REG_CONFIG) & ~BME280_STBY_MSK; /*������� ������ �� ��������*/
    resalt |= BME280_STBY_1000 & BME280_STBY_MSK; /*����������� ������ �� ����, ������� �������� �� ����� ��������*/
    mspi.WriteByte(BME280_REG_CONFIG, resalt); /*������� ����� ������ � ������� ������������ BME280*/
    
    /*������� ���������� ������� �������*/
    resalt = mspi.ReadByte(BME280_REG_CONFIG) & ~BME280_FILTER_MSK; /*������� ������ �� ��������*/
    resalt |= BME280_FILTER_4 & BME280_FILTER_MSK; /*����������� ����, ������� �������� �� ���������� ������� �������*/
    mspi.WriteByte(BME280_REG_CONFIG, resalt); /*������� ����� ������ � ������� ������������ BME280*/
    
    /*�������� ��������� ����� ������ �����������*/
    resalt = mspi.ReadByte(BME280_REG_CTRL_MEAS) & ~BME280_OSRS_T_MSK; /*������� ������ �� ��������*/
    resalt |= BME280_OSRS_T_x4 & BME280_OSRS_T_MSK; /*����������� ����, ������� �������� �� ����������������� �����������*/
    mspi.WriteByte(BME280_REG_CTRL_MEAS, resalt);/*������� ����� ������ � ������� ���������� ����� ������*/

    /*�������� ��������� ����� ������ ���������*/
    resalt = mspi.ReadByte(BME280_REG_CTRL_HUM) & ~BME280_OSRS_H_MSK; /*������� ������ �� ��������*/
    resalt |= BME280_OSRS_H_x1 & BME280_OSRS_H_MSK; /*����������� ����, ������� �������� �� ����������������� ���������*/
    mspi.WriteByte(BME280_REG_CTRL_HUM, resalt); /*������� ����� ������ � ������� ���������� ����� ������*/

    /*�������� ����� ������*/
    resalt = mspi.ReadByte(BME280_REG_CTRL_MEAS) & ~BME280_MODE_MSK; /*������� ������ �� �������� ���������� ����� ������*/
    resalt |= BME280_MODE_NORMAL & BME280_MODE_MSK; /*����������� ����, ������� �������� �� ��������� ������ ������ BME280*/
    mspi.WriteByte(BME280_REG_CTRL_MEAS, resalt); /*������� ����� ������ � ������� ���������� ����� ������*/
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