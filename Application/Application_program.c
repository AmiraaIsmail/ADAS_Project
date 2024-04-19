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
         * adjust Servo Motor with proper right-angle
         * Assuming Servo Motor Already initialized
         * and settled with wanted frequency
         *
         * */
        ServoMotor_Start(0, 180);
        ServoMotor_Start(1, 0);
        /*
         * Assuming Ultrasonic Already initialized
         * */
        uint32_t distance1;
        uint32_t distance2;

        /* set timer to 5 sec delay to timeout this feature
         * */
        //dummy values
        uint32_t Timer_timeout_flag = 1;
        uint32_t threshold_in_Cm = 9;
        bool PossibleSpot_acuainted;
        bool FoundSpot = false;

        /*
         * Scan For possible Space take 2 readings from ultrasonic rear/front
         * */
        while (Timer_timeout_flag || FoundSpot)
        {
            distance1 = UltrasonicBack_u32GetDistance();
            distance2 = UltrasonicFront_u32GetDistance();

            if (distance1 > threshold_in_Cm && distance2 < threshold_in_Cm)
            {  // possible spot
                PossibleSpot_acuainted = true;
            }

            if (distance1 > threshold_in_Cm&& distance2 > threshold_in_Cm
            && PossibleSpot_acuainted == true)
            {  // Found a spot
                PossibleSpot_acuainted = false;
                FoundSpot = true;
            }

            if (distance1 < threshold_in_Cm && distance2 < threshold_in_Cm)
            {  // possible spot
                PossibleSpot_acuainted = false;
            }

        }  // End of while

        if (FoundSpot)
        {        // Suitable Spot for parking detected

            // move vehicle forward for 0.5 seconds
            // reverse with angle 45 if possible
            // move backwards while having the same angle
            // stop
            // rotate within the same place
        }
        else
        {        // Task Time-out or didn't find suitable spot
            // Blink LED to inform driver that no possible parking spot found
            // yield task if possible

        }
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
