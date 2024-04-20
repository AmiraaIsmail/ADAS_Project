/*
 * @ file:   ultrasonic.h
 * @ brief:  Ultrasonic  file.h
 * @ Author: Lenovo
 * @ Date:   Apr 6, 2024
 * @ Version 1.0
 */

#ifndef ULTASONIC_H_
#define ULTASONIC_H_

#include "stdint.h"
/*
 * @ Brief : this function initialize Timer3 in input-edge time mode with up-count mode
 * @ Parameter: void
 * @ Return :   void
 */
void TIMER3_voidCaptureInit(void);
/*
 * @ Brief:  This function calculates the distance for front Ultrasonic as it captures consecutive rising and falling edges of a periodic signal
 * @ Parameter: void
 * @ Return :   u32(distance)
 */
uint32_t UltrasonicFront_u32GetDistance(void);
/*
 * @ Brief:  This function calculates the distance for back Ultrasonic as it captures consecutive rising and falling edges of a periodic signal
 * @ Parameter: void
 * @ Return :   u32(distance)
 */
uint32_t UltrasonicBack_u32GetDistance(void);
/*
 * @ Brief : this function make delay of microsecond
 * @ Parameter: u32(time)
 * @ Return :   void
 */
void Delay_MicroSecond(uint32_t time);


#endif /* ULTASONIC_H_ */
