/*
 * @Author: your name
 * @Date: 2021-07-09 09:05:42
 * @LastEditTime: 2021-07-09 11:21:51
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
/**
 * @description:计算达到人口的年限 
 * @param {int} p0
 * @param {double} percent
 * @param {int} aug
 * @param {int} p
 * @return {*}
 */
int nbYear(int p0, double percent, int aug, int p) {
    
  int number = 0;
  while (p0 < p) { 
    p0 = p0 * (1 + percent / 100) + aug;
    number++;
  }
  return number;
  //return number < 0 ? number : number<  13 ?  number - 1 : number -2;   三目运算符

  }