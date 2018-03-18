#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

typedef struct _Node{
	struct prop* pRental;
	struct _Node* pNext;
} Node;

/**
 * Creates a single property node and allocates space for it
 */
Node* createPropertyNode();

/**
 * Pushes a new node to a given list 
 */
void pushNode(Node** ppHead, Node* pNewPropNode);

/**
 * Insert a node into a given list at the given index
 */
void insertAtIndex(Node** ppHead, Node pNewPropNode, int i);

/**
 * Removes the given node from the given list
 */
Node* removeNode(Node** ppHead, int i);

/**
 * Gets node at the given index
 */
Node* getNodeAtIndex(Node *pHead, int i);

/**
 * Returns the number of items in a given list
 */
int getCount(Node* pHead);

#endif
