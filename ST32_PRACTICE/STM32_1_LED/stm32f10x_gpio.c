/*
 * @Author: your name
 * @Date: 2022-04-23 10:49:01
 * @LastEditTime: 2022-04-23 11:20:48
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \STM32_one\stm32f10x_gpio.c
 */
#include "stm32f10x_gpio.h"
void GPIO_SetBits(GPIO_TypeDef *GPIOX, uint16_t GPIO_Pin) {
    GPIOX->BSRR |= GPIO_Pin;
}

void GPIO_ResetBits(GPIO_TypeDef *GPIOX, uint16_t GPIO_Pin) {
    GPIOX->BRR  |= GPIO_Pin;
}
