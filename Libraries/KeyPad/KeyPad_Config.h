/*
 * KeyPad_Config.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

#define KEYPAD_R0_PIN            PC3_PIN
#define KEYPAD_R1_PIN            PC4_PIN
#define KEYPAD_R2_PIN            PC5_PIN
#define KEYPAD_R3_PIN            PC6_PIN

#define KEYPAD_C0_PIN            PB4_PIN
#define KEYPAD_C1_PIN            PB5_PIN
#define KEYPAD_C2_PIN            PB6_PIN
#define KEYPAD_C3_PIN            PB7_PIN
/*
 * KEYPAD_MODEL OPTIONS :   KEYPAD_MODEL_A :  { '7' , '8' , '9' , '+' }
			                  	  	  	  	  { '4' , '5' , '6' , '-' }
							  	  	  	  	  { '1' , '2' , '3' , '*' }
							  	  	  	  	  { 'C' , '0' , '=' , '/' }

                            KEYPAD_MODEL_B :  { '7' , '8' , '9' , '+' }
			                  	  	  	  	  { '4' , '5' , '6' , '-' }
							  	  	  	  	  { '1' , '2' , '3' , '*' }
							  	  	  	  	  { 'C' , '0' , '=' , '/' }
 */
#define KEYPAD_MODEL             KEYPAD_MODEL_A

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
