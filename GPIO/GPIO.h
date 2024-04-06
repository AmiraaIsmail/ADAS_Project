#ifndef GPIO_H_
#define GPIO_H_

#include "STD_TYPES.h"

typedef enum
{
    PA=0,
    PB,
    PC,
    PD,
    PE,
    PF
}PORT_ID;


typedef enum
{
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}PIN_ID;


typedef enum
{
    OUT=0,
    INPUT,
    INPULLUP,
    INPULLDOWN
}DIRECTION_ID;


typedef enum
{
    LOW=0,
    HIGH
}VOLTAGE_ID;


void GPIO_Init_Port(PORT_ID port);

void GPIO_Set_Pin_Direction(PORT_ID port ,PIN_ID pin,DIRECTION_ID direction);

void GPIO_Set_Port_Direction(PORT_ID port,DIRECTION_ID direction);

void GPIO_Set_Pin_Value(PORT_ID port,PIN_ID pin,VOLTAGE_ID value);

void GPIO_Set_Port_Value(PORT_ID port,u8 value);

u8 GPIO_Get_Pin_Value(PORT_ID port,PIN_ID pin);

void GPIO_Toggle_Pin_Value(PORT_ID port,PIN_ID pin);

#endif /* GPIO_H_ */
