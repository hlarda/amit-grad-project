#ifndef _PWM_H
#define _PWM_H


#include <stdint.h>
#include <math.h>


#include "dio.h"
#include "timer.h"


// TODO implement timer 1 too
typedef enum pwm_mode_t
{
    ctc = 0b0001,
    pwm_correct = 0b1000,
    pwm_fast = 0b1001,
    pwm_mode_mask = 0b1001
} pwm_mode_t;

typedef enum pwm_polarity_t
{
    pwm_normal = 0b10,
    pwm_inverted = 0b11,
    pwm_polarity_mask = 0b11
} pwm_polarity_t;

typedef enum ctc_operation_t
{
    ctc_none = 0b00,
    ctc_toggle = 0b01,
    ctc_clear = 0b10,
    ctc_set = 0b11
} ctc_operation_t;

typedef enum pwm_pin_t
{
    pwm_OC0 = DIO_PB3,
    pwm_OC2 = DIO_PD7
} pwm_pin_t;

typedef struct pwm_t
{
    timer_t tmr;
    volatile uint8_t *duty_reg;
    uint8_t polarity_bit;
    uint8_t mode_bit;
    pwm_pin_t pin;
} pwm_t;

#define _PWM_SPEED(x)  ( ((x) == pwm_fast)   ? 256 \
                       : ((x) == pwm_normal) ? 510 \
                                             : 510 )

#define PWM_DEFAULTS pwm_correct, \
                     8,           \
                     pwm_normal
/*
 * defaults are correct non-inverted PWM with 8 prescaler
 * i.e. frequency = F_CPU / (8*510); 392Hz for 16MHz crystal
 *                                   196Hz for 8Mhz  crystal
 */

void pwm_init(timer_type_t timer);
void pwm_off(timer_type_t timer);
void pwm_conf(timer_type_t timer, pwm_mode_t mode, psc_scale scale, pwm_polarity_t polarity);
void ctc_init(timer_type_t timer, psc_scale scale, float period, pwm_polarity_t mode);
void pwm_duty(timer_type_t timer, uint8_t duty);
pwm_t pwm_get(timer_type_t timer);

#endif