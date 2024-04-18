/*
 * LCD_interface.h
 *
 *  Created on: Apr 2, 2024
 *      Author: SMART
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#include "BIT_Math.h"

void LCD_Init(void);
void LCD_SendCmd( uint8_t command);
void LCD_Write4bits( uint8_t data,  uint8_t control);
void LCD_WriteString( uint8_t *str);
void LCD4bits_Char( uint8_t data);
void LCD_CLEAR_SCREEN(void);
void LCD_GOTOXY( uint8_t line,  uint8_t position);
void LCD_voidWriteNumber( int32_t Copy_u8num );
void delayMs(uint32_t n);
void delayUs(uint32_t n);


#endif /* LCD_INTERFACE_H_ */
