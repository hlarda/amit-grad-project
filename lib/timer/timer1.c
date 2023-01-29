#include "timer1.h"

void timer1_init(WGM12_v correctness, timer1_pwm_value pwm_reg, psc_scale scale, float period)
{
    uint8_t prescaler = timer_psc(TMR1, scale);
    _assign_pattern(TCCR1B, CS10, 0b111, prescaler);
    if ((correctness == frequency_correct) && ((pwm_reg >> 2) != assigned))
        return; // mutually exclusive conditions

    _assign_bit(TCCR1B, WGM12, correctness & 1);
    _assign_bit(TCCR1B, WGM13, pwm_reg >> 2);
    _assign_pattern(TCCR1A, WGM10, 0b11, pwm_reg);
    if (pwm_reg >> 2 == assigned)
    {
        _assign_bit(TCCR1A, WGM11, correctness >> 1);

        switch (pwm_reg)
        {
        case reg_OCR1A:
            OCR1A = round((float)F_CPU / (float)scale * period);
            break;
        case reg_ICR1:
            ICR1 = round((float)F_CPU / (float)scale * period);
            break;

        default:
            break;
        }
    }
}

void timer1_ctc_mode(timer1_output pin, ctc_operation_t operation)
{
    _assign_pattern(TCCR1A, pin, 0b11, operation);
}