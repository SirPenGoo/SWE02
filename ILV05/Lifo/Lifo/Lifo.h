#pragma once
#ifndef LIFO_H
#define LIFO_H

extern SLIST* push(SLIST_HEADER* p, void* data);
extern SLIST* pop(SLIST_HEADER* p);
extern int length(SLIST_HEADER* p);
extern SLIST* top(SLIST_HEADER* p);
extern int empty(SLIST_HEADER* p);
extern void delete(SLIST_HEADER* p);
#endif // !LIFO_H

