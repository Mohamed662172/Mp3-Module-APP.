/*
 * Mp3_Module.c
 *
 */ 

#include "Mp3_Module.h"
#include "DIO.h"



uint16  Mp3STACK[STACK_SIZE]={SB,VER,LEN,Diactivate,NO_FEEDBACK,Diactivate,Diactivate,Diactivate,Diactivate,EB};



Mp3_API      Mp3M0={0};



static void Execut_CMDFormat(void)
{
	uint8 index = 0x00;
	uint8 CheckSum = 0x00; 
	uint8 Add_Frame =0x00;
	for (index=0x00;index<STACK_SIZE;index++)
	{
			USART_TxByteBlockingMode(Mp3STACK[index]);
	}
	if (index>Mp3_indVER  && index<Mp3_indCheck_MSB)
	{
		Add_Frame += Mp3STACK[index];
	}
	else if (index == Mp3_indCheck_MSB )
	{
		CheckSum = 0xFFFF- Add_Frame +1;
		Mp3STACK[Mp3_indCheck_MSB] = CheckSum >> 8;
		Mp3STACK[Mp3_indCheck_LSB] = (uint8)CheckSum; 
	} 
	else
	{
		/* Do Nothing */
	}
		
} 



void Mp3Module_Init(void)
{
	/* Configure   USART During RunTime */
	USART0.BaudRate=9600;
	USART0.EnableMode= USART_TxEnable;
	USART0.CommunicationMode= USART_Async_DoubleSpeedMode;
	USART0.CommunicationTerminal= USART_SingleProcessor;
	USART0.DataFrameFormat = USART_8BitDataFrame;
	USART0.ControlFrameFormat = USART_ParityDisable_1StopBit;
	USART0.InterrupetSource =  USART_DisableInterrupt;
	USART0.ReadMsg_Error =  USART_NoError;
	/* USART  initiate */
	USART_init();
	/* Mp3   Player  OnLine */
	Mp3M0.reset();
	DELAY_FUN(1000);				  
}

void playNext(void){
	
	Mp3STACK[Mp3_indCMD] = NEXT;
	
	Execut_CMDFormat();
	
	Mp3STACK[Mp3_indCMD] = Diactivate;
	
	}

void playPrevious(void){
	
	Mp3STACK[Mp3_indCMD] = PREV;
	
	Execut_CMDFormat();
	
	Mp3STACK[Mp3_indCMD] = Diactivate;
	
}


void play(uint16 trackNum){
	
	Mp3STACK[Mp3_indCMD] = PLAY;
	Mp3STACK[Mp3_indPara_MSB] = trackNum>>8;
	Mp3STACK[Mp3_indPara_LSB] = (uint8)trackNum;
	Execut_CMDFormat();
	Mp3STACK[Mp3_indCMD] =  Diactivate ;
	Mp3STACK[Mp3_indPara_MSB] =  Diactivate ;
	Mp3STACK[Mp3_indPara_LSB] =  Diactivate ; 
	
}


void Setvolume (uint8 volume){
	
	
	if ((0 <= volume)&&(volume <= 30)){	
		Mp3STACK[Mp3_indCMD] = VOLUME;
		Mp3STACK[Mp3_indPara_MSB] = volume>>8;
		Mp3STACK[Mp3_indPara_LSB] = (uint8)volume;
		
		Execut_CMDFormat();
		
		Mp3STACK[Mp3_indCMD] =  Diactivate ;
		Mp3STACK[Mp3_indPara_MSB] =  Diactivate ;
		Mp3STACK[Mp3_indPara_LSB] =  Diactivate ;
		}
		else
		{
			
			//  Report  error 
		}
		
}

void reset(void){
	
	Mp3STACK[Mp3_indCMD] = RESET;
	
	Execut_CMDFormat();
	
	Mp3STACK[Mp3_indCMD] = Diactivate;
}

void resume(void){
	
	Mp3STACK[Mp3_indCMD] = PLAYBACK;
	
	Execut_CMDFormat();
	
	Mp3STACK[Mp3_indCMD] = Diactivate;
} 

void stop(void){
	
	Mp3STACK[Mp3_indCMD] = STOP;
	
	Execut_CMDFormat();
	
	Mp3STACK[Mp3_indCMD] = Diactivate;
	
	
}

void incVolume(void){
	
	Mp3STACK[Mp3_indCMD] = INC_VOL;
	
	Execut_CMDFormat();
	
	Mp3STACK[Mp3_indCMD] = Diactivate;
	
	
}

void decVolume(void){
	
	Mp3STACK[Mp3_indCMD] = DEC_VOL;
	
	Execut_CMDFormat();
	
	Mp3STACK[Mp3_indCMD] = Diactivate;
	
}

void EQSelect(uint8 setting){
	
	if (setting>6)
	{
		
		Mp3STACK[Mp3_indCMD] = EQ;
		
		Execut_CMDFormat();
		
		Mp3STACK[Mp3_indCMD] = Diactivate;
	} 
	else
	{
		// Report Error  
	}
	
	
}

