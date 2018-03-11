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
 * Declare functions used in node.c
 */
Property* createPropertyNode();
void pushNode(Property** ppHead, Property* pNewPropNode);

#endif
