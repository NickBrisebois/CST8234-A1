#ifndef SORT_H_DEFINED
#define SORT_H_DEFINED

/**
 * Sort given list by distance
 */
void sortByDistance(Node** ppProps);

/**
 * Sort given list by rent
 */
void sortByRent(Node** ppProps);

/**
 * Sort given list by address
 */
void sortByAddress(Node** ppProps);

/**
 * Sort given list by rooms 
 */
void sortByRooms(Node** ppProps);

/**
 * Compare properties by rent
 */
int compareByRent(Node* pPropOne, Node* pPropTwo);

/**
 * Compare properties by distance
 */
int compareByDistance(Node* pPropOne, Node* pPropTwo);

/**
 * Compare properties by address
 */
int compareByAddress(Node* pPropOne, Node* pPropTwo);

/**
 * Compare properties by rooms
 */
int compareByRooms(Node* pPropOne, Node* pPropTwo);

/**
 * Swap the two given properties
 */
void swap(Node** pPropOne, Node** pPropTwo);

#endif
