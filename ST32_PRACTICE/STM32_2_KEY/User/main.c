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
<<<<<<< HEAD
#include "key.h"
#include "led.h"
=======
#include "stm32f10x_gpio.h"

#define DELAY_TIME_MS 50
void delay_us(uint32_t delay_us)
{
  volatile unsigned int num;
  volatile unsigned int t;


  for (num = 0; num < delay_us; num++)
  {
    t = 11;
    while (t != 0)
    {
      t--;
    }
  }
}

void delay_ms(uint16_t delay_ms)
{
  volatile unsigned int num;
  for (num = 0; num < delay_ms; num++)
  {
    delay_us(1000);
  }
}

//#include "bsp_led.h"

#define SOFT_DELAY Delay(0x0FFFFF);

>>>>>>> parent of 13adbf3 (添加Gpio初始函数)
// void Delay(__IO u32 nCount); 
/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
 //BUG 
int main(void)
{	  
    uint8_t status = Bit_RESET;

<<<<<<< HEAD
		LED_GPIO_Config();
    Key_PGIO_Config();
=======

    for (uint16_t i = 0; i < 0xff; i++ )
    {
      // printf ("hello world !");
    }
// //	/* LED �˿ڳ�ʼ�� */
// 	LED_GPIO_Config();	 

// 	while (1)
// 	{
// 		LED1_ON;			  // ��
// 		SOFT_DELAY;
// 		LED1_OFF;		   // ��
>>>>>>> parent of 13adbf3 (添加Gpio初始函数)

    while (1)
    { 
      //test  ���԰���
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


