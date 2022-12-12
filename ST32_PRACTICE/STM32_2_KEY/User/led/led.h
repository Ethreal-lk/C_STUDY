#ifndef _BSP_LED_
#define _BSP_LED_
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

//  引脚定义
#define    LED_GPIO_CLK     RCC_APB2Periph_GPIOB
#define    LED_GPIO_PORT    GPIOB			   
#define    LED_GREEN		 		GPIO_Pin_0
#define    LED_BLUE		 			GPIO_Pin_1
#define    LED_RED		 			GPIO_Pin_5


 /** 按键按下标置宏
	*  按键按下为高电平，设置 KEY_ON=1， KEY_OFF=0
	*  若按键按下为低电平，把宏设置成KEY_ON=0 ，KEY_OFF=1 即可
	*/

void LED_GPIO_Config(void);
void delay_ms(uint16_t delay_ms);
void delay_us(uint32_t delay_us);
// uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);
#endif
