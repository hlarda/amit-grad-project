#include <stdint.h>

#define reg(address) _Generic((address),            \
                              volatile uint8_t *    \
                              : reg_create8,        \
                                volatile uint16_t * \
                              : reg_create16,       \
                                volatile uint32_t * \
                              : reg_create32)((void *)address)

typedef union address_t {
    volatile uint8_t *r8;
    volatile uint16_t *r16;
    volatile uint32_t *r32;
} address_t;

typedef struct reg_t {
    address_t address;
    uint8_t width;
} reg_t;

typedef reg_t *regptr_t;

reg_t reg_create8(void *address);
reg_t reg_create16(void *address);
reg_t reg_create32(void *address);

void reg_assign(reg_t reg, uint32_t value);
uint32_t reg_read(reg_t reg);
uint8_t reg_width(reg_t reg);
void *reg_unwrap(reg_t reg);