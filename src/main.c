#include"STD.h"
#include"DIO_Interface.h"
#include"GIE_Interface.h"
#include"Timer_Interface.h"
#include"AT24C16A_Interface.h"
#include"LCD_Interface.h"
#include"LM35_Interface.h"
#include"PB_Interface.h"
#include"DIO_Interface.h"
#include"LED_Interface.h"
#include"ExtInt_Interface.h"

u8 volatile temp;
u8 max_temp=75 , min_temp=35 ;
u8 req_temp;
u8 stability_flag = 0 , up_flag=0, down_flag=0 ;

void update_temp(void);
void up_pressed(void);
void down_pressed(void);

int main ()
{
    M_Timer_Void_TimerInit();
    M_Timer_Void_TimerSetTime(100);
    M_Timer_Void_SetCallBack(update_temp);

    H_Lcd_Void_LCDInit();
    H_LM35_Void_LM35Init();
    H_AT24C16A_Void_EEPROMInit();

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

    req_temp = H_AT24C16A_Void_EEPROMRead(0x00,0x00);
    M_GIE_Void_GlobalInterruptEnable();
    M_Timer_Void_TimerStart(TIMER0_CHANNEL);
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

        for(int i =0 ; (temp == req_temp && i<10) ; i++)
        {
            if (i==9)
            {
                M_DIO_Void_SetPinValue(PD4_PIN,LOW);
                M_DIO_Void_SetPinValue(PD5_PIN,LOW);
                H_AT24C16A_Void_EEPROMWrite(0x00,0x00,60);
            }
            
        }
    }
}
/**********************************************************************/
void up_pressed(void)
{
    if(up_flag == 0 )               //heating_mode
    {
        M_DIO_Void_SetPinValue(PD4_PIN,HIGH);  
        M_DIO_Void_SetPinValue(PD5_PIN,LOW);  

        H_LED_Void_LedOn(LED0);
        H_LED_Void_LedOff(LED1);
        up_flag   = 1;
        down_flag = 0;
    }
    else if(req_temp <= max_temp-5)
    {
        req_temp+=5;
        H_AT24C16A_Void_EEPROMWrite(0x00,0x00,req_temp);
    }
}
/**********************************************************************/
void down_pressed()
{
    if(down_flag == 0)              //cooling_mode
    {
        M_DIO_Void_SetPinValue(PD5_PIN,HIGH);
        M_DIO_Void_SetPinValue(PD4_PIN,LOW);  
        H_LED_Void_LedOn(LED1);
        H_LED_Void_LedOff(LED0);
        down_flag = 1 ;
        up_flag   = 0 ;
    }
    else if(req_temp >= min_temp+5)
    {
        req_temp-=5;
        H_AT24C16A_Void_EEPROMWrite(0x00,0x00,req_temp);
    }
}
/**********************************************************************/
void update_temp(void)
{   
    temp = H_LM35_U16_LM35Read();
    
}


//#define Q_LENGTH 10
//    u8 temp_queue[Q_LENGTH], last=-1, first=-1;
//  
//    /*empty*/    if (last == -1 && first == -1)
//                    { last = 0; first = 0;  temp_queue[last] = temp;}
//    /*full*/else if (last == Q_LENGTH-1)               
//                    {for (u8 i = 0; i < Q_LENGTH-1 ; i++){temp_queue[i]=temp_queue[i+1];}    last--;temp_queue[Q_LENGTH-1] = temp;}
//                else{ last++;  temp_queue[last] = temp;}
