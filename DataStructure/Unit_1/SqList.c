/*
 * @Author: your name
 * @Date: 2021-06-28 13:51:45
 * @LastEditTime: 2021-06-28 15:30:37
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C\.vscode\DataStructure\Unit_1\SqList.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Element;
typedef int Status;
#define error 0;
#define true 1
typedef struct Node {
	Element data;
  struct Node * next;
}Node;
typedef struct Node* LinkList;   //定义LinkLList
LinkList CreateListHead(LinkList L , int n);
LinkList CreateListTail(LinkList L ,int n);



int main()
{
	printf("This is a sqlist!\n");

  LinkList L = NULL;
  LinkList q;
  int  n = 5;
  int i;

  q = CreateListTail(L, n);
  while (q->next != NULL)
  {
    q = q->next;
    printf("the number is %d\n", q->data);
  }
  
	getchar();

	return 0;
}

// 头插法
LinkList  CreateListHead(LinkList L , int n)
{
  LinkList p;
  int i;
  srand(time(0));

  L = (LinkList)malloc (sizeof (Node));
  L->next = NULL;

  for ( i = 0; i < n; i++)
  {
    p = (LinkList) malloc (sizeof (Node));
    p->data = rand() % 100 + 1;
    p->next = L->next;
    L->next = p;
    
  }
  return L;
  
}

// 尾插法
LinkList CreateListTail(LinkList L ,int n) {
  LinkList p , r;

  int i;
  srand(time(0));


  L = (LinkList)malloc(sizeof (Node));
  r = L ;

  for (i = 0; i < n; i++ ) { 

    p = (LinkList)malloc( sizeof (Node) );
    p->data = rand() % 100 + 1;
    r->next = p;
    r = p;
  }
  r->next = NULL;
  

  return L;

}
