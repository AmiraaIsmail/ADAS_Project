/*
 * LEDS.h
 *
 *  Created on: Apr 14, 2024
 *      Author: Lenovo
 */

#ifndef LEDS_H_
#define LEDS_H_

/*enum for leds types*/
typedef enum{
    RedLed,
    BlueLed,
}LED_type;

void LED_ON(LED_type LED);

void LED_OFF(void);

void Alarm_ON(void);

void Alarm_OFF(void);

#endif /* LEDS_H_ */
