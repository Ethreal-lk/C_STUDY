/*
 * @Author: your name
 * @Date: 2021-07-09 09:05:42
 * @LastEditTime: 2021-07-09 09:41:54
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C\.vscode\C_CLASSES\KATA_Practise\4_Multiplesof3or5.c
 */

/**
 * @description: If we list all the natural numbers below 10 that are multiples of 3 or 5
 *               , we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * @param {*}
 * @return {*}
 */

#include <stdio.h>
#include <stdlib.h>


int solution(int number);
int main() { 
    int temp = solution(10);
    printf("%d ",temp);
}
// 计算小于给出数字能被3或者5整除的数之和;
int solution(int number) {
		
    int sum = 0 ;
    if (number < 0 )
    {
      return 0 ;
    } else {

    for (int i = 3; i < number; i ++  ) {
      
      if (i % 3 == 0 || i % 5 == 0)
      {
        sum += i;
      }   
    }
    return sum ; 
  }
}