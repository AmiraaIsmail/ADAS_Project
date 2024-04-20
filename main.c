/* Library includes. */

#include  <stdint.h>
#include  <stdbool.h>

/* FreeRTOS includes. */

#include <FreeRTOS.h>
#include <task.h>

/* other includes. */

// Application Logic
#include "Application/Application_interface.h"

// Drivers
#include "GPIO/GPIO.h"
#include "UART_0/UART_0_interface.h"
#include "SERVO/ServoMotor_Interface.h"
#include "LCD/LCD_interface.h"
#include "SERVO/ServoMotor_Interface.h"
#include "Ultrasonic/ultrasonic.h"

// Utils
//#include "STD_TYPES.h"
// #include <stdio.h>

/* #defines  */

uint32_t SystemCoreClock = 16000000;

// Tasks Implementation

//---------------------------------------------------------------------------------------------------
BlinlingLED_t BlinkState_LED1 = LED_Stop;

// LED Indicator Tasks
// TODO Test Validity of multiple occurrences of this task

void pxTaskBlindLED1(void *pvParameters)
{
    TickType_t xDelay;
    for (;;)
    {
        switch (BlinkState_LED1)
        {
        case LED_Full:
            xDelay = 1;
            break;
        case LED_Stop:
            xDelay = 0;
            break;
        case LED_BlinkFast:

            xDelay = 100 / portTICK_PERIOD_MS;
            break;
        case LED_BlindMid:

            xDelay = 400 / portTICK_PERIOD_MS;
            break;
        case LED_BlindSlow:

            xDelay = 800 / portTICK_PERIOD_MS;
            break;
        default:
            break;
        }
        if (xDelay > 1)
        {

            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
            vTaskDelay(xDelay);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x00);
            vTaskDelay(xDelay);
        }
        else if (xDelay == 1)
        {
            //LED is On
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
        }
        else if (xDelay == 0)
        {
            //LED is Off
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x00);

        }
        else
        {
            UART_0_SendString("Error LED state\n");
        }
    }
}

//---------------------------------------------------------------------------------------------------
void pxTaskPOV(void *pvParameters)
{
    const TickType_t xDelay = 500 / portTICK_PERIOD_MS;

    for (;;)
    {
//          PB6 echo   PB2 trig

        uint32_t distance = UltrasonicFront_u32GetDistance();

        uint8_t distance_str[12];

        itoa((distance), distance_str);
        if (distance < 5)
        {
            BlinkState_LED1 = LED_BlinkFast;
        }
        else if (distance > 10)
        {
            BlinkState_LED1 = LED_BlindSlow;
        }
//        sprintf((char*)distance_str, "%i", distance);
        UART_0_SendString((uint8_t*) distance_str);

        UART_0_SendString(" CM\t");

        vTaskDelay(xDelay);
    }
}
//---------------------------------------------------------------------------------------------------

int main()
{
//Init Section

//Init Led
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);

// Init UltraSonic
    TIMER3_voidCaptureInit();

    //Init UART
    UART_0_Init();

//Create Tasks

    xTaskCreate(pxTaskPOV, "23", 256, NULL, 1, NULL);
    xTaskCreate(pxTaskBlindLED1, "24", 256, NULL, 1, NULL);

    // Startup of the FreeRTOS scheduler.  The program should block here.
    vTaskStartScheduler();

    // The following line should never be reached.  Failure to allocate enough
    //  memory from the heap would be one reason.
    for (;;)
        ;

}
