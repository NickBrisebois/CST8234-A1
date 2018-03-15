#include<stdio.h>
#include<stdlib.h>
#include"node.h"

Property* createPropertyNode(){
	Property* pPropNode = calloc(1, sizeof(Property));
	return pPropNode;
}

void pushNode(Property** ppHead, Property* pNewPropNode){
	if(*ppHead == NULL)
		*ppHead = pNewPropNode;
	else{
		Property* pPropNode = *ppHead;
		while(pPropNode->pNextProp != NULL)
			pPropNode = pPropNode->pNextProp;
		pPropNode->pNextProp = pNewPropNode;
	}
	pNewPropNode->pNextProp = NULL;
}

Property* getNodeAtIndex(Property* pHead, int index){
	int listCount = getCount(pHead);
	index = (index <= listCount) ? index : listCount;
	for(int i = 0; (i < index); i++){
		if(i == index)
			return pHead;
		pHead = pHead->pNextProp;
	}
	return pHead;
}

void removeNode(Property** ppHead, int index){
	Property* toRemove = getNodeAtIndex(*ppHead, index);
	printf("%d", toRemove->rentCost);
}

int getCount(Property* pHead){
	int count = 0;
	while(pHead != NULL){
		count++;
		pHead = pHead->pNextProp;
	}
	return count;
}
