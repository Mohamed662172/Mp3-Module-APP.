/*
 * UART_Reusable.c
 *
 * Created: 28/04/2020 06:05:10 AM
 *  Author: EL_abbas salah hatata
 */ 

#include "ATMEGA32A_UART.h"
#include "Mp3_Module.h"
#include "DIO.h"


int main(void)
{
	Mp3M0.play(1);
	DELAY_FUN(1000);
	Mp3M0.stop();		
    
	while(1)
    {
        //TODO:: Please write your application code 
    }
}