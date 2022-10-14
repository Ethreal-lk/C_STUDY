#ifndef _DLIST_H_
#define _DLIST_H_
#include <stdlib.h>

#define ERROR	-1
#define SUCESS  0

typedef struct DlistElmt{
	void		*data;
	struct		DlistElmt * prev;
	struct		DlistElmt * next;
}DlistElmt;
typedef struct Dlist_ {
	int			size;
	int			(*match)(const void *key1, const void *key2);
	void		(*destry) (void *data);
	DlistElmt	*head;
	DlistElmt	*tail;
}Dlist;
void dlist_init(Dlist *list, void(*destry)(void *data));
//void dlis_destry(Dlist * list);
int  dlist_ins_next(Dlist *list, DlistElmt *element, const void *data);
int  dlist_ins_prev(Dlist *list, DlistElmt *element, const void *data);
int  dlist_remove(Dlist *list, DlistElmt *element, void **data);

#define dlist_size(list)  ((list)->size)
#define dlist_head(list)  ((list)->head)
#define dlist_tail(list)  ((list)->tail)

#endif