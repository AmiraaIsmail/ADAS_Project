#include  <stdint.h>
#include  <stdbool.h>

#include <FreeRTOS.h>
#include <task.h>

#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"

#include  "BitMath.h"
#include  "tm4c123gh6pm.h"

#include "Application/Application_interface.h"

#include "UART_0/UART_0_interface.h"

uint32_t SystemCoreClock = 16000000;

#define BUILT_IN_LED_1  1
#define BUILT_IN_LED_2  2
#define BUILT_IN_LED_3  3

void vPeriodicTask(void *pvParameters)
{

    // Establish the task's period.
    const TickType_t xDelay = pdMS_TO_TICKS(1000);
    TickType_t xLastWakeTime = xTaskGetTickCount();

    for (;;)
    {

        Tog_Bit(GPIO_PORTF_DATA_R, BUILT_IN_LED_3);

        uart_sendString("helllllllllo\n");

        // Block until the next release time.
        //vTaskDelayUntil(&xLastWakeTime, xDelay);
        vTaskDelay(xDelay);
    }

}



int main()
{
    //---------------------------------------------------------------
    // Enable the GPIOF peripheral
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    // Wait for the GPIOF module to be ready.
    //
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }
    /*
     // Set pins 2, 4, and 5 as input, SW controlled.
     //
     GPIOPinTypeGPIOInput(GPIO_PORTA_BASE,
     GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
     * */

    // Set pins 2 and 3 as output, SW controlled.
    //
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2 | GPIO_PIN_3);
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_HIGH_LEVEL);
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_HIGH_LEVEL);
//-------------------------------------------------------------------
// PA0 Tx pin   PA1 Rx pin
    uart_init();

    xTaskCreate(vPeriodicTask, "My Task", 256, NULL, 1, NULL);

    // Startup of the FreeRTOS scheduler.  The program should block here.
    vTaskStartScheduler();

    // The following line should never be reached.  Failure to allocate enough
    //  memory from the heap would be one reason.
    for (;;)
        ;

}
