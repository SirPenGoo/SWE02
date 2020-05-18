#include "stdlib.h"
#include "Fifo.h"
#include "SList.h"

SLIST* put(SLIST_HEADER* p, void* data) {
	if (p == NULL)
		return NULL;
	if (data == NULL)
		return NULL;
	insertLast(p, data);
}

SLIST* get(SLIST_HEADER* p) {
	return(deleteFirst(p));
}

int length(SLIST_HEADER* p) {
	if (p == NULL)
		return -1;
	return p->Len;
}

SLIST* next(SLIST_HEADER* p) {
	return(get_entrySList(p, 1));
}

SLIST* last(SLIST_HEADER* p) {
	return(get_entrySList(p, p->Len));
}

int empty(SLIST_HEADER* p) {
	if (p->Len == 0)
		return 1;
	else
		return 0;
}

void delete(SLIST_HEADER* p) {
	rm_SList(p);
}