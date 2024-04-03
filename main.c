#include  <stdint.h>
#include  <stdbool.h>

#include <FreeRTOS.h>
#include <task.h>

#include  "driverlib/systick.h"
#include  "driverlib/interrupt.h"

#include  "inc/hw_nvic.h"
#include  "inc/hw_types.h"
#include  "inc/hw_ints.h"

uint32_t SystemCoreClock = 16000000;

void vPeriodicTask(void *pvParameters)
{

    // Establish the task's period.
    const TickType_t xDelay = pdMS_TO_TICKS(1000);
    TickType_t xLastWakeTime = xTaskGetTickCount();

    for (;;) {


        // Block until the next release time.
        vTaskDelayUntil(&xLastWakeTime, xDelay);
    }

}



int main()
{
    IntMasterEnable();

    xTaskCreate(vPeriodicTask, "My Task", 256, NULL, 1, NULL);

    // Startup of the FreeRTOS scheduler.  The program should block here.
    vTaskStartScheduler();

    // The following line should never be reached.  Failure to allocate enough
    //  memory from the heap would be one reason.
    for (;;);

}
