#pragma once

#ifndef DEQUE_H
#define DEQUE_H

SLIST* insert_element_at_back(SLIST_HEADER* p, void* data);
void remove_element_at_back(SLIST_HEADER* p);
SLIST* insert_element_at_front(SLIST_HEADER* p, void* data);
void remove_element_at_front(SLIST_HEADER* p);
SLIST* get(SLIST_HEADER* p);
SLIST* examine_first_element(SLIST_HEADER* p);
SLIST* examine_last_element(SLIST_HEADER* p);
int empty(SLIST_HEADER* p);
void delete(SLIST_HEADER* p);

#endif // !DEQUE_H
