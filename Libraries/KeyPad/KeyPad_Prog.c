/*
 * KeyPad_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "KeyPad_Interface.h"
#include "KeyPad_Private.h"

void H_KeyPad_Void_KeyPadInit(void)
{
	M_DIO_Void_SetPinDirection(KEYPAD_R0_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_R1_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_R2_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_R3_PIN,OUTPUT);

	M_DIO_Void_SetPinValue(KEYPAD_R0_PIN,HIGH);
	M_DIO_Void_SetPinValue(KEYPAD_R1_PIN,HIGH);
	M_DIO_Void_SetPinValue(KEYPAD_R2_PIN,HIGH);
	M_DIO_Void_SetPinValue(KEYPAD_R3_PIN,HIGH);

	M_DIO_Void_SetPinDirection(KEYPAD_C0_PIN,INPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_C1_PIN,INPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_C2_PIN,INPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_C3_PIN,INPUT);

	M_DIO_Void_SetPinPullUpRes(KEYPAD_C0_PIN,ENABLE);
	M_DIO_Void_SetPinPullUpRes(KEYPAD_C1_PIN,ENABLE);
	M_DIO_Void_SetPinPullUpRes(KEYPAD_C2_PIN,ENABLE);
	M_DIO_Void_SetPinPullUpRes(KEYPAD_C3_PIN,ENABLE);
}

u8   H_KeyPad_U8_KeyPadRead(void)
{
#if   KEYPAD_MODEL   ==   KEYPAD_MODEL_A
	u8 Local_U8_Arr [4][4] = {{ '1' , '2' , '3' , 'A' },
			                  { '4' , '5' , '6' , 'B' },
							  { '7' , '8' , '9' , 'C' },
							  { '*' , '0' , '#' , 'D' }};
#elif KEYPAD_MODEL   ==   KEYPAD_MODEL_B
	u8 Local_U8_Arr [4][4] = {{ '7' , '8' , '9' , '+' },
			                  { '4' , '5' , '6' , '-' },
							  { '1' , '2' , '3' , '*' },
							  { 'C' , '0' , '=' , '/' }};
#endif
	u8 Local_U8_Reading = 1;
	u8 Local_U8_Col     = 0;
	u8 Local_U8_Row     = 0;
	for(Local_U8_Row=KEYPAD_R0_PIN ; Local_U8_Row <= KEYPAD_R3_PIN ; Local_U8_Row++)
	{
		M_DIO_Void_SetPinValue(Local_U8_Row,LOW);
		for(Local_U8_Col=KEYPAD_C0_PIN ; Local_U8_Col <= KEYPAD_C3_PIN ; Local_U8_Col++)
		{
			if(M_DIO_Void_GetPinValue(Local_U8_Col) == KEYPAD_PRESSED)
			{
				_delay_ms(120);
				if(M_DIO_Void_GetPinValue(Local_U8_Col) == KEYPAD_PRESSED)
				{
					while(M_DIO_Void_GetPinValue(Local_U8_Col) == KEYPAD_PRESSED);
					Local_U8_Reading = Local_U8_Arr[Local_U8_Row - KEYPAD_R0_PIN][Local_U8_Col - KEYPAD_C0_PIN];
					break;
				}

			}
		}
		M_DIO_Void_SetPinValue(Local_U8_Row,HIGH);
	}
return Local_U8_Reading;
}






















