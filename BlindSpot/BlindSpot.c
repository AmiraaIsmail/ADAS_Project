/*
 * BlindSpot.c
 *
 *  Created on: Apr 13, 2024
 *      Author: Lenovo
 */

#include "BIT_MATH.h"
#include "GPIO/GPIO.h"
#include "Ultrasonic/ultrasonic.h"
#include "BlindSpot.h"
#include "LEDS.h"
#include "LEDConfig.h"

/* Backward Distance of vehicle is a global variable*/
uint32_t Back_distance;

/* vehicle_State is a global variable*/
uint8_t vehicle_State;

VehicleState_t BlindSpotMonitor(void)
{
    /* */
    uint8_t LocalVehicleState;
    /* read the value of distance*/
    uint32_t local_Back_distance=Back_distance;
    /*check if the Back_distance is greater than threshold2 and less than max range */
    if((local_Back_distance>=Threshold2) && (local_Back_distance<=MAXRange))
    {
        /*update local vehicle state to normal state*/
        LocalVehicleState=NormalState;
        /*turn off leds and turn off alarm according to this state*/
        //LED_OFF();
        // Alarm_OFF();

    }

    /*check if the Back_distance is greater than or equal to threshold1 and less than threshold2 */
    else if((local_Back_distance>=Threshold1) && (local_Back_distance<Threshold2))
    {
        /*update local vehicle state to warning state*/
        LocalVehicleState=WarningState;
        /*turn on green led and turn off alarm according to this state*/
        //LED_ON(BlueLed);
        //Alarm_OFF();

    }

    /*check if the Back_distance is less than threshold1 */
    else if((local_Back_distance<Threshold1))
    {
        /*update local vehicle state to urgent state*/
        LocalVehicleState=UrgentState;
        /*turn on red led and turn alarm on according to this state*/
        //LED_ON(RedLed);
        //Alarm_ON();

    }

    return LocalVehicleState;

}










