/*
 * ADC_interface.h
 *
 *  Created on: Apr 19, 2024
 *      Author: M0rE
 */

#ifndef ADC_ADC_INTERFACE_H_
#define ADC_ADC_INTERFACE_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/adc.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

/*
 Analog Channel    Pin Name    Pin Number
 AN0                PE3         6
 AN1                PE2         7
 AN2                PE1         8
 AN3                PE0         9
 AN4                PD3         64
 AN5                PD2         63
 AN6                PD1         62
 AN7                PD0         61
 AN8                PE5         60
 AN9                PE4         59
 AN10               PB4         58
 AN11               PB5         57
 * */

// E.G.    ADC_Init(GPIO_PIN_5,ADC_CTL_CH8);
uint32_t ADC_MapValue(uint32_t x, uint32_t in_min, uint32_t in_max,
                      uint32_t out_min, uint32_t out_max);
void ADC_Init(uint32_t GPIO_pin, uint32_t ADC_channel);

uint32_t ADC_GetChannelRead();

#endif /* ADC_ADC_INTERFACE_H_ */
