#include<stdio.h>
#include<stdlib.h>
#include"rental.h"
#include"node.h"

Node* createPropertyNode(){
	Node* pPropNode = calloc(1, sizeof(Node));
	pPropNode->pRental = calloc(1, sizeof(Property));
	return pPropNode;
}

void pushNode(Node** ppHead, Node* pNewPropNode){
	if(*ppHead == NULL){
		*ppHead = pNewPropNode;
	}else{
		Node* pPropNode = *ppHead;
		while(pPropNode->pNext != NULL)
			pPropNode = pPropNode->pNext;
		pPropNode->pNext = pNewPropNode;
	}
	pNewPropNode->pNext = NULL;
}

Node* getNodeAtIndex(Node* pHead, int i){
	for(int j = 0; (j < i); j++){
		if(j == i)
			break;
		if(pHead != NULL)
			pHead = pHead->pNext;
	}
	return pHead;
}

void removeNode(Node** ppHead, int i){
	Node* toRemove = getNodeAtIndex(*ppHead, i);
	Node* prevNode = getNodeAtIndex(*ppHead, i-1);
	if(getCount(*ppHead) > 0){
		if(i > 0){
			prevNode->pNext = toRemove->pNext;
		}else {
			*ppHead = toRemove->pNext;
		}
	}
}

int getCount(Node* pHead){
	int count = 0;
	while(pHead != NULL){
		count++;
		pHead = pHead->pNext;
	}
	return count;
}
