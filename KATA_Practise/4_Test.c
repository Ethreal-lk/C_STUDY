/*
 * @Author: your name
 * @Date: 2021-07-07 12:22:04
 * @LastEditTime: 2021-07-08 09:42:12
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