// DIO.h 


#ifndef _DIO_H
#define _DIO_H

#include "types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NUM_OF_PORTS           6
#define NUM_OF_PINS_PER_PORT   8

#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3
#define PORTE_ID               4
#define PORTF_ID               5


#define PIN0_ID                0
#define PIN1_ID                1U
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}DIO_PinDirectionType;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}DIO_PortDirectionType;
typedef enum
{
	PIN,PORT
}DIO_PINORPORT;


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void DIO_init(uint32 port_num, uint32 pin_num, DIO_PinDirectionType direction, DIO_PortDirectionType direction2, DIO_PINORPORT num);
void DIO_writePin(uint32 port_num, uint32 pin_num, uint32 value);
void DIO_writePort(uint32 port_num, uint32 value);
uint32 DIO_readPin(uint32 port_num, uint32 pin_num);
uint32 DIO_readPort(uint32 port_num);


#endif /*_DIO_H_*/
