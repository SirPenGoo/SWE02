#pragma once
#ifndef FIFO_H
#define FIFO_H

SLIST* put(SLIST_HEADER* p, void* data);
SLIST* get(SLIST_HEADER* p);
int length(SLIST_HEADER* p);
SLIST* next(SLIST_HEADER* p);
SLIST* last(SLIST_HEADER* p);
int empty(SLIST_HEADER* p);
void delete(SLIST_HEADER* p);
#endif // !FIFO_H
