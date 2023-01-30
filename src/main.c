#include"STD.h"
#include"DIO_Interface.h"
#include"GIE_Interface.h"
#include "timer.h"
#include"AT24C16A_Interface.h"
#include"LCD_Interface.h"
#include"PB_Interface.h"
#include"DIO_Interface.h"
#include"LED_Interface.h"
#include"ExtInt_Interface.h"
#include"adc.h"

u8 volatile temp=60;
u8 max_temp=75 , min_temp=35 ;
u8 volatile req_temp=60;
u8 static up_flag=0, down_flag=0 ;

void update_temp(void);
void up_pressed(void);
void down_pressed(void);
void heating_mode_ON(void);
void cooling_mode_ON(void);
void heating_mode_OFF(void);
void cooling_mode_OFF(void);

int main ()
{
    H_Lcd_Void_LCDInit();
    H_AT24C16A_Void_EEPROMInit();
    adc_init(ADC_AVCC, PSC_128);

    H_PB_Void_PBInit(PB0);                          //up_btn            /*int0 min el kit*/
    H_PB_Void_PBInit(PB1);                          //down_btn          /*change in config into PD3_PIN (LED fel kit) */
    H_LED_Void_LedInit(LED0);                       //red_led
    H_LED_Void_LedInit(LED1);                       //blue_led

    M_ExtInt_Void_ExtIntInit(INT0_CHANNEL);
    M_ExtInt_Void_ExtIntInit(INT1_CHANNEL);
    M_ExtInt_Void_SetCallBack(INT0_CHANNEL,up_pressed);
    M_ExtInt_Void_SetCallBack(INT1_CHANNEL,down_pressed);

    M_DIO_Void_SetPinDirection(PD4_PIN,OUTPUT);     //heater_pin
    M_DIO_Void_SetPinDirection(PD5_PIN,OUTPUT);     //cooler_pin

    //req_temp = H_AT24C16A_Void_EEPROMRead(0x00,0x00);
    M_GIE_Void_GlobalInterruptEnable();
    timer_init(TMR1, PSC_64, 0.1 , TMR_INT);
    H_Lcd_Void_LCDGoTo(0,0);
    H_Lcd_Void_LCDWriteString("temp NOW: ");
    H_Lcd_Void_LCDGoTo(1,0);
    H_Lcd_Void_LCDWriteString("desired: ");

    while (1)
    {
        H_Lcd_Void_LCDGoTo(0,12);
        H_Lcd_Void_LCDWriteNumber(temp);
        H_Lcd_Void_LCDGoTo(1,12);
        H_Lcd_Void_LCDWriteNumber(req_temp);
    }
}
/**********************************************************************/
timer_isr(TMR1) {
    update_temp();
}
/**********************************************************************/
void update_temp(void)
{   
    temp = (adc_read(1)*4.88)/10;

    for(int i =0 ; (temp == req_temp && i<10) ; i++)
        {
            if (i==9)
            {
                heating_mode_OFF();
                cooling_mode_OFF();
            }
        }
    for(int i =0 ; (((req_temp - temp)>= 5 ) && i<10) ; i++)
        {
            if (i==9)
            {
                heating_mode_ON();
                cooling_mode_OFF();
            }
        }
    for(int i =0 ; (((temp - req_temp)>= 5 ) && i<10) ; i++)
    {
        if (i==9)
        {
            heating_mode_OFF();
            cooling_mode_ON();
        }
    }
}
/**********************************************************************/
void up_pressed(void)
{
    if(up_flag == 0 )              
    {
        heating_mode_ON();
        up_flag   = 1;
        down_flag = 0;
    }
    else if((req_temp <= max_temp-5) || temp == req_temp)
    {
        req_temp+=5;
        H_AT24C16A_Void_EEPROMWrite(0x00,0x00,req_temp);
        up_flag   = 0;
    }
}
/**********************************************************************/
void down_pressed(void)
{
    if(down_flag == 0)              
    {
        cooling_mode_ON();
        down_flag = 1;
        up_flag   = 0; 
    }
    else if((req_temp >= min_temp+5) || temp == req_temp)
    {
        req_temp-=5;
        H_AT24C16A_Void_EEPROMWrite(0x00,0x00,req_temp);
        down_flag = 0;
    }
}
/**********************************************************************/
void heating_mode_ON(void)
{
    M_DIO_Void_SetPinValue(PD4_PIN,HIGH);  
    M_DIO_Void_SetPinValue(PD5_PIN,LOW);  
    H_LED_Void_LedOn(LED0);
    H_LED_Void_LedOff(LED1);
}
/**********************************************************************/
void cooling_mode_ON(void)
{
    M_DIO_Void_SetPinValue(PD5_PIN,HIGH);
    M_DIO_Void_SetPinValue(PD4_PIN,LOW);  
    H_LED_Void_LedOn(LED1);
    H_LED_Void_LedOff(LED0);
}
/**********************************************************************/
void heating_mode_OFF(void)
{
    M_DIO_Void_SetPinValue(PD4_PIN,LOW);
    H_LED_Void_LedOff(LED0);
}
/**********************************************************************/
void cooling_mode_OFF(void)
{
    M_DIO_Void_SetPinValue(PD5_PIN,LOW);
    H_LED_Void_LedOff(LED1);
}