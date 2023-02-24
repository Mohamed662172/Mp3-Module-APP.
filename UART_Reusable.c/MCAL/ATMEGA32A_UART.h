/*
 * ATMEGA32A_UART.h
 *
 */ 

/************************************************************************/
/*                   USART_PostBuildConfiguration                       */
/************************************************************************/


#ifndef ATMEGA32A_UART_H_
#define ATMEGA32A_UART_H_
#include "um_Configuration.h"
#include  "PLATFORM_TYPES.h"
/************************************************************************/
/*                   TYPE DEF ENUM for Option USART                     */
/************************************************************************/


typedef enum
{  
    USART_Disable,
	USART_TxEnable,
	USART_RxEnable,
	USART_TxRxEnable,
	
}USART_EnableMode;

typedef enum
{  
    USART_Async_NormalSpeedMode,
	USART_Async_DoubleSpeedMode,
	USART_sync_Mode,
	
}USART_CommuincationMode;

typedef enum
{  
   USART_SingleProcessor,
   USART_MultiProcessor,
   
}USART_CommunicationTerminal;

typedef enum
{	
	USART_DisableInterrupt,
	USART_TxInterruptEnable,
	USART_RxInterruptEnable,
	USART_UDREmpetyInterruptEnable,
	USART_TxRxInterruptEnable,
	USART_TxUDREmpetyInterruptEnable,
	USART_RxUDREmpetyInterruptEnable,
	USART_TxRxUDREmpetyInterruptEnable,
	
}USART_InterrupetSource;

typedef enum 
{  
   USART_5BitDataFrame,
   USART_6BitDataFrame,
   USART_7BitDataFrame,
   USART_8BitDataFrame,
   USART_9BitDataFrame,
   
}USART_DataFrameFormat;

typedef enum 
{
	USART_ParityDisable_1StopBit,
	USART_ParityDisable_2StopBit,
	USART_ParityEven_1StopBit,
	USART_ParityEven_2StopBit,
	USART_ParityOdd_1StopBit,
	USART_ParityOdd_2StopBit,
	
}USART_ControlFrameFormat;

typedef enum 
{ 
	USART_SampleRisingEdge,
	USART_SampleFallingEdge,
	
}USART_CLKPolarity;

typedef enum 
{
	USART_NoError,
	USART_ParityError,
	USART_OverRunError,
	USART_FrameError,
}USART_ErrorType;



/************************************************************************/
/*                     USART_ConfigurationStruct                        */
/************************************************************************/

typedef struct  
{
	USART_EnableMode					EnableMode;

	USART_CommuincationMode             CommunicationMode;  

	USART_CommunicationTerminal         CommunicationTerminal;

	USART_InterrupetSource              InterrupetSource;

	USART_DataFrameFormat				DataFrameFormat;

	USART_ControlFrameFormat            ControlFrameFormat;

		/*Assign this when  working in Sync Mode */

	USART_CLKPolarity                   CLKPolarity;

	uint32 								BaudRate;	

	    /* Read this flag before using returned data  by Rx function, clear flag your self*/   	

	USART_ErrorType                     ReadMsg_Error;	

    /*call back function member */
	/* Make  The Pointer Points  To The Function You Wish Called By  RxC Interrupt*/
 	void(*RxCInterrupt_CallBack)(void);

	/* Make  The Pointer Points  To The Function You Wish Called By  TxC Interrupt*/
	
	void(*TxCInterrupt_CallBack)(void);
	/* Make  The Pointer Points  To The Function You Wish Called By  UDRE Interrupt*/

	void(*UDREInterrupt_CallBack)(void);
	
}USART_ConfigurationStruct;

/************************************************************************/
/*                ProtoType of USART Function                           */
/************************************************************************/



extern USART_ConfigurationStruct      USART0;

void USART_init(void);

void USART_TxByteBlockingMode(uint8 Data);

void USART_TxByteNonBlockingMode(uint8 Data);

uint8 USART_RxByteBlockingMode(void);

uint8 USART_RxByteNonBlockingMode(void);







#endif /* ATMEGA32A_UART_H_ */