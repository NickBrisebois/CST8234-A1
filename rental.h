#ifndef RENTAL_H_DEFINED
#define RENTAL_H_DEFINED

/**
 * Property struct holding all data used for entire property list and favourites list
 */
typedef struct prop{
	int addrNum;
	char* addrName;
	int numRooms;
	int rentCost;
	float distance;
} Property;

/**
 * Holds the base distance of a street from the college and the street's name
 */
typedef struct street {
	int baseDistance;
	char* streetName;
} Street;

/**
 * Returns a randomly generated property node to be used to add to a linked list
 */
struct _Node* defineProperty();

/**
 * Generates numProps amount of properties using defineProperty() and returns the head
 */
struct _Node* generateProperties(int numProps);

#endif
