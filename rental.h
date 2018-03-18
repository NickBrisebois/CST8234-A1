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

/**
 * Prints all properties in the given linked list
 */
void printProperties(struct _Node* pRentalsHead);

/**
 * Prints the top tabs for printProperties
 */
void printTabs();

/**
 * Get users's opinion the the property at the head of the given list
 */
void askOpinion(struct _Node* pNode);

#endif
