/*
 * Application_program.c
 *
 *  Created on: Apr 4, 2024
 *      Author: M0rE
 */
#include "Application_interface.h"

void Update_Vehicle_Mode(void)
{
    /*
     * Checks For User inputs on these buttons :
     *
     * Start vehicle button  -----
     *                            | --- could be one button
     * Change mode button    -----
     *
     * Auto parking Mode Button
     *
     *
     * */

}

void Check_Frontal_Sensor(void)
{

    /*
     * based on Current Mode the vehicle
     * on this should take Different Action
     * */
    switch (VehicleMode_obj)
    {
    case Vehicle_Driver_Mode:
        /*
         * Get distance from frontal Sensor
         * compare it with 2 threshold
         * if its too close change state to stop and then break
         * if its within the 2 threshold warn driver to slow down
         * if its above the threshold do nothing or give him a green light to increase vehicle speed
         *
         * */

        /*
         * could add blind spot check here for future implementation
         * */

        break;
    case Vehicle_Cruise_Control_Mode:
        /*
         * Get distance from frontal Sensor
         * compare it with 2 threshold
         * if its too close change state to stop and then break
         * if its within the 2 threshold slow down immediately
         * if its above the threshold increase vehicle
         * speed within top threshold mostly predefined
         *
         * */
        break;

    default:
        break;
    }

}

extern BlinlingLED_t BlinkState_LED1;

void Initiate_AutoParking_Mode(void)
{
    /*
     * If the vehicle is in Stop mode and user
     * pressed Parking button this function should be called
     * */
    if (VehicleMode_obj == Vehilce_Auto_Parking_Mode)
    {

        BlinkState_LED1 = LED_BlinkFast;
        /*
         * Scan For possible Space take 2 readings from ultrasonic rear/front
         * suspend task for 1.5 seconds
         * calculate length between 2 readings from ultrasonic
         * if it fit move for 0.5 seconds
         * stop
         * then return with and angle  for 0.5seconds
         * stop
         * then rotate in place
         * */

    }
    else
    {
        /*
         * warn driver that auto parking is disabled within the current mode
         * */
    }

}

/* reverse:  reverse string s in place */
void reverse(uint8_t s[], uint16_t len)
{
    uint16_t i, j;
    uint8_t c;

    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(uint32_t n, uint8_t s[])
{
    uint16_t i, len;
    len = 0;
    i = 0;
    do
    {
        /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
        len++;
    }
    while ((n /= 10) > 0); /* delete it */

    s[i] = '\0';
    reverse(s, len);
}
