#ifndef _UART_h
#define _UART_h
#include "STC12X.h"

#define uchar unsigned char

void UART_init (unsigned int bps);
void UART_sendchar(uchar ch);
void UART_sendstring(uchar *p);
uchar UART_receive(void);

#endif