#include "pwm.h"

void pwm_conf(timer_type_t timer, pwm_mode_t mode, psc_scale scale, pwm_polarity_t polarity)
{
    pwm_t pwm = pwm_get(timer);

    uint8_t prescaler = timer_psc(scale, timer);

    _assign_pattern(*(pwm.tmr.control_reg), pwm.tmr.psc_bit, psc_mask, prescaler);

    _assign_pattern(*(pwm.tmr.control_reg), pwm.mode_bit, pwm_mode_mask, mode);

    _assign_pattern(*(pwm.tmr.control_reg), pwm.polarity_bit, pwm_polarity_mask, polarity);
}

void pwm_init(timer_type_t timer)
{
    // timer_t tmr = timer_get(timer);
    pwm_t pwm = pwm_get(timer);
    pwm_conf(timer, PWM_DEFAULTS);
    dio_set_direction(pwm.pin, DIO_DIRECTION_OUTPUT);
}

void pwm_off(timer_type_t timer)
{
    pwm_t pwm = pwm_get(timer);

    _assign_pattern(*(pwm.tmr.control_reg), pwm.tmr.psc_bit, psc_mask, 0);

    _assign_pattern(*(pwm.tmr.control_reg), pwm.mode_bit, pwm_mode_mask, 0);

    _assign_pattern(*(pwm.tmr.control_reg), pwm.polarity_bit, pwm_polarity_mask, 0);
}

void ctc_init(timer_type_t timer, psc_scale scale, float period, pwm_polarity_t mode)
{
    pwm_t pwm = pwm_get(timer);
    // volatile uint8_t *tmr_register = (volatile uint8_t *)((timer==TMR1)? &TCCR1B : ((timer==TMR0)? &TCCR0 : &TCCR2));
    pwm_init(timer);
    pwm_conf(timer, ctc, scale, mode);
    *(uint8_t *)pwm.duty_reg = round((float)F_CPU / (float)scale * period);
}

void pwm_duty(timer_type_t timer, uint8_t duty)
{
    pwm_t pwm = pwm_get(timer);
    *(pwm.duty_reg) = round(duty * (float)pwm.tmr.max / 100.0);
}

pwm_t pwm_get(timer_type_t timer)
{
    switch (timer)
    {
    case TMR0:
    {
        const pwm_t pwm = {
            .tmr = timer_get(timer),
            .duty_reg = &OCR0,
            .polarity_bit = COM00,
            .mode_bit = WGM01,
            .pin = pwm_OC0};
        return pwm;
        break;
    }
    case TMR1:
    {
        //*
        const pwm_t pwm = {
            .tmr = timer_get(timer),
            .duty_reg = &OCR0,
            .polarity_bit = COM00,
            .mode_bit = WGM01,
            .pin = pwm_OC0};
        return pwm;
        //*/
        break;
    }
    case TMR2:
    {
        const pwm_t pwm = {
            .tmr = timer_get(timer),
            .duty_reg = &OCR2,
            .polarity_bit = COM20,
            .mode_bit = WGM21,
            .pin = pwm_OC2};
        return pwm;
        break;
    }
    default:
        break;
    }
}