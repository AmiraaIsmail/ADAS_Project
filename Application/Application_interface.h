/*
 * Application_interface.h
 *
 *  Created on: Apr 4, 2024
 *      Author: M0rE
 */

#ifndef APPLICATION_APPLICATION_INTERFACE_H_
#define APPLICATION_APPLICATION_INTERFACE_H_

#include "stdint.h"

typedef enum
{
    Vehicle_Stop_Mode,
    Vehicle_Driver_Mode,
    Vehicle_Cruise_Control_Mode,
    Vehilce_Auto_Parking_Mode
} VehicleMode_t;

typedef enum {
    LED_Stop,
    LED_BlinkFast,
    LED_BlindMid,
    LED_BlindSlow

}BlinlingLED_t;

static VehicleMode_t VehicleMode_obj = Vehicle_Stop_Mode;

void Update_Vehicle_Mode(void);

void Check_Frontal_Sensor(void);

void Initiate_AutoParking_Mode(void);

void itoa(uint32_t n, uint8_t s[]);

#endif /* APPLICATION_APPLICATION_INTERFACE_H_ */
