/*
 * @Author: your name
 * @Date: 2021-07-06 16:59:18
 * @LastEditTime: 2021-07-07 08:57:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C\.vscode\KATA_Practise\2_.C
 */

// The new "Avengers" movie has just been released! There are a lot of people at the cinema box office standing in a huge line. Each of them has a single 100, 50 or 25 dollar bill. An "Avengers" ticket costs 25 dollars.

// Vasya is currently working as a clerk. He wants to sell a ticket to every single person in this line.

// Can Vasya sell a ticket to every person and give change if he initially has no money and sells the tickets strictly in the order people queue?

// Return YES, if Vasya can sell a ticket to every person and give change with the bills he has at hand at that moment. Otherwise return NO.

// Examples:
// tickets(3, {25, 25, 50}) // => true
// tickets(2, {25, 100}) // => false. Vasya will not have enough money to give change to 100 dollars
// tickets(5, {25, 25, 50, 50, 100}) 

#include <stdlib.h>
#include <stdio.h>


int tickets(size_t length,  int people[length]);


int main() {

  int Length = 0;
  int people[] = {25, 25, 25, 100,25, 25, 100};
  Length = sizeof(people) / sizeof(people[0]);
  int flag ;
 flag =  tickets(Length, people);
if (flag == 1 )
{
  printf("true !");
}else 
 printf("false !");

}


int tickets(size_t length,  int people[length]) {
  
  int num25 = 0, num50  = 0, num100 = 0;
  for(size_t i = 0; i < length ; i++){
    if(people[i] == 25) 
    num25++;
    
    else if(people[i] == 50) {
      num50++;
      num25--;
      if (num25 < 0) 
      return 0;
    } else if( people[i] == 100) {

        if (num25 >= 1) { 
          if(num50 >= 1) {
            num25-- ;
            num50--;
            continue;
          } 
          if (num25 >= 3)
          {
            num25 -= 3;
            continue ;
          }
          return 0; 
        }
        else return 0;
    }
  }
          return 1;
  }