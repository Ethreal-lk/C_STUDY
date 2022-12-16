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
// void Delay(__IO u32 nCount); 
/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
 //BUG 
int main(void)
{	  
    uint8_t status = Bit_RESET;

		LED_GPIO_Config();
    Key_PGIO_Config();

    while (1)
    { 
      //test  测试按键
      status = GPIO_ReadInputDataBit(KEY1_GPIO_PORT, KEY1_GPIO_PIN);
      if (status == Bit_RESET)
      {
        GPIO_SetBits(LED_GPIO_PORT,LED_RED | LED_BLUE | LED_GREEN);
      } else {
        GPIO_ResetBits(LED_GPIO_PORT,LED_RED);
      }
      status = GPIO_ReadInputDataBit(KEY2_GPIO_PORT, KEY2_GPIO_PIN);
      if (status == Bit_RESET)
      {
        GPIO_SetBits(LED_GPIO_PORT,LED_RED | LED_BLUE | LED_GREEN);
      } else {
        GPIO_ResetBits(LED_GPIO_PORT,LED_BLUE);
      }
    }

//todo
//done
//mark
}


