/*
 * ultasonic.h
 *
 *  Created on: Apr 6, 2024
 *      Author: Lenovo
 */

#ifndef ULTASONIC_H_
#define ULTASONIC_H_

void Ultrasonic_Init(void);

void TIMER0A_voidCaptureInit(void);

u32 Ultrasonic_u32GetDistance(void);

void Delay_MicroSecond(u32 time);

void Delay(u32 counter);



#endif /* ULTASONIC_H_ */
