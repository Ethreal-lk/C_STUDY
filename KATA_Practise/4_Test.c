/*
 * @Author: your name
 * @Date: 2021-07-07 12:22:04
 * @LastEditTime: 2021-07-09 15:31:35
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C\.vscode\KATA_Practise\4_Test.c
 */
#include <stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int main () {
    int x = 121;
    int rawvalue = x;
    int temp =0;
    if (x < 0)
    {
      return  0;

    } else {
      while (x > 0)
      {
        temp = temp * 10  + x % 10 ;
        x /= 10 ;
      }     
    }
     if (rawvalue == temp)
      {
        printf("sucess");
      } 
       return 0;
  
}
/**
 * @description: 返回数组中相加等于目标值的下标
 *                注意要使用动态分配内存存放数据
 * @param {int*} nums
 * @param {int} numsSize
 * @param {int} target
 * @param {int*} returnSize
 * @return {*}
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

  int * ptr = returnSize;
  for (int i = 0; i < numsSize-1 ; i++ ) { 
    for (int j = i + 1; j < numsSize ; j++) {
      if (nums[i] + nums[j] == target)
      {
        *ptr = i;
        ptr ++;
        *ptr = j;
      }
      
    }
  }
  return returnSize;

}
/**
 * @description: 
 * @param {*}
 * @return {*}
 */
//复杂方法
int digital_root(int n) {
  
  if (n < 10)  return n ;
  int sum = 0 ;
  while (n > 0)
  {
    sum += n % 10 ;
    n /= 10; 
  }
  return digital_root(sum);
  
}
/*
简单方法
比如num=1000*a+100*b+10*c+d；
可以写成num=999*a+99*b+9*c+(a+b+c+d)；
如果(a+b+c+d) > 10, 重复上述步骤。
*/
int digital_root(int n) {
  return (n-1)%9 + 1;
}