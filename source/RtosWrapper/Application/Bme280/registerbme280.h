/*Взял от сюда: https://github.com/KBMudrov/BME280_T*/
#define BME280_ADDRESS 0x76<<1 /*����� BME280, p.32, 6.2*/

#define BME280_REG_ID 0xD0 /*ID ������� BME280, p.26, 5.2*/

#define BME280_ID 0x60 /*����������, �������� �� BME280 � ID ��������, 27, 5.4.1*/

#define BME280_REG_SOFTRESET 0xE0 /*������� ��� ������������ BME280, p.27, 5.4.2*/

#define BME280_SOFTRESET_VALUE 0xB6 /*��������, ������������ � ������� ��� ������������ BME280, p.27, 5.4.2*/

#define BME280_REGISTER_STATUS 0XF3 /*������� ������� BME280, p.28, 5.4.4*/

#define BME280_STATUS_MEASURING 0X08 /*�������� �� �������� ������� ��� ������� ��������� BME280, p.28, 5.4.4*/

#define BME280_STATUS_IM_UPDATE 0X01 /*�������� �� �������� ������� ��� ��������� ��������� BME280, p.28, 5.4.4*/

#define BME280_REGISTER_DIG_T1 0x88/*�������, ������ ������ ������������� �������� 1, p.24, 4.2.2*/

#define BME280_REGISTER_DIG_T2 0x8A/*�������, ������ ������ ������������� �������� 2, p.24, 4.2.2*/

#define BME280_REGISTER_DIG_T3 0x8C/*�������, ������ ������ ������������� �������� 3, p.24, 4.2.2*/


#define BME280_REG_CONFIG 0xF5 /*������� ������������ BME280, ����� ����� ��������, �������� ���������� ������� ������� BME280, p.29, 5.4.6*/

#define BME280_STBY_MSK 0xE0/*��������������� "�����" ��� ���������������� ������� ��������*/

/*����� �������� t_standby, ��, p.30*/
#define BME280_STBY_0_5 0x00
#define BME280_STBY_62_5 0x20
#define BME280_STBY_125 0x40
#define BME280_STBY_250 0x60
#define BME280_STBY_500 0x80
#define BME280_STBY_1000 0xA0
#define BME280_STBY_10 0xC0
#define BME280_STBY_20 0xE0

#define BME280_FILTER_MSK 0x1C/*��������������� "�����" ��� ���������������� ���������� ������� �������*/
/*���������� ������� �������, p.30, 5.4.6., p.30*/
#define BME280_FILTER_OFF 0x00
#define BME280_FILTER_2 0x04
#define BME280_FILTER_4 0x08
#define BME280_FILTER_8 0x0C
#define BME280_FILTER_16 0x10
//------------------------------------------------//
#define BME280_REG_CTRL_MEAS  0xF4 /*������� ���������� ����� ������ �������� � �����������, p.28, 5.4.5*/
/*p.29, 5.4.5*/

#define BME280_REG_CTRL_HUM 0xF2 // /*������� ���������� ����� ������ ���������, p.27, 5.4.3*/

#define BME280_OSRS_T_MSK 0xE0/*��������������� "�����" ��� ���������������� �����������������*/
/*�������� ����������������� �����������, p.29*/
#define BME280_OSRS_T_SKIP 0x00
#define BME280_OSRS_T_x1 0x20
#define BME280_OSRS_T_x2 0x40
#define BME280_OSRS_T_x4 0x60
#define BME280_OSRS_T_x8 0x80
#define BME280_OSRS_T_x16 0xA0


#define BME280_OSRS_H_MSK 0x07/*��������������� "�����" ��� ���������������� ����������������� (Table 19)*/

//------------------------------------------------//
#define BME280_MODE_MSK 0x03/*��������������� "�����" ��� ���������������� ������ ������ BME280*/
/*����� ������ �������, p.29*/
#define BME280_MODE_SLEEP 0x00
#define BME280_MODE_FORCED 0x01
#define BME280_MODE_NORMAL 0x03
//------------------------------------------------//
#define BME280_REGISTER_TEMPDATA 0xFA/*�������, ������ �������� ������ ����������� BME280, p.31, 5.4.8*/

#define BME280_REGISTER_HUMIDDATA 0xFD/*�������, ������ �������� ������ ��������� BME280, p.31, 5.4.9*/

#define BME280_REGISTER_PRESS 0xF7 /*�������, ������ �������� ������ ��������� BME280, p.31, 5.4.9*/
//------------------------------------------------
#define be24toword(a) ((((a)>>16)&0x000000ff)|((a)&0x0000ff00)|(((a)<<16)&0x00ff0000)) /*������� ������������ ������*/

#define be16toword(a) ((((a)>>8)&0xff)|(((a)<<8)&0xff00)) /*������� ������������ ������*/