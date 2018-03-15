#ifndef RENTAL_H_DEFINED
#define RENTAL_H_DEFINED

/**
 * Holds the base distance of a street from the college and the street's name
 */
typedef struct street {
	int baseDistance;
	char* streetName;
} Street;

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

/*
 * Generate a random int between two given numbers
 */
int randInt(int min, int max);

void printReadable();


#endif
