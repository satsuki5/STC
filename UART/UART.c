#include "STC12X.h"

#define uchar unsigned char

//**********************************************
//UART砞竚
//肚把计bps
//肚把计void
//弧砞竚纉瞯
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
//UARTじ肚块
//肚把计void
//肚把计void
//弧礚
//**********************************************
void UART_sendchar(uchar ch)
{
	SBUF=ch;
	while(TI==0);
	TI=0;
}
//**********************************************
//UART﹃肚块
//肚把计void
//肚把计void
//弧礚
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
//UART_SBUF钡Μ
//肚把计void
//肚把计void
//弧礚
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