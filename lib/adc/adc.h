#ifndef _ADC_H
#define _ADC_H

#include <avr/io.h>

#include <stdint.h>

#include "dio.h"
#include "psc.h"

typedef enum {
    ADC_AREF = 0,
    ADC_AVCC = 1,
    ADC_INTR = 3
} adc_ref_t;

typedef enum {
    ADC_RIGHT = 0,
    ADC_LEFT = 1
} adc_alignment_t;

// void adc_init(psc_scale scale, adc_ref_t reference, adc_alignment_t alignment);
void adc_init(adc_ref_t reference, psc_scale scale);
uint16_t adc_read(uint8_t ch);
void adc_off();

#endif