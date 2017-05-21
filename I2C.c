/*
 * I2C.c
 *
 * Created: 2016/9/22 12:32:55
 *  Author: dusch
 */ 

#include "I2C.h"

 /******** TWI�ӿڵĳ�ʼ������********/
void I2C_Init(void)
{
	TWAR = 0x00;         	//����ģʽ���õ�ַ��Ч
	TWCR = 0x00;         	//�ر�TWIģ��
	TWBR = 100;        //100
	TWSR = 0x03;         //64��Ƶ
 }
 /********��Write_dataд��AT24C04�ڲ�����EE_addressΪ��ַ�Ĵ洢��********/
void I2C_Write(unsigned char Write_data, unsigned char EE_address)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);
	while(!(TWCR & (1<<TWINT)));  //0x08
	TWDR = SLA_W;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));  //0x18
	TWDR = EE_address;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));  //0x28
	TWDR = Write_data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));  //0x28
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}
/********��AT24C04�ڲ�����EE_addressΪ��ַ�Ĵ洢����������********/
unsigned char I2C_Read(unsigned char EE_address)
{
	unsigned char temp;
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);
	while(!(TWCR & (1<<TWINT)));
	TWDR = SLA_W;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	TWDR = EE_address;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);
	while(!(TWCR & (1<<TWINT)));
	TWDR = SLA_R;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	temp = TWDR;
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	return temp;
}