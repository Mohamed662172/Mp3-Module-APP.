/*
 * MAIN.c
 *
 */
/*****************************************INCLUDE_LIBERARY**********************************/
#include "DIO.h"


/****************************************PROTOTYPE_FUNCTION*********************************/



/*****************************************main_body_of_atmega_32****************************/
int main(void){

DIO_SET_PIN_DIRECTION(PORT_A,PIN_1,OUTPUT);
while(1){
	TOGGEL_PIN_ID(PORT_A,PIN_1);

}

}
