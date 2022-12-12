#include "led.h"
void LED_GPIO_Config(void) {
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(LED_GPIO_CLK,ENABLE);
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_InitStructure.GPIO_Pin = LED_BLUE | LED_GREEN | LED_RED;
  GPIO_Init(LED_GPIO_PORT, &GPIO_InitStructure);
}
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
