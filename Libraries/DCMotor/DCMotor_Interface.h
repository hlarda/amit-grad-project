/*
 * DCMotor_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_DCMOTOR_DCMOTOR_INTERFACE_H_
#define HAL_DCMOTOR_DCMOTOR_INTERFACE_H_

#include "STD.h"

#define CW                0
#define ACW               1


void H_DCMotor_Void_DCMotorInit(void);
void H_DCMotor_Void_DCMotorSetDirection(u8);
void H_DCMotor_Void_DCMotorSetSpeed(u8);
void H_DCMotor_Void_DCMotorStart(void);
void H_DCMotor_Void_DCMotorStop(void);

#endif /* HAL_DCMOTOR_DCMOTOR_INTERFACE_H_ */
