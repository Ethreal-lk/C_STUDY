/*
 * @Author: your name
 * @Date: 2021-06-28 15:46:08
 * @LastEditTime: 2021-06-29 17:10:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C\.vscode\DataStructure\Unit_1\StaticList.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 1000
typedef  int ElemType ;
typedef   int Status;
typedef struct {
  ElemType data;
  int cur;
}Component;
typedef Component* staticLinkList; 

Status InitList (staticLinkList space);
int    Malloc_SLL(staticLinkList space);
int    ListLength(staticLinkList L);
Status ListDelete (staticLinkList L , int i) ;
void   Free_SSL (staticLinkList space , int i);
void   Listadd(staticLinkList space );
Status ListInsert (staticLinkList L, int i, ElemType e);

int main() 
{
  Status flag ;
  int length;
  int i;
  Component array[MAXSIZE];



  flag = InitList(array);
  if (flag == 1)
  {
    printf("InitList Sucess!\n");
  }
  
  Listadd(array);
  flag = ListInsert(array, 8, 99);
  if (flag ==1 ) {
    printf("sucess!\n");  
  } 

  length = ListLength(array);
  printf("ListLength is %d\n", length);
  i = array[MAXSIZE].cur;
  while (i)
  {
    printf("%d \n", array[i].data);
    i = array[i].cur;
  }
  
}

// 初始化几个元素
void Listadd(staticLinkList space )
{
  int number;
  printf("Input the number of data:\n");
  scanf("%d",&number);
  for (int i = 1; i<=number; i++)
  {
    space[i].data = i;
  
  }
  space[0].cur = number + 1;
  space[number].cur = 0; 
  space[MAXSIZE].cur = 1;

}

// 链表初始化
Status InitList (staticLinkList space)
{
  int i;
  for (i = 0; i < MAXSIZE-1;i++)
  space[i].cur = i+1;
  space[MAXSIZE - 1].cur = 0;

  return 1;
  

}

// 若备用链表非空 ，则返回分配的节点下标，否则返回0
int Malloc_SLL(staticLinkList space) 
{
  int i = space[0].cur;
  if (space[0].cur)
  space[0].cur = space[i].cur;

  return i;
}

// 在L中第i个元素之前插入新的元素e

Status ListInsert (staticLinkList L, int i, ElemType e)
{
  int  j, k, l;
  k = MAXSIZE - 1;  // K是最后一个元素的下标 ，即第一数据的元素的下标
  if (i < 1 || i > ListLength (L) + 1)  //判断是否在插入范围内，如果不在返回error 
  return  0;

  j = Malloc_SLL (L);  //获得空闲分量的下标
  if ( j )
  {
    L[j].data = e;   // 将数据赋值给此分量的data;
    for (l = 1; i <= i-1; l++) //找到第 i个元素之前的位置
     k = L[k].cur;

     L[j].cur = L[k].cur; //把第 i个元素之前的cur赋值给新元素的cur
     L[k].cur = j;  //把新元素的下标赋值给元素之前的cur

     return 1; 
  }

  return 0;

}

Status ListDelete (staticLinkList L , int i) 
{
  int j, k;
  if (i < 1 || i > ListLength (L))
  return 0;
  k = MAXSIZE - 1 ;
  for (j = 1; j <= i - 1; j++) // 获取第 i 之前的下标
  k = L[k].cur;

  j = L[k].cur;    //将第i个删除的下标赋值 给j 
  L[k].cur = L[j].cur; //将第i个删除元素后面的下标赋值给删除元素之前的下标
  Free_SSL (L , j);
  return 1;

  

}


//获取L数据元素的长度

int ListLength(staticLinkList L)
{
  int length = 0;
  int i = L[MAXSIZE - 1].cur;

  while (i) {
    i = L[i].cur;
    length ++;
  } 

  return length ;
  
}
// 释放第i个元素
void  Free_SSL (staticLinkList space, int i)
{
  space[i].cur = space[0].cur; // 把第一个元素的cur复制给要删除的分量cur
  space[0].cur = i;

}