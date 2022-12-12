/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ����led
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� F103-ָ���� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
	
#include "stm32f10x.h"
#include "key.h"
#include "led.h"

#define SOFT_DELAY Delay(0x0FFFFF);

// void Delay(__IO u32 nCount); 

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
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


