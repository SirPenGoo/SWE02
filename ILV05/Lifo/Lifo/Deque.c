#include "stdlib.h"
#include "SList.h"
#include "Deque.h"

SLIST* insert_element_at_back(SLIST_HEADER* p, void* data) {
	if (p == NULL)
		return NULL;
	if (data == NULL)
		return NULL;
	insertLast(p, data);
}

void remove_element_at_back(SLIST_HEADER* p) {
	deleteLast(p);
}

SLIST* insert_element_at_front(SLIST_HEADER* p, void* data) {
	if (p == NULL)
		return NULL;
	if (data == NULL)
		return NULL;
	insertFirst(p, data);
}

void remove_element_at_front(SLIST_HEADER* p) {
	deleteFirst(p);
}

SLIST* get(SLIST_HEADER* p) {
	return(deleteFirst(p));
}

SLIST* examine_first_element(SLIST_HEADER* p) {
	return(get_entrySList(p, 0));
}

SLIST* examine_last_element(SLIST_HEADER* p) {
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