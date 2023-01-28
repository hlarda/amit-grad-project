/*
 * PB_Config.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_PB_PB_CONFIG_H_
#define HAL_PB_PB_CONFIG_H_

#define PUSH_BUTTON_0_PIN            PB0_PIN
#define PUSH_BUTTON_1_PIN            PD6_PIN
#define PUSH_BUTTON_2_PIN            PD2_PIN
/*
 * SELECT PB_MODE OPTIONS : ACTIVE_HIGH , ACTIVE_LOW
 */
#define PB_MODE                      ACTIVE_HIGH
/*
 * SELECT PB_DEBOUNCING_TIME IN MILLI SECOND
 */
#define PB_DEBOUNCING_TIME           120

#endif /* HAL_PB_PB_CONFIG_H_ */
