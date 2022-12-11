/*
 * @Author: your name
 * @Date: 2021-12-14 22:32:31
 * @LastEditTime: 2022-04-23 11:20:42
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \STM32_one\main.c
 */
#include "stm32f10x.h"
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

int main(void)
{	
	// 开启GPIOB 端口时钟
	RCC_APB2ENR |= (1<<3);

	//清空控制PB1/PB0/PB5的端口位
	GPIOB->CRL &= ~( 0x0F<< (4*1) | (0x0F<< (4*0)) |(0x0F<< (4*5)));	
	// 配置PB1/PB0/PB5为通用推挽输出，速度为10M
	GPIOB->CRL |= ((1<<4*5) | (1<<4*0) | (1<<4*1));
	while (1)
	{
		// GPIO_SetBits(GPIOB,GPIO_Pin_5);
    // GPIO_ResetBits(GPIOB,GPIO_Pin_0);
    GPIO_SetBits(GPIOB,GPIO_Pin_1 | GPIO_Pin_0 | GPIO_Pin_5);
    delay_ms(DELAY_TIME_MS);
		GPIO_ResetBits(GPIOB,GPIO_Pin_1);
		delay_ms(DELAY_TIME_MS);
    GPIO_SetBits(GPIOB,GPIO_Pin_1 | GPIO_Pin_0 | GPIO_Pin_5);
    delay_ms(DELAY_TIME_MS);
		GPIO_ResetBits(GPIOB,GPIO_Pin_0);
		delay_ms(DELAY_TIME_MS);
    GPIO_SetBits(GPIOB,GPIO_Pin_1 | GPIO_Pin_0 | GPIO_Pin_5);
    delay_ms(DELAY_TIME_MS);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5);
		delay_ms(DELAY_TIME_MS);
    GPIO_SetBits(GPIOB,GPIO_Pin_1 | GPIO_Pin_0 | GPIO_Pin_5);
    delay_ms(DELAY_TIME_MS);
    GPIO_ResetBits(GPIOB,GPIO_Pin_1 | GPIO_Pin_0);
    delay_ms(DELAY_TIME_MS);
    GPIO_SetBits(GPIOB,GPIO_Pin_1 | GPIO_Pin_0 | GPIO_Pin_5);
    delay_ms(DELAY_TIME_MS);
    GPIO_ResetBits(GPIOB,GPIO_Pin_1 | GPIO_Pin_5);
    delay_ms(DELAY_TIME_MS);
    GPIO_SetBits(GPIOB,GPIO_Pin_1 | GPIO_Pin_0 | GPIO_Pin_5);
    delay_ms(DELAY_TIME_MS);
    GPIO_ResetBits(GPIOB,GPIO_Pin_0 | GPIO_Pin_5);
    delay_ms(DELAY_TIME_MS);
    GPIO_SetBits(GPIOB,GPIO_Pin_1 | GPIO_Pin_0 | GPIO_Pin_5);
    delay_ms(DELAY_TIME_MS);
    GPIO_ResetBits(GPIOB,GPIO_Pin_1 | GPIO_Pin_0 | GPIO_Pin_5);
    delay_ms(DELAY_TIME_MS);
    GPIO_SetBits(GPIOB,GPIO_Pin_1 | GPIO_Pin_0 | GPIO_Pin_5);

	}
}



// 函数为空，目的是为了骗过编译器不报错
void SystemInit(void)
{	
}
