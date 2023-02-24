/*
 * USART_REGS.h

 *
 */

#ifndef USART_REGS_H
#define USART_REGS_H
/*******************************************#DEFINE***********************************************/
#include "COMPILER.h"
#include "PLATFORM_TYPES.h"

/***********************************DEFINITION_OF_USART_REGS**************************************/

#define UDR_REG   (*(volatile uint8 * const)0x002C)
#define UCSRA_REG (*(volatile uint8 * const)0x002B)
#define UCSRB_REG (*(volatile uint8 * const)0x002A)
#define UCSRC_REG (*(volatile uint8 * const)0x0040)
#define UBRRH_REG (*(volatile uint8 * const)0x0040)
#define UBRRL_REG (*(volatile uint8 * const)0x0029)
#define RxEN  4 
#define TxEN  3
#define U2X   1
#define UMSEL 6
#define MPCM  0
#define TxCIN 6
#define RxCIN 7

#define UDRIE 5
#define UCSZ2 2
#define UCSZ1 2
#define UCSZ0 1

#define USBS  3
#define UPM0  4
#define UPM1  5
#define UCPOL 0
#define RxC   7
#define TxC   6
#define FE    4
#define DOR	  3
#define PE    2 
#define RxB8  1
#define TxB8  0

/* USART, RX Complete */
#define USART_RxC_vect            _VECTOR(13)
#define USART_RxC_vect_num        13

/* USART Data Register Empty */
#define USART_UDRE_vect            _VECTOR(14)
#define USART_UDRE_vect_num        14

/* USART, TX Complete */
#define USART_TxC_vect            _VECTOR(15)
#define USART_TxC_vect_num        15

#endif /* USART_REGS_H */
