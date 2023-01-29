#include "reg.h"

#define NULL ((void *)0)
#define __finline inline __attribute__((always_inline))

reg_t reg_create(uint8_t width, void *address);
void *reg_unwrap(reg_t reg);

__finline reg_t reg_create8(void *address) {
    return reg_create(8, address);
}

__finline reg_t reg_create16(void *address) {
    return reg_create(16, address);
}

__finline reg_t reg_create32(void *address) {
    return reg_create(32, address);
}

__finline uint8_t reg_width(reg_t reg) {
    return reg.width;
}

reg_t reg_create(uint8_t width, void *address) {
    reg_t reg = {0};
    switch (width) {
        case 8:
            reg = (reg_t){
                .address = (address_t){.r8 = (uint8_t *)address},
                .width = 8};
            break;
        case 16:
            reg = (reg_t){
                .address = (address_t){.r16 = (uint16_t *)address},
                .width = 16};
            break;
        case 32:
            reg = (reg_t){
                .address = (address_t){.r32 = (uint32_t *)address},
                .width = 32};
            break;
    }
    return reg;
}

void reg_assign(reg_t reg, uint32_t value) {
    switch (reg.width) {
        case 8:
            *reg.address.r8 = (uint8_t)value;
            break;
        case 16:
            *reg.address.r16 = (uint16_t)value;
            break;
        case 32:
            *reg.address.r32 = (uint32_t)value;
            break;
    }
}

uint32_t reg_read(reg_t reg) {
    uint32_t value = 0;
    switch (reg.width) {
        case 8:
            value = *reg.address.r8;
            break;
        case 16:
            value = *reg.address.r16;
            break;
        case 32:
            value = *reg.address.r32;
            break;
    }
    return value;
}

void *reg_unwrap(reg_t reg) {
    void *reg_ptr = NULL;
    switch (reg.width) {
        case 8:
            reg_ptr = (void *)reg.address.r8;
            break;
        case 16:
            reg_ptr = (void *)reg.address.r16;
            break;
        case 32:
            reg_ptr = (void *)reg.address.r32;
            break;
    }
    return reg_ptr;
}
