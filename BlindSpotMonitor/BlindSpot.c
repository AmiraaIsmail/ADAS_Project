/*
 * BlindSpot.c
 *
 *  Created on: Apr 13, 2024
 *      Author: Lenovo
 */
#include "Ultrasonic/ultrasonic.h"
#include "BlindSpot.h"

VehicleState_t BlindSpotMonitor(void)
{
    /* */
    uint8_t  LocalVehicleState;
    /* read the value of distance*/
    uint32_t  local_Back_distance=UltrasonicBack_u32GetDistance();
    /*check if the Back_distance is greater than threshold2 and less than max range */
    if((local_Back_distance>=Threshold2) && (local_Back_distance<=MAXRange))
    {
        /*update local vehicle state to normal state*/
        LocalVehicleState=NormalState;
        /*according to this state*/
        /*turn on blink led */
        /*maintain speed or increase it*/

    }

    /*check if the Back_distance is greater than or equal to threshold1 and less than threshold2 */
    else if((local_Back_distance>=Threshold1) && (local_Back_distance<Threshold2))
    {
        /*update local vehicle state to warning state*/
        LocalVehicleState=WarningState;
        /*turn on green led and turn off alarm according to this state*/
        /*turn on blinking led with medium speed*/


    }

    /*check if the Back_distance is less than threshold1 */
    else if((local_Back_distance<Threshold1))
    {
        /*update local vehicle state to urgent state*/
        LocalVehicleState=UrgentState;
        /*turn on red led and turn alarm

        / *on according to this state*/

    }

    return LocalVehicleState;

}










