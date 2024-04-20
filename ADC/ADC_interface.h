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

void ADC_Init(uint32_t copy_u32ChannelNumber);
uint32_t ADC_GetChannelRead(uint32_t copy_u32ChannelNumber);

#endif /* ADC_ADC_INTERFACE_H_ */
