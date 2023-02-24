/*
 * ATMEGA32_UART.c
 */ 


/************************************************************************/
/*                     Include Header File                              */
/************************************************************************/
#include "ATMEGA32A_UART.h"
#include "USART_REGS.h"
#include "DIO.h"
#include <avr/interrupt.h>

USART_ConfigurationStruct      USART0={0,   
	                                   .RxCInterrupt_CallBack=NULL_PTR,
	                                   .TxCInterrupt_CallBack=NULL_PTR,
	                                   .UDREInterrupt_CallBack=NULL_PTR,
									    };
ISR(USART_RxC_vect)
{ 
	if (USART0.RxCInterrupt_CallBack != NULL_PTR)
	{
		USART0.RxCInterrupt_CallBack();
	}
	else 
	{
		//Report an error using Error Handel
    }
}

ISR(USART_TxC_vect)
{
	if (USART0.TxCInterrupt_CallBack != NULL_PTR)
	{
		USART0.TxCInterrupt_CallBack();
	}
	else
	{
		//Report an error using Error Handel
	}
}

ISR(USART_UDRE_vect)
{
	if (USART0.UDREInterrupt_CallBack != NULL_PTR)
	{
		USART0.UDREInterrupt_CallBack();
	}
	else
	{
		//Report an error using Error Handel
	}
}


void USART_init (void) {
	
	uint8	UCSRA_Temp=0;
	uint8	UCSRB_Temp=0;
	uint8	UCSRC_Temp=0;
	float32 UBRR_Temp =0;
 
 
switch (USART0.EnableMode)
{
	case USART_Disable:
 		break;
	case USART_TxEnable:
            SET_BIT(UCSRB_Temp,TxEN);
		break;
	case USART_RxEnable:
			SET_BIT(UCSRB_Temp,RxEN);
		break;
	case USART_TxRxEnable:
			SET_BIT(UCSRB_Temp,TxEN);
			SET_BIT(UCSRB_Temp,RXEN);
		break;
 default:
		break;	
}
 
switch(USART0.CommunicationMode) 
{
   case USART_Async_NormalSpeedMode:
			UBRR_Temp=((float32)F_CPU)/((16.0)*USART0.BaudRate)-.5;// we add .5 to approximate the float number to avoid fixed point 
		break;
   case USART_Async_DoubleSpeedMode:
			SET_BIT(UCSRA_Temp,U2X);
			UBRR_Temp=((float32)F_CPU)/((8.0)*USART0.BaudRate)-.5;// we add .5 to approximate the float number to avoid fixed point
		break;
   case USART_sync_Mode:
			SET_BIT(UCSRC_Temp,UMSEL);
			UBRR_Temp=((float32)F_CPU)/((2.0)*USART0.BaudRate)-.5;// we add .5 to approximate the float number to avoid fixed point
					switch(USART0.CLKPolarity)
					{  
						case USART_SampleFallingEdge:
						break;
						case USART_SampleRisingEdge:
								SET_BIT(UCSRC_Temp,UCPOL);  
						break;
					}			
		break;
   default:
		break;
}

switch(USART0.CommunicationTerminal)
{
   case USART_SingleProcessor:
		break;
   case USART_MultiProcessor:
			SET_BIT(UCSRA_Temp,MPCM);
		break;
   default:
		break;

} 
switch(USART0.InterrupetSource)
{
	case USART_DisableInterrupt:
		break;
	case USART_TxInterruptEnable:
			SET_BIT(UCSRB_Temp,TxCIN);
		break;
	case USART_RxInterruptEnable:
			SET_BIT(UCSRB_Temp,RxCIN);	
		break;
	case USART_UDREmpetyInterruptEnable:
			SET_BIT(UCSRB_Temp,UDRIE);			
		break;
	case USART_TxRxInterruptEnable:
			SET_BIT(UCSRB_Temp,TxCIN);
			SET_BIT(UCSRB_Temp,RxCIN);
		break;
	case USART_TxUDREmpetyInterruptEnable:
			SET_BIT(UCSRB_Temp,TxCIN);
			SET_BIT(UCSRB_Temp,UDRIE);
		break;
	case USART_RxUDREmpetyInterruptEnable:
			SET_BIT(UCSRB_Temp,RxCIN);
			SET_BIT(UCSRB_Temp,UDRIE);
		break;
	case USART_TxRxUDREmpetyInterruptEnable:
			SET_BIT(UCSRB_Temp,TxCIN);
			SET_BIT(UCSRB_Temp,RxCIN);
			SET_BIT(UCSRB_Temp,UDRIE);
		break; 
	default:
		break;
}

switch(USART0.DataFrameFormat)
{
	case USART_5BitDataFrame:
			break;
	case USART_6BitDataFrame:
			SET_BIT(UCSRC_Temp,UCSZ0);
			break;
	case USART_7BitDataFrame:
			SET_BIT(UCSRC_Temp,UCSZ1);
			break;
	case USART_8BitDataFrame:
			SET_BIT(UCSRC_Temp,UCSZ0);
			SET_BIT(UCSRC_Temp,UCSZ1);
			break;
	case USART_9BitDataFrame:
			SET_BIT(UCSRC_Temp,UCSZ0);
			SET_BIT(UCSRC_Temp,UCSZ1);
			SET_BIT(UCSRB_Temp,UCSZ2);
	break;	
	default:
	break;
}	

switch(USART0.ControlFrameFormat)
{   
	case USART_ParityDisable_1StopBit:
				break;
	case USART_ParityDisable_2StopBit:
					SET_BIT(UCSRC_Temp,USBS);
				break;
	case USART_ParityEven_1StopBit:
					SET_BIT(UCSRC_Temp,UPM1);
				break;
	case USART_ParityEven_2StopBit:
					SET_BIT(UCSRC_Temp,USBS);
					SET_BIT(UCSRC_Temp,UPM1);
				break;
	case USART_ParityOdd_1StopBit:
					SET_BIT(UCSRC_Temp,UPM0);
				break;
	case USART_ParityOdd_2StopBit:
					SET_BIT(UCSRC_Temp,USBS);
					SET_BIT(UCSRC_Temp,UPM1);
			   break;
	default:
			 break;	
}

	
	UCSRB_REG = UCSRB_Temp;
	
	UBRRL_REG =((uint8)UBRR_Temp) ;
	
	UBRRH_REG =((uint8)UBRR_Temp)>>8 ;
	
	
	UCSRA_REG = UCSRA_Temp;
	
	UCSRC_REG = UCSRC_Temp;
	
}

