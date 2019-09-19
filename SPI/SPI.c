/*
 * SPI.c
 *
 *  Created on: Sep 14, 2019
 *      Author: Amr
 */
#include "../../LIB/std_types.h"
#include "../../LIB/Bit_Math.h"


#include "DIO_reg.h"
#include "DIO_types.h"
#include "DIO.h"

#include "SPI_reg.h"
#include "SPI_types.h"
#include "SPI_config.h"
#include "SPI.h"



void SPI_Initialize(void){
	/*Clearing SPCR Register &Clearing bit 7 'INTERRUPT ENABLE' **We Will Use Polling Method** */
	SPCR_Reg=0x00;
/*Enabling The SPI  Communication Mode*/
	SPCR_Reg|=0b01000000;

	/************  Deciding Which of The Bits Will Be Sent First(MSB/LSB)**************/
#if(SPI_DATA_ORDER==SPI_MSB_FIRST)

SPCR_Reg|=SPI_MSB_FIRST;
#elif(SPI_DATA_ORDER==SPI_LSB_FIRST)

SPCR_Reg|=SPI_LSB_FIRST;

#endif

/************  Deciding Whether The MicroController Is A Master Or A Slave**************/
#if(SPI_MASTER_SLAVE_SELECT	==SPI_MASTER)

SPCR_Reg|=SPI_MASTER;

#elif(SPI_MASTER_SLAVE_SELECT==SPI_SLAVE)

SPCR_Reg|=SPI_SLAVE;

#endif
/*********Selecting The Sending Method For The BITS In Every Rising Edge 'CLK' Or Falling One******************************************/
#if(SPI_CLK_POLARITY_SELECT==SPI_CLK_POL_RISING)

SPCR_Reg|=SPI_CLK_POL_RISING;

#elif(SPI_CLK_POLARITY_SELECT==SPI_CLK_POL_FALLING)
SPCR_Reg|=SPI_CLK_POL_FALLING;

#endif

/***************Selecting The Sampling First Or The Setup First ***********************/
#if(SPI_CLK_PHASE_SELECT==SPI_CLK_PHA_SETUP_FIRST)

SPCR_Reg|=SPI_CLK_PHA_SETUP_FIRST;
#elif(SPI_CLK_PHASE_SELECT==SPI_CLK_PHA_SAMPLE_FIRST)
SPCR_Reg|=SPI_CLK_PHA_SAMPLE_FIRST;

#endif

/*Selecting CLK Prescaler*/

#if(SPI_CLK_PRESCALER_SELECT==SPI_CLK_PRESCALER_4)

SPCR_Reg|=SPI_CLK_PRESCALER_4;

#elif(SPI_CLK_PRESCALER_SELECT==SPI_CLK_PRESCALER_16)

SPCR_Reg|=SPI_CLK_PRESCALER_16;


#elif(SPI_CLK_PRESCALER_SELECT==SPI_CLK_PRESCALER_64)

SPCR_Reg|=SPI_CLK_PRESCALER_64;

#elif(SPI_CLK_PRESCALER_SELECT==SPI_CLK_PRESCALER_128)

SPCR_Reg|=SPI_CLK_PRESCALER_128;


#endif


}

uint8 SPI_SendData(DIO_PortType PortId, uint8 PortValue, uint8 Data){

if(PortId<=PORTD){

	switch(PortId){

	case PORTA : DDRA_Reg=PortValue; break;
	case PORTB : DDRB_Reg=PortValue; break;
	case PORTC : DDRC_Reg=PortValue; break;
	case PORTD : DDRD_Reg=PortValue; break;
    default: /*WRONG SELECTION*/     break;
	              }
	SPDR_Reg=Data;
while(GetBit(SPSR_Reg,7)!=1);


}

return SPDR_Reg;

}
uint8 SPI_DataReceived(){



}
