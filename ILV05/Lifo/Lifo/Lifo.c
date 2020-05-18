#include "stdlib.h"
#include "Lifo.h"
#include "SList.h"

SLIST* push(SLIST_HEADER* p, void* data) {
	if (p == NULL)
		return NULL;
	if (data == NULL)
		return NULL;
	insertFirst(p, data);
}

SLIST* pop(SLIST_HEADER* p) {
	return(deleteFirst(p));
}

int length(SLIST_HEADER* p) {
	if (p == NULL)
		return -1;
	return p->Len;
}

SLIST* top(SLIST_HEADER* p) {
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