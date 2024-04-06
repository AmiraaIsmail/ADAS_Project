


#ifndef  _PWM_INTERFACE_H_
#define  _PWM_INTERFACE_H_

typedef enum{
   Rigth,
   Left,   
}Rotate_t;


//PWM0_Genrator0 have two PIN PWM_OUT_0 AND PWM_OUT_1 is PB6 AND PB7 ON J2 OF TIVA C Kit
//RIGHT
#define H1_ENB1  PWM_OUT_0  //PB6
#define H1_ENA1  PWM_OUT_1  //PB7
#define H1_PORT  GPIO_PORTD_BASE
#define H1_IN1   GPIO_PIN_0
#define H1_IN2   GPIO_PIN_1
#define H1_IN3   GPIO_PIN_2
#define H1_IN4   GPIO_PIN_3

//PWM0_Genrator1 have two PIN PWM_OUT_2 AND PWM_OUT_3 is PB4 AND PB5 ON J1 OF TIVA C Kit
//LEFT
#define H2_ENB1  PWM_OUT_2  //PB4
#define H2_ENA1  PWM_OUT_3  //PB5
#define H2_PORT  GPIO_PORTC_BASE
#define H2_IN1   GPIO_PIN_4
#define H2_IN2   GPIO_PIN_5
#define H2_IN3   GPIO_PIN_6
#define H2_IN4   GPIO_PIN_7


/*
  The TM4C123GH6PM microcontroller contains two PWM modules
  each module have up to four generator block and control block
  Each PWM module provides four PWM generators, each providing two PWM outputs 
  that may be used in a wide variety of applications
*/
//PWM0_Genrator0 have two PIN PWM_OUT_0 AND PWM_OUT_1 is PB6 AND PB7 ON J2 OF TIVA C Kit
//PWM0_Genrator1 have two PIN PWM_OUT_2 AND PWM_OUT_3 is PB4 AND PB5 ON J1 OF TIVA C Kit


/*
  enable clock for Module 0  
  Assumed clock source 16MHZ So Divide by 1 so clock for Module 0 is 4MHZ Ticks 0.0625 microsecond MAX FREQ 122 HZ TO Increase chand DIV
  we use two Generator PWM0_GEN0 AND PWM0_GEN1
*/
void Wheels_Init(void);

/*
  we use Module 0 Two Fuctions to Enable and Disable PWM Genrator 0 or 1
  ui32Gen This parameter must be one of PWM_GEN_0, PWM_GEN_1
  This function blocks the PWM clock from driving the timer/counter for the specified generator block
*/
void Wheels_DisableGen(uint32_t ui32Gen);

/*
  Freq HZ for all pin of this generator which have two pins 
  ui8Freq from 0 to Max Freq 122 Hz
  ui32Gen This parameter must be one of PWM_GEN_0, PWM_GEN_1
  the Freq is applied the next time the corresponding counter becomes zero  
*/
void Wheels_SetFreq_HZ(uint32_t ui32Gen,uint8_t ui8Freq);


/*
  For module 0 
  ui8Duty from 0 to 100
  ui32PWMOut This parameter must be one of PWM_OUT_0, PWM_OUT_1, PWM_OUT_2, PWM_OUT_3 that we used
  the Duty is applied the next time the corresponding counter becomes zero  
*/
void Wheels_SetDuty(uint32_t ui32PWMOut, uint8_t ui8Duty);


/*
  Enables PWM outputs
  ui32PWMOut This parameter must be one of PWM_OUT_0_BIT, PWM_OUT_1_BIT, PWM_OUT_2_BIT, PWM_OUT_3_BIT that we used two generator
*/
void Wheels_EnableOutput(uint32_t ui32PWMOut);

/*
  disables PWM outputs
  ui32PWMOut This parameter must be one of PWM_OUT_0_BIT, PWM_OUT_1_BIT, PWM_OUT_2_BIT, PWM_OUT_3_BIT that we used two generator
*/
void Wheels_DisableOutput(uint32_t ui32PWMOut);


/*
  Enables two PWM outputs in same genrator
  when use PWM_DisableOutputGen the timer not stop so preferd to use PWMSyncTimeBase to reset timer Before use PWM_EnableOutputGen
  ui32Gen This parameter must be one of PWM_GEN_0, PWM_GEN_1 that we used
*/
void Wheels_EnableOutputGen(uint32_t ui32Gen);


/*
  Disables two PWM outputs in same genrator
  when use PWM_DisableOutputGen the timer not stop so preferd to use PWMSyncTimeBase to reset timer Before use PWM_EnableOutputGen
  ui32Gen This parameter must be one of PWM_GEN_0, PWM_GEN_1 that we used
*/
void Wheels_DisableOutputGen(uint32_t ui32Gen);

/*
  this function synchronizes the time base of the generator blocks by causing the specified generator counters to be reset to zero
  ui32Gen This parameter must be one of PWM_GEN_0_BIT, PWM_GEN_1_BIT that we used
*/
void Wheels_ResetTimer(uint32_t ui32Gen);



void Wheels_GoForwardSpeed(uint8_t ui8Speed);

void Wheels_GoBackwardSpeed(uint8_t ui8Speed);

void Wheels_Rotate(Rotate_t Dir , uint8_t ui8Speed);

#endif


