/*
 * LEDS.c
 *
 *  Created on: Apr 14, 2024
 *      Author: Lenovo
 */

#include "BIT_MATH.h"
#include "GPIO/GPIO.h"
#include "Ultrasonic/ultrasonic.h"
#include "BlindSpot.h"
#include "LEDS.h"
#include "LEDConfig.h"

/*LEDS for blind spot monitoring */
void LEDS_Init(void)
{
   /*Init PINS in PORTF FOR LEDS */
   GPIO_Init_Port(PF);
   /*Init PINS in PORTE FOR LEDS */
   GPIO_Init_Port(PE);
   /*Set direction of these PNS as output*/
   GPIO_Set_Pin_Direction(PF, PIN1, OUT); // PF1 RED LED
   GPIO_Set_Pin_Direction(PF, PIN2, OUT); // PF2 BLUE LED
   /*Alarm*/
   GPIO_Set_Pin_Direction(PE, PIN1, OUT); // PE1 FOR ALARM
}

/*turn on specific led according to the state of blind spot monitoring*/
void LED_ON(LED_type LED)
{
    switch(LED)
    {
    case RedLed:
        GPIO_Set_Pin_Value(PF, PIN1, HIGH); // make red led high
        GPIO_Set_Pin_Value(PF, PIN2, LOW);  // make blue led high
        break;
    case BlueLed:
        GPIO_Set_Pin_Value(PF, PIN1, LOW);  // make red led Low
        GPIO_Set_Pin_Value(PF, PIN2, HIGH); // make blue led high
        break;
    }
}

void LEDS_OFF(void)
{
    /*turn off leds when in normal mode*/
    GPIO_Set_Pin_Value(PF, PIN1, LOW);  // make red led Low
    GPIO_Set_Pin_Value(PF, PIN2, LOW);  // make blue led high
}


/* function turn on alarm when vehicle in urgent state*/
void Alarm_ON(void)
{
    GPIO_Set_Pin_Value(PE, PIN1, HIGH);
}

void Alarm_OFF(void)
{
    GPIO_Set_Pin_Value(PE, PIN1, LOW);
}










