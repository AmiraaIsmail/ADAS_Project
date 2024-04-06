#include  <stdint.h>
#include  <stdbool.h>

#include <FreeRTOS.h>
#include <task.h>


#include "Application/Application_interface.h"

#include "UART_0/UART_0_interface.h"
<<<<<<< Updated upstream
#include "SERVO/ServoMotor_Interface.h"
=======
#include "LED/LED_interface.h"

>>>>>>> Stashed changes

uint32_t SystemCoreClock = 16000000;


void vPeriodicTask(void *pvParameters)
{

    // Establish the task's period.
    const TickType_t xDelay = pdMS_TO_TICKS(1000);
    TickType_t xLastWakeTime = xTaskGetTickCount();

    for (;;)
    {
        //NON-LBOCKING UART
        UART_0_SendString("Hello World !!\n");

        LED_Toggle(BUILT_IN_LED_3_BLUE);

        // Block until the next release time.
        //vTaskDelayUntil(&xLastWakeTime, xDelay);
        vTaskDelay(xDelay);
    }

}

void ServoTest(void *pvParameters)
{
    static int16_t Angle1=0;
    static int16_t Angle2=180;
    ServoMotor_Start(Front_Servo,Angle1);
    ServoMotor_Start(Back_Servo,Angle2);
    for (;;)
    {
        ServoMotor_Start(Front_Servo,Angle1);
        ServoMotor_Start(Back_Servo,Angle2);
        Angle1+=45;
        Angle2-=45;
        if (Angle1>180)
        {
            Angle1=0;
        }
        if (Angle2<0)
        {
            Angle2=180;
        }
        vTaskDelay( pdMS_TO_TICKS( 1500 ) ) ;

    }
}

int main()
{


// PA0 Tx pin   PA1 Rx pin
    UART_0_Init();
// PF1 RED LED   Pin
    LED_Init(BUILT_IN_LED_1_RED);

    xTaskCreate(vPeriodicTask, "My Task", 256, NULL, 1, NULL);
//-------------------------------------------------------------------
//    PA6      PA7
    ServoMotor_Init();

    xTaskCreate(ServoTest,"EditDuty", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
//-------------------------------------------------------------------

    // Startup of the FreeRTOS scheduler.  The program should block here.
    vTaskStartScheduler();

    // The following line should never be reached.  Failure to allocate enough
    //  memory from the heap would be one reason.
    for (;;)
        ;

}
