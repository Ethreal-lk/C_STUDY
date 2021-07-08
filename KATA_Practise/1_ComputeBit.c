/*
 * @Author: your name
 * @Date: 2021-07-06 16:04:42
 * @LastEditTime: 2021-07-06 16:18:59
 * @LastEditors: Please set LastEditors
 * @Description:计算给出的数字二进制中1的个数
 * @FilePath: \C\.vscode\KATA_Practise\1_ComputeBit.c
 */
 
 #include <stdio.h>


 unsigned int CountBits(unsigned int  value);

 unsigned int CountBits1(unsigned int  value);

 int main ()
 {
    unsigned int Testdata = 8;
    unsigned int num = 0;

    
    num = CountBits(Testdata);
    printf("%d",num);

    num = CountBits1(Testdata);
    printf ("  %d", num);
    return 0;

 }


//好的方法，通过移位来计算
 unsigned int CountBits(unsigned int  value)
 {
   unsigned int count = 0 ;

   for (; value ;value = value >> 1)
    if (value & 1 )
    {
      count ++;
    }
    return count;
 }

 /**
  * @description:自己做的方法 
  * @param {*}
  * @return {*}
  */
unsigned int CountBits1(unsigned int  value)

{
  int count = 0;

  while (value >0 )
  {
    if (value % 2 == 1 )
    {
      count ++;
    }
    value /= 2;
  }
  return count;
}