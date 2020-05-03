/*==========================================================
|	Assignment:		SWE02_HUE04FO
|	File:			SList.h
|	Author:			Maximilian Erlmoser
|	University:		FH Salzburg
|	Semester:		ITS-B SS20
|	Date:			03.05.2020
|-----------------------------------------
|	Description:	Header for double linked List functions
*=========================================================*/


#ifndef SLIST_H
#define SLIST_H

/* -- SLIST Knoten */
struct SList {
	int* Data;
	struct SList* Next;
	struct SList* Prev;
};
typedef struct SList SLIST;
/* -- Ein Kopf-Knoten, der die Listenlaenge enthaelt */
struct SList_Header {
	int Len;
	SLIST* First, * Last;
};
typedef struct SList_Header SLIST_HEADER;
extern SLIST_HEADER* createSList(void);			//creates new List
extern SLIST* insertFirst(SLIST_HEADER*, void*);//inserts element at front of List
extern SLIST* insertLast(SLIST_HEADER*, void*);	//inserts element at end of List
extern void* deleteFirst(SLIST_HEADER*);		//deletes first element of List
extern void* deleteLast(SLIST_HEADER*);			//deletes last element of List
extern void pr_SList(SLIST_HEADER*, FILE*);		//prints List
extern void rm_SList(SLIST_HEADER*);			//removes List
extern void* get_entrySList(SLIST_HEADER*, int);//gets List entry at Index


#endif // !SLIST_H