#include "STC12X.h"

#define uchar unsigned char

//**********************************************
//�\��GUART�]�m
//�ǤJ�ѼơGbps
//�^�ǰѼơGvoid
//�����G�]�m�j�v
//**********************************************
void UART_init (unsigned int bps) 
{
	SCON  = 0x50;
	TMOD |= 0x20;
	TH1   = TL1 = 256 - (28800 / bps);	   // Fosc = 11.0592MHz
	IE   |= 0x90;			               //EA = 1
	TR1   = 1;
}
//**********************************************
//�\��GUART�r���ǿ�
//�ǤJ�ѼơGvoid
//�^�ǰѼơGvoid
//�����G�L
//**********************************************
void UART_sendchar(uchar ch)
{
	SBUF=ch;
	while(TI==0);
	TI=0;
}
//**********************************************
//�\��GUART�r��ǿ�
//�ǤJ�ѼơGvoid
//�^�ǰѼơGvoid
//�����G�L
//**********************************************
void UART_sendstring(uchar *p)
{
	while(*p)
	{
		UART_sendchar(*p);
		p++;
	}
	UART_sendchar(0x0D);
	UART_sendchar(0x0A);
}
//**********************************************
//�\��GUART_SBUF����
//�ǤJ�ѼơGvoid
//�^�ǰѼơGvoid
//�����G�L
//**********************************************
uchar UART_receive(void) 
{  	
	uchar RxBuf;
	if(RI)
	{
		RxBuf = SBUF;
		RI=0;
	}
	return RxBuf;
}