void USART_TxByteBlockingMode(uint8 Data)
{
	while ((UCSRA_REG & (0x01<<UDRE))==0)
	{ 
		/* Do  Nothing */
	}  
	if (USART0.DataFrameFormat == USART_9BitDataFrame )
	{
		UCSRB_REG = (UCSRB_REG & 0xFE ) | (Data  & (1<<8))>>8;
	}
	UDR_REG = (uint8)Data;
	
}	

void USART_TxByteNonBlockingMode(uint8 Data)
{
	if ((UCSRA_REG & (0x01<<UDRE)) != 0)
	{	
			if (USART0.DataFrameFormat == USART_9BitDataFrame )
			{
				UCSRB_REG = (UCSRB_REG & 0xFE ) | (Data  & (1<<8))>>8;
			}
			UDR_REG = (uint8)Data;
	}
}	

uint8 USART_RxByteBlockingMode(void)
{   
	uint8 Rx_Data = 0;
	
	while ((UCSRA_REG & (0x01<<RxC)) == 0)
 	{  
		 /* Do Nothing */   
 	}
	if (UCSRA_REG & ((0x01<<FE) | (0x01<<PE) | (0x01<<DOR)))
	{ 
		  //ERROR :You should handle it as i wish 
		  if (UCSRA_REG & (0x01<<FE))
		  {
			  USART0.ReadMsg_Error = USART_FrameError;
		  }
		  else if(UCSRA_REG & (0x01<<PE))
		  {
			  USART0.ReadMsg_Error = USART_ParityError;
		  }
		  else if (UCSRA_REG &(0x01<<DOR))
		  {
			  USART0.ReadMsg_Error = USART_OverRunError;
		  }
		  else 
		  {
			  USART0.ReadMsg_Error = USART_NoError;
		  }
		    
	}	
	if (USART0.DataFrameFormat == USART_9BitDataFrame)
	{
		Rx_Data = UCSRA_REG & (1<<RxB8)<<7;
	}
	
	Rx_Data |= UDR_REG;
	
	return Rx_Data;
		
}


uint8 USART_RxByteNonBlockingMode(void)
{
	uint8 Rx_Data = 0;
	
	if  ((UCSRA_REG & (0x01<<RxC)) == 0)
	{

		if (UCSRA_REG & ((0x01<<FE) | (0x01<<PE) | (0x01<<DOR)))
		{
			//ERROR :You should handle it as i wish
			if (UCSRA_REG & (0x01<<FE))
			{
				USART0.ReadMsg_Error = USART_FrameError;
			}
			else if(UCSRA_REG & (0x01<<PE))
			{
				USART0.ReadMsg_Error = USART_ParityError;
			}
			else if (UCSRA_REG &(0x01<<DOR))
			{
				USART0.ReadMsg_Error = USART_OverRunError;
			}
			else
			{
				USART0.ReadMsg_Error = USART_NoError;
			}
		
		}
		if (USART0.DataFrameFormat == USART_9BitDataFrame)
			{
				Rx_Data = UCSRA_REG & (1<<RxB8)<<7;
			}
	
		 Rx_Data |= UDR_REG;
    }
	return Rx_Data;
}