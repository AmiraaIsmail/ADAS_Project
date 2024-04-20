#include <stdint.h>
#include "BIT_MATH.h"
#include "ultrasonic.h"
#include "tm4c123gh6pm.h"

/* Timer0A initialization function */
/* Initialize Timer0A in input-edge time mode with up-count mode */

void Ultrasonic_Init(void)
{
    SYSCTL_RCGCTIMER_R |= 8;     /* enable clock to Timer Block 0 */
    SYSCTL_RCGCGPIO_R |= 2;      /* enable clock to PORTB */
    GPIO_PORTB_DIR_R &= ~0x0C;        /* make PB6 PB7 an input pin */
    GPIO_PORTB_DEN_R |= 0x0C;         /* make PB6 PB7 as digital pin */
    GPIO_PORTB_AFSEL_R |= 0x0C;       /* use PB6 PB7 alternate function */
    GPIO_PORTB_PCTL_R &= ~0x0000FF00;  /* configure PB6 PB7 for T0CCP0 */
    GPIO_PORTB_PCTL_R |=  0x00007700;
   /* PA3 as a digital output signal to provide trigger signal */
    SYSCTL_RCGCGPIO_R |= 1;      /* enable clock to PORTA */
    GPIO_PORTA_DIR_R |=(1<<3);         /* set PA3 as a digial output pin */
    GPIO_PORTA_DEN_R |=(1<<3);         /* make PA3 as digital pin */
    GPIO_PORTA_DIR_R |=(1<<2);         /* set PA2 as a digial output pin */
    GPIO_PORTA_DEN_R |=(1<<2);         /* make PA2 as digital pin */
    TIMER3_CTL_R &= ~1;          /* disable timer0A during setup */
    TIMER3_CFG_R |= 4;            /* 16-bit timer mode */
    TIMER3_TAMR_R = 0x17;        /* up-count, edge-time, capture mode */
    TIMER3_TBMR_R = 0x17;        /* up-count, edge-time, capture mode */
    TIMER3_CTL_R |=0xC0C;        /* capture the both  edge */
    TIMER3_CTL_R |= (1<<0);           /* enable timer0A */
    TIMER3_CTL_R |= (1<<8);           /* enable timer0B */

}

/* This function captures consecutive rising and falling edges of a periodic signal */
/* from Timer Block 0 Timer A and returns the time difference (the period of the signal). */
uint32_t UltrasonicFront_u32GetDistance(void)
{
    uint32_t lastEdge, thisEdge, time,distance;

         /* Given 10us trigger pulse pinA3*/
         GPIO_PORTA_DATA_R &= ~(1<<3); /* make trigger  pin high */
         Delay_MicroSecond(10); /*10 seconds delay */
         GPIO_PORTA_DATA_R |= (1<<3); /* make trigger  pin high */
         Delay_MicroSecond(10); /*10 seconds delay */
         GPIO_PORTA_DATA_R &= ~(1<<3); /* make trigger  pin low */

//         while(GET_BIT(TIMER0_RIS_R , 2) == 0);    /* wait till captured */

         while(GET_BIT(TIMER3_RIS_R , 2) == 0);    /* wait till captured */
         TIMER3_ICR_R= 4;                   /* clear timer0A capture flag */


       lastEdge = TIMER3_TAR_R;     /* save the timestamp */
           /* detect falling edge */

       while(GET_BIT(TIMER3_RIS_R , 2) == 0);     /* wait till captured */
       TIMER3_ICR_R= 4;                     /* clear timer0A capture flag */

       thisEdge = TIMER3_TAR_R;     /* save the timestamp */
           time= (thisEdge - lastEdge); /* return the time difference */
           distance = ((time * 625)/(10000*58));
           return distance;
}

uint32_t UltrasonicBack_u32GetDistance(void)
{
    uint32_t lastEdge, thisEdge, time,distance;

         /* Given 10us trigger pulse pinA2*/
         GPIO_PORTA_DATA_R &= ~(1<<2); /* make trigger  pin high */
         Delay_MicroSecond(10); /*10 seconds delay */
         GPIO_PORTA_DATA_R |= (1<<2); /* make trigger  pin high */
         Delay_MicroSecond(10); /*10 seconds delay */
         GPIO_PORTA_DATA_R &= ~(1<<2); /* make trigger  pin low */

       while(GET_BIT(TIMER3_RIS_R , 10) == 0) ;    /* wait till captured */
       TIMER3_ICR_R= 1024;                   /* clear timer0A capture flag */

       lastEdge = TIMER3_TBR_R;     /* save the timestamp */
           /* detect falling edge */
       while(GET_BIT(TIMER3_RIS_R , 10) == 0) ;    /* wait till captured */
       TIMER3_ICR_R= 1024;                   /* clear timer0A capture flag */

       thisEdge = TIMER3_TBR_R;     /* save the timestamp */
           time= (thisEdge - lastEdge); /* return the time difference */
           distance = ((time * 625)/(10000*58));
           return distance;
}
/* Create one microsecond second delay using Timer block 1 and sub timer A */

void Delay_MicroSecond(uint32_t time)
{
    uint32_t i;
    SYSCTL_RCGCTIMER_R |= 2;     /* enable clock to Timer Block 1 */
    TIMER1_CTL_R |= 2;            /* disable Timer before initialization */
    TIMER1_CFG_R |= 0x04;         /* 16-bit option */
    TIMER1_TAMR_R = 0x02;        /* periodic mode and down-counter */
    TIMER1_TAILR_R = 16 - 1;  /* TimerA interval load value reg */
    TIMER1_ICR_R = 0x1;          /* clear the TimerA timeout flag */
    TIMER1_CTL_R |= 0x01;        /* enable Timer A after initialization */

    for(i = 0; i < time; i++)
    {
        while ((TIMER1_RIS_R & 0x1) == 0) ;      /* wait for TimerA timeout flag */
        TIMER1_ICR_R = 0x1;      /* clear the TimerA timeout flag */
    }
}











