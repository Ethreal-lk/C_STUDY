/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   测试led
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-指南者 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
	
#include "stm32f10x.h"
#include "key.h"
#include "led.h"

#define SOFT_DELAY Delay(0x0FFFFF);

// void Delay(__IO u32 nCount); 

/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{	
		LED_GPIO_Config();
    Key_PGIO_Config();

    while (1)
    {
      GPIO_SetBits(LED_GPIO_PORT,LED_RED | LED_BLUE | LED_GREEN);
      delay_ms(50);
      GPIO_ResetBits(LED_GPIO_PORT,LED_RED);
      delay_ms(200);
			GPIO_SetBits(LED_GPIO_PORT,LED_RED | LED_BLUE | LED_GREEN);
      delay_ms(50);
      GPIO_ResetBits(LED_GPIO_PORT,LED_BLUE);
      delay_ms(200);
			GPIO_SetBits(LED_GPIO_PORT,LED_RED | LED_BLUE | LED_GREEN);
      delay_ms(50);
      GPIO_ResetBits(LED_GPIO_PORT,LED_GREEN);
      delay_ms(200);
    }

}


