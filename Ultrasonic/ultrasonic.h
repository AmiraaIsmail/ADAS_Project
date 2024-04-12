/*
 * @ file:   ultrasonic.h
 * @ brief:  Ultrasonic  file.h
 * @ Author: Lenovo
 * @ Date:   Apr 6, 2024
 * @ Version 1.0
 */

#ifndef ULTASONIC_H_
#define ULTASONIC_H_
/*
 * @ Brief : this function initialize Timer0A in input-edge time mode with up-count mode
 * @ Parameter: void
 * @ Return :   void
 */
void TIMER0A_voidCaptureInit(void);
/*
 * @ Brief:  This function calculates the distance as it captures consecutive rising and falling edges of a periodic signal
 * @ Parameter: void
 * @ Return :   u32(distance)
 */
u32 Ultrasonic_u32GetDistance(void);
/*
 * @ Brief : this function make delay of microsecond
 * @ Parameter: u32(time)
 * @ Return :   void
 */
void Delay_MicroSecond(u32 time);
/*
 * @ Brief : this function make delay
 * @ Parameter: u32(counter)
 * @ Return :   void
 */
void Delay(u32 counter);



#endif /* ULTASONIC_H_ */
