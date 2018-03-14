#ifndef RENTAL_H_DEFINED
#define RENTAL_H_DEFINED

/*
 * Returns a randomly generated property node to be used to add to a linked list
 */
Property* defineProperty();

/*
 * Generates numProps amount of properties using defineProperty() and returns the head
 */
Property* generateProperties(int numProps);

/*
 * Add a new property to the given list
 */
void addProperty(Property* pHead);

#endif
