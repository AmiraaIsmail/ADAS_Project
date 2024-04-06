/*
 * LCD_config.h
 *
 *  Created on: Apr 2, 2024
 *      Author: SMART
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#define RS                 0x01
#define EN                 0x02
#define RW                 0x04                 //EN -> PB2 (0x04)

#define LCD_DATA             PA
#define LCD_CONTROL          PB

#define LCD_DATA_REG            GPIO_PORTA_DATA_R
#define LCD_CONTROL_REG         GPIO_PORTB_DATA_R


#endif /* LCD_CONFIG_H_ */
