#ifndef SORT_H_DEFINED
#define SORT_H_DEFINED

void sortByDistance(Node** ppProps);
void sortByRent(Node** ppProps);
void sortByAddress(Node** ppProps);
void sortByRooms(Node** ppProps);
int compareByRent(Node* pPropOne, Node* pPropTwo);
int compareByDistance(Node* pPropOne, Node* pPropTwo);
int compareByAddress(Node* pPropOne, Node* pPropTwo);
int compareByRooms(Node* pPropOne, Node* pPropTwo);
void swap(Node** pPropOne, Node** pPropTwo);

#endif
