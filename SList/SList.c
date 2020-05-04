/*==========================================================
|	Assignment:		SWE02_HUE04FO
|	File:			SList.c
|	Author:			Maximilian Erlmoser
|	University:		FH Salzburg
|	Semester:		ITS-B SS20
|	Date:			03.05.2020
|-----------------------------------------
|	Description:	Double linked list functions
*=========================================================*/


#include "SList.h"
#include "stdlib.h"
#include "stdio.h"

extern SLIST_HEADER* createSList();			//creates new List
extern SLIST* insertFirst(SLIST_HEADER*, void*);//inserts element at front of List
extern SLIST* insertLast(SLIST_HEADER*, void*);	//inserts element at end of List
extern void* deleteFirst(SLIST_HEADER*);		//deletes first element of List
extern void* deleteLast(SLIST_HEADER*);			//deletes last element of List
extern void pr_SList(SLIST_HEADER*, FILE*);		//prints List
extern void rm_SList(SLIST_HEADER*);			//removes List
extern void* get_entrySList(SLIST_HEADER*, int);//gets List entry at Index

extern SLIST_HEADER* createSList() {
	SLIST_HEADER* tmp = (SLIST_HEADER*)malloc(sizeof(SLIST_HEADER));
	if (tmp == NULL) {
		perror("Speicherfehler");
		return NULL;
	}
	tmp->Len = 0;
	tmp->First = tmp->Last = NULL;
	return tmp;
}

extern SLIST* insertFirst(SLIST_HEADER* list, void* newData) {
	SLIST* newElement;
	if ((newElement = (SLIST*)malloc(sizeof(SLIST))) != NULL)
	{
		newElement->Data = newData;
		newElement->Next = newElement;
		list->First = newElement;
		if (list->Len == 0)
			list->Last = newElement;

		list->Len++;
	}
	return newElement;
}

extern SLIST* insertLast(SLIST_HEADER* list, void* newData){
	SLIST* newElement;
	if ((newElement = (SLIST*)malloc(sizeof(SLIST))) != NULL)
	{
		newElement->Data = newData;
		newElement->Next = newElement;

		if (list->Len != 0)
			list->Last->Next = newElement;
		else
			list->First = newElement;

		list->Last = newElement;
		list->Len++;

	}
	return newElement;
}

extern void* deleteFirst(SLIST_HEADER* list) {
	SLIST* tmp;
	void* data;

	if (list->Len > 0)
	{
		tmp = list->First;
		data = tmp->Data;

		list->First = tmp->Next;
		list->Len--;

		if (list->Len == 0)
			list->Last = (SLIST*)NULL;

		free((void*)tmp);
	}
}
extern void* deleteLast(SLIST_HEADER* list) {
	SLIST* tmp;
	SLIST* help;
	void* data;
	int i;

	if (list->Len > 0)
	{
		tmp = list->Last;
		data = tmp->Data;

		help = list->First;
		list->Last = help;
		for (i = 0; i < list->Len - 1; i++) {
			list->Last = help;
			help = help->Next;
		}
		list->Len--;

		if (list->Len == 0)
		{
			list->Last = (SLIST*)NULL;
			list->First = (SLIST*)NULL;
		}
		free((void*)tmp);
	}

}
extern void pr_SList(SLIST_HEADER*list, FILE* out) {
	SLIST* currentElement = list->First;

	for (int i = 1; i <= list->Len; i++) {
		fprintf(out, "%6d\t%s\n", i, (char*)currentElement->Data);
		out = currentElement->Next;
	}
}

extern void rm_SList(SLIST_HEADER* list) {
	{
		while (list->Len)
			deleteLast(list);

		free(list);
	}

}
extern void* get_entrySList(SLIST_HEADER* list, int index) {
	if (index >= 1 && index <= list->Len)
	{
		SLIST* node;

		node = list->First;
		for (int i = 1; i < index; i++)
			node = node->Next;
		return(node->Data);
	}
	else
		return((char*)NULL);
}