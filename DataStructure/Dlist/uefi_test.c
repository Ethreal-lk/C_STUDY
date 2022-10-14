#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include <string.h>

#define LIST_LENGTH 10
void dlist_init(Dlist *list, void(*destry)(void *data)) {
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->destry = destry;
	return;
}
//void dlis_destry(Dlist * list) {
//	void *data;
//}
int  dlist_remove(Dlist *list, DlistElmt *element, void **data) {
	if (element == NULL && dlist_size(list) == 0) {
		return ERROR;
	}
	*data = element->data;
	if (element == list->head) {
		list->head = element->next;
		if (list->head == NULL) {
			list->tail = NULL;
		}
		else {
			element->next->prev = NULL;
		}
	}
	else {
		element->prev->next = element->next;
		if (element->next == NULL) {
			list->tail = element->prev;
		}
		else {
			element->next->prev = element->prev;
		}
	}
	free(element);
	list->size--;
	return SUCESS;
}

int  dlist_ins_next(Dlist *list, DlistElmt *element, const void *data) {
	DlistElmt *NewElement;

	if (element == NULL && dlist_size(list) != 0){
		return -1;
	}
	NewElement = (DlistElmt*)malloc(sizeof(DlistElmt));
	if (NewElement == NULL) {
		return -1;
	}
	NewElement->data = (void *)data;
	if (dlist_size(list) == 0) {
		list->head = NewElement;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->tail = NewElement;
		
	}
	else {
		NewElement->next = element->next;
		NewElement->prev = element;
		if (element->next ==  NULL)
		{
			list->tail = NewElement;
		}
		else {
			element->next->prev = NewElement;
		}
		element->next = NewElement;
	}
	list->size++;
	return SUCESS;
}
int  dlist_ins_prev(Dlist *list, DlistElmt *element, const void *data)
{
	return SUCESS;
}
int main() {
	Dlist *dlist;
	DlistElmt * ElemPtr;
	int *temp = NULL;
	int state;
	int data[10] = { 0,1,2,3,4,5,6,7,8,9 };
	dlist = (Dlist*)malloc(sizeof(Dlist));
	if (dlist == NULL)
	{
		printf("memeory malloc fail!\n");
		return  ERROR;
	}
	dlist_init(dlist, NULL);
	for (int i = 0; i < LIST_LENGTH; i++) {
		state = dlist_ins_next(dlist, dlist->tail, (const void *)&data[i]);
		printf("state is %d", state);
		printf("dlist->size = %d  dlist->tail = %p dlist->tail->data = %d \n", \
			dlist->size, dlist->tail, *((int *)dlist->tail->data));

	}
	ElemPtr = dlist->tail;
	while (ElemPtr != NULL) {
		printf("ElemPtr->data = %d", *((int *)ElemPtr->data));
		printf("	ElemPtr address = %p\n", ElemPtr);
		ElemPtr = ElemPtr->prev;
	}
	printf("dlist->tail = %p\n", dlist->tail);
	state = dlist_remove(dlist, dlist->tail, (void **)&temp);
	printf("temp = %d", *temp);
	system("pause");
	return 0;

}