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

// void Delay(__IO u32 nCount); 

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	

    Key_PGIO_Config();
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

// 		LED2_ON;			 // ��
// 		SOFT_DELAY;
// 		LED2_OFF;		   // ��

// 		LED3_ON;			 // ��
// 		SOFT_DELAY;
// 		LED3_OFF;		   // ��	 

// 		/*������ʾ ������������� ��ɫ*/
// 		LED_RED;
// 		SOFT_DELAY;
		
// 		LED_GREEN;
// 		SOFT_DELAY;
		
// 		LED_BLUE;
// 		SOFT_DELAY;
		
// 		LED_YELLOW;
// 		SOFT_DELAY;
		
// 		LED_PURPLE;
// 		SOFT_DELAY;
				
// 		LED_CYAN;
// 		SOFT_DELAY;
		
// 		LED_WHITE;
// 		SOFT_DELAY;
		
// 		LED_RGBOFF;
// 		SOFT_DELAY;		
// 	}
}

void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/
