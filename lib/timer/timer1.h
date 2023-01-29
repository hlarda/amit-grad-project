#ifndef _TIMER1_H
#define _TIMER1_H


#include <avr/interrupt.h>
#include "macros.h"
#include "timer.h"
#include "pwm.h"

// WGM13 -> assign value bit
// WGM12 -> fast pwm
// if(WGM13) :  WGM10 -> select OCR1A or else ICR1A
//              WGM11 -> not frequency correct
//                       i.e. update on BOTTOM
// if(!WGM13):  WGM11|WGM10 -> width

typedef enum WGM12_v
{
    phase_correct,
    fast,
    frequency_correct
} WGM12_v;

typedef enum WGM13_v
{
    tmr1_max,
    assigned
} WGM13_v;

typedef enum timer1_pwm_value
{
    max_8bit = (tmr1_max << 2) | 0b01,
    max_9bit = (tmr1_max << 2) | 0b10,
    max_10bit = (tmr1_max << 2) | 0b11,
    reg_OCR1A = (assigned << 2) | 0b01, // (!assigned << 3)0b01,
    reg_ICR1 = (assigned << 2) | 0b00   //(!assigned << 3)0b00
} timer1_pwm_value;

typedef enum timer1_output
{
    pin_OC1A = COM1A0,
    pin_OC1B = COM1B0
} timer1_output;

void timer1_init(WGM12_v correctness, timer1_pwm_value pwm_reg, psc_scale scale, float period);
void timer1_ctc_mode(timer1_output pin, ctc_operation_t operation);

#endif
