/*
 * @Author: your name
 * @Date: 2021-07-13 15:45:02
 * @LastEditTime: 2021-07-13 16:08:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C\.vscode\C_CLASSES\KATA_Practise\array.c
 */
#include <stdio.h>
#include <stdlib.h>
#include  <string.h>


int main() {

  int a[3][4] = {
                {1,2,3,4,}, 
                {5,6,7,8},
                {9,10,11,12}
  };

  int  a2[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12};
  int  a3[][4] = { 1,2,3,4,5,6,7,8,9,10,11,12};
 int i , j ;
 for (i = 0 ; i< 3 ; i++) {
   for(j = 0; j < 4; j++) {
     printf("%d ", a3[i][j]);
   }
   printf("\n");
 } 
 printf ("\n");

  printf("a: %d, a+1: %d \n", a3, a3 + 1);
  printf("%d , %d\n", *(a3 + 0), *(a3 + 0) + 1);
  printf(" %d  %d ", a3[0], a3[0 + 1]);
  //a : 代表第0行的首地址
  //a + i : 代表的第i行首地址
  // *（0 + i）第i行元素首地址
  //*（a + i）+j —— >&a[i][j]：第i行第j列元素的地址；
  //*(*(a + i) + j )- > 第i行第j列元素的值
}