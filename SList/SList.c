#include "SList.h"
#include "stdlib.h"
#include "stdio.h"

extern SLIST_HEADER* createSList();			//creates new List
extern void insertFirst(SLIST_HEADER*, int*);//inserts element at front of List
extern SLIST* insertLast(SLIST_HEADER*, void*);	//inserts element at end of List
extern void* deleteFirst(SLIST_HEADER*);		//deletes first element of List
extern void* deleteLast(SLIST_HEADER*);			//deletes last element of List
extern void pr_SList(SLIST_HEADER*, FILE*);		//prints List
extern void rm_SList(SLIST_HEADER*);			//removes List
extern void* get_entrySList(SLIST_HEADER*, int);//gets List entry at Index

extern SLIST_HEADER* createSList() {
	SLIST_HEADER* tmp = (SLIST_HEADER*)malloc(sizeof(SLIST_HEADER));
	if(tmp == NULL)
	tmp->Len = 0;
	tmp->First = tmp->Last = NULL;
	return tmp;
}

extern void insertFirst(SLIST_HEADER*, int*) {

}