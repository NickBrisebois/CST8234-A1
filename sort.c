#include<stdlib.h>
#include<stdio.h>
#include"node.h"
#include"rental.h"
#include"sort.h"

void sortByDistance(Node** ppProps){
	Node* pTempOne = calloc(1, sizeof(Node));
	Node* pTempTwo = calloc(1, sizeof(Node));
	int listSize = getCount(*ppProps);

	for(int i=0; i<listSize-1; i++){
		for(int j=0; j<listSize-1; j++){
			pTempOne = getNodeAtIndex(*ppProps, j);
			pTempTwo = getNodeAtIndex(*ppProps, j+1);
			if(pTempOne->pRental->distance > pTempTwo->pRental->distance){
				swap(&pTempOne, &pTempTwo);
			}
			pTempTwo = pTempTwo->pNext;
		}
		pTempOne = pTempOne->pNext;
	}
}

void swap(Node** pPropOne, Node** pPropTwo){
	Node temp = **pPropOne;
	(*pPropOne)->pRental = (*pPropTwo)->pRental;
	(**pPropTwo).pRental = temp.pRental;
}
