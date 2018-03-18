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
	Node* tempNode = *ppHead;
	if(tempNode == NULL){
		*ppHead = pNewPropNode;
	}else{
		while(tempNode->pNext != NULL){
			tempNode = tempNode->pNext;
		}
		tempNode->pNext = pNewPropNode;
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

Node* removeNode(Node** ppHead, int i){
	Node* toRemove = getNodeAtIndex(*ppHead, i);
	if(toRemove != NULL){
		if(getCount(*ppHead) > 0){
			if(i > 0){
				Node* prevNode = getNodeAtIndex(*ppHead, i-1);
				prevNode->pNext = toRemove->pNext;
				toRemove->pNext = NULL;
			}else {
				*ppHead = toRemove->pNext;
				toRemove->pNext = NULL;
			}
		}
	}
	return toRemove;
}

int getCount(Node* pHead){
	int count = 0;
	while(pHead != NULL){
		count++;
		pHead = pHead->pNext;
	}
	return count;
}
