#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

/**
 * Property struct holding all data used for entire property list and favourites list
 */
typedef struct prop{
	int addrNum;
	char* addrName;
	int numRooms;
	int rentCost;
	float distance;
	struct prop *pNextProp;
} Property;

/**
 * Creates a single property node and allocates space for it
 */
Property* createPropertyNode();

/**
 * Pushes a new node to a given list 
 */
void pushNode(Property** ppHead, Property* pNewPropNode);

/**
 * Removes the given node from the given list
 */
void removeNode(Property** ppHead, int index);

/**
 * Gets node at the given index
 */
Property* getNodeAtIndex(Property *pHead, int index);

/**
 * Returns the number of items in a given list
 */
int getCount(Property* pHead);

#endif
