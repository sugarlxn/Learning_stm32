#include "stm32f10x.h"
#include "GPIOLIKE51.h"
#include "led.h"
#include "key.h"
#include "blueteeth.h"
#include "stm32f10x_usart.h"
#include "delay.h"
#include "oled.h"
#include "ANO_DT.h"





int main(void)
{
	uint8_t flag=0;
	uint16_t data =0x11;
	int16_t data1=10,data2=10,data3=10,data4=10,data5=10,data6=10,data7=10,data8=10;
	int sum=0;
	
	DelayInit();
	led_init();
	key_init();
	blueteeth_init();
	OLED_Init();
	
	DelayMs(1000);
	OLED_CLS();
	OLED_ShowStr(0,1,"ok!",1);
	OLED_ShowStr(0,2,"data1:",1);
    while (1)
	{

		
		if(key_scan()){
			flag =~flag;
			//DelayMs(500);
			//Usart_SendString(USART1,"ok!today is a good day!/n/r");
			data1 += 10;
		}
		data2=data2+(data1-data2)*0.03 +(sum)*0.01;
		sum+=(data1-data2);
		if(sum >= 1000){sum=0;}
		//PCout(13)=flag%2;
		//USART_SendData(USART1,data);
		
		OLED_Showint(50,2,data1,1);
		ANO_DT_send_int16(USART1, data1, data2, data3, data4, data5, data6, data7, data8);
    }
	
}




