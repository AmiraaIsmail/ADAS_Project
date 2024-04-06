/*
 * LED_interface.h
 *
 *  Created on: Apr 5, 2024
 *      Author: M0rE
 */

#ifndef LED_LED_INTERFACE_H_
#define LED_LED_INTERFACE_H_

#include "stdint.h"
#include  <stdbool.h>


#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "BitMath.h"
#include "tm4c123gh6pm.h"
#define BUILT_IN_LED_1_RED  1
#define BUILT_IN_LED_2_GREEN  2
#define BUILT_IN_LED_3_BLUE  3

void LED_Init(uint8_t LED_NUMBER);

void LED_on(uint8_t LED_NUMBER);

void LED_off(uint8_t LED_NUMBER);

void LED_Toggle(uint8_t LED_NUMBER);

#endif /* LED_LED_INTERFACE_H_ */
