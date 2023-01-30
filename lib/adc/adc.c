#include "adc.h"

void adc_init(adc_ref_t reference, psc_scale scale) {
    adc_alignment_t alignment = ADC_RIGHT;  // hardcoded default

    uint8_t prescaler = psc_select(scale, PSCA);
    ADMUX = 0;
    ADMUX |= prescaler | (reference << REFS0) | (alignment << ADLAR);

    ADCSRA = (1 << ADEN) | prescaler;  // enable ADC and set the prescaler
    //// clk/2, clk/4, clk/8, clk/16, clk/32, clk/64, clk/128 [1:7]
}

uint16_t adc_read(uint8_t ch) {
    // select the corresponding channel [0:7]
    ADMUX &= ~0b111;        // clear the bottom 3 bits before ORing
    ADMUX |= (ch & 0b111);  // foolproof channel number

    // start single conversion
    // write '1' to ADSC
    ADCSRA |= (1 << ADSC);

    // wait for conversion to complete
    // ADSC becomes ’0′ again
    // till then, infinite loop
    while ((ADCSRA >> ADSC) & 1)
        ;

    return (ADC);
}

void adc_alignment(adc_alignment_t alignment) {
    ADMUX |= (alignment << ADLAR);
}

void adc_off() {
    ADCSRA &= ~(1 << ADEN);
}
