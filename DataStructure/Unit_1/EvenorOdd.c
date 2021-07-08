/*
 * @Author: your name
 * @Date: 2021-06-30 10:48:12
 * @LastEditTime: 2021-07-01 11:59:59
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C\.vscode\DataStructure\Unit_1\Vote.c
 */

#include <stdio.h>
#include <stddef.h>

const char *even_or_odd(const char *digits);
const char *even_or_odd1(const char *digits);
int main()
{
  const char *p = even_or_odd("1524");
  printf ("%d\n",p);
  printf("%s\n",p);
  p = even_or_odd1("1526");
  printf ("%d\n",p);
  printf("%s\n",p);

}

// own method
const char *even_or_odd(const char *digits) {

    int SumEven = 0, SumOdd = 0;
    while (*digits != '\0')
    {
      if (*digits % 2 == 0)
      {
        SumEven += (*digits -'0');
      } else {
        SumOdd += (*digits-'0');
      }
      digits++;
    }
    if (SumOdd == SumEven) {

    return "Even and Odd are the same";
    } else

    return SumOdd > SumEven ? "Odd is greater than Even" : "Even is greater than Odd";

}


//The most suitable method
const char *even_or_odd1(const char *digits)
{
  int sum = 0;
  
  for (char *p = (char *)digits; *p; p++)
    sum += (*p % 2 ? 1 : -1) * (*p - '0');

  return  sum < 0 ? "Even is greater than Odd" : 
          sum > 0 ? "Odd is greater than Even" :
                    "Even and Odd are the same";
}