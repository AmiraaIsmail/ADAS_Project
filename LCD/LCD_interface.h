/*
 * LCD_interface.h
 *
 *  Created on: Apr 2, 2024
 *      Author: SMART
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#include "BIT_Math.h"
#include "STD_TYPES.h"

void LCD_Init(void);
void LCD_SendCmd( u8 command);
void LCD_Write4bits( u8 data,  u8 control);
void LCD_WriteString( u8 *str);
void LCD4bits_Char( u8 data);
void LCD_CLEAR_SCREEN(void);
void LCD_GOTOXY( u8 line,  u8 position);
void LCD_voidWriteNumber( u32 Copy_u8num );
void delayMs(u32 n);
void delayUs(u32 n);


#endif /* LCD_INTERFACE_H_ */
