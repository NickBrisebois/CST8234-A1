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
