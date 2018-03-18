#include<stdlib.h>
#include<stdio.h>
#include<string.h>
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
			if(compareByDistance(pTempOne, pTempTwo) > 0)
				swap(&pTempOne, &pTempTwo);
		}
	}
}

void sortByRent(Node** ppProps){
	Node* pTempOne = calloc(1, sizeof(Node));
	Node* pTempTwo = calloc(1, sizeof(Node));
	int listSize = getCount(*ppProps);

	for(int i=0; i<listSize-1; i++){
		for(int j=0; j<listSize-1; j++){
			pTempOne = getNodeAtIndex(*ppProps, j);
			pTempTwo = getNodeAtIndex(*ppProps, j+1);
			if(compareByRent(pTempOne, pTempTwo) > 0)
				swap(&pTempOne, &pTempTwo);
		}
	}
}

void sortByRooms(Node** ppProps){
	Node* pTempOne = calloc(1, sizeof(Node));
	Node* pTempTwo = calloc(1, sizeof(Node));
	int listSize = getCount(*ppProps);

	for(int i=0; i<listSize-1; i++){
		for(int j=0; j<listSize-1; j++){
			pTempOne = getNodeAtIndex(*ppProps, j);
			pTempTwo = getNodeAtIndex(*ppProps, j+1);
			if(compareByRooms(pTempOne, pTempTwo) < 0)
				swap(&pTempOne, &pTempTwo);
		}
	}
}

void sortByAddress(Node** ppProps){
	Node* pTempOne = calloc(1, sizeof(Node));
	Node* pTempTwo = calloc(1, sizeof(Node));
	int listSize = getCount(*ppProps);

	for(int i=0; i<listSize-1; i++){
		for(int j=0; j<listSize-1; j++){
			pTempOne = getNodeAtIndex(*ppProps, j);
			pTempTwo = getNodeAtIndex(*ppProps, j+1);
			if(compareByAddress(pTempOne, pTempTwo) > 0)
				swap(&pTempOne, &pTempTwo);
			pTempTwo = pTempTwo->pNext;
		}
		pTempOne = pTempOne->pNext;
	}
}

int compareByRent(Node* pPropOne, Node* pPropTwo){
	int diff = pPropOne->pRental->rentCost - pPropTwo->pRental->rentCost;
	if(diff == 0)
		diff = pPropOne->pRental->numRooms - pPropTwo->pRental->numRooms;
	return diff;
}

int compareByDistance(Node* pPropOne, Node* pPropTwo){
	int diff = pPropOne->pRental->distance - pPropTwo->pRental->distance;
	if(diff == 0)
		diff = pPropOne->pRental->rentCost - pPropTwo->pRental->rentCost;
	return diff;
}

int compareByAddress(Node* pPropOne, Node* pPropTwo){
	int diff = strcmp(pPropOne->pRental->addrName, pPropTwo->pRental->addrName);
	if(diff == 0)
		diff = pPropOne->pRental->addrNum - pPropTwo->pRental->addrNum;
	return diff;
}

int compareByRooms(Node* pPropOne, Node* pPropTwo){
	int diff = pPropOne->pRental->numRooms - pPropTwo->pRental->numRooms;
	if(diff == 0)
		diff = pPropTwo->pRental->rentCost - pPropOne->pRental->rentCost;
	return diff;
}

void swap(Node** pPropOne, Node** pPropTwo){
	Node temp = **pPropOne;
	(*pPropOne)->pRental = (*pPropTwo)->pRental;
	(**pPropTwo).pRental = temp.pRental;
}
