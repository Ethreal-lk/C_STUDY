/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ����led
  ******************************************************************************
  * @attention

	
#include "stm32f10x.h"
#include "key.h"
#include "led.h"
// void Delay(__IO u32 nCount); 
/**
  * @brief  
  * @param    
  * @retval 
  */
 //BUG 
int main(void)
{	  
    uint8_t status = Bit_RESET;

		LED_GPIO_Config();
    Key_PGIO_Config();

    while (1)
    { 
      //test  
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
}


