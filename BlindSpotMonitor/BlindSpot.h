/*
 * BlindSpot.h
 *
 *  Created on: Apr 13, 2024
 *      Author: Lenovo
 */

#ifndef BLINDSPOT_H_
#define BLINDSPOT_H_

#include "stdint.h"

#define Threshold1     10
#define Threshold2     20
#define MAXRange       45

typedef enum{
    NormalState=0,
    WarningState,
    UrgentState
}VehicleState_t;

VehicleState_t BlindSpotMonitor(void);




#endif /* BLINDSPOT_H_ */
