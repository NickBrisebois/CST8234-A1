#include<stdio.h>
#include<stdlib.h>
#include"node.h"
#include"rental.h"

Node* defineProperty(){
	Node* tempProp = createPropertyNode();
	Street streets[10] = {
		{randInt(100, 2000), "Magnolia Drive"},
		{randInt(100, 2000), "Garden Street"},
		{randInt(100, 2000), "Wood Street"},
		{randInt(100, 2000), "William Street"},
		{randInt(100, 2000), "Valley View Drive"},
		{randInt(100, 2000), "Fawn Lane"},
		{randInt(100, 2000), "Bayberry Drive"},
		{randInt(100, 2000), "Ridge Road"},
		{randInt(100, 2000), "Pinecrest Road"},
		{randInt(100, 2000), "Chandigarh Road"}
	};
	
	Street chosenStreet = streets[randInt(0,9)];

	tempProp->pRental->addrName = chosenStreet.streetName;
	tempProp->pRental->addrNum = randInt(1, 200);
	tempProp->pRental->numRooms = randInt(1, 4);
	tempProp->pRental->rentCost = (50 * randInt(4,12));
	tempProp->pRental->distance = (chosenStreet.baseDistance + tempProp->pRental->addrNum);
	return tempProp;
}

Node* generateProperties(int numProps){
	// The head of the linked list
	Node* pHead = defineProperty();
	for(int i = 0; i < numProps; i++){
		//pushNode defined in node.c
		pushNode(&pHead, defineProperty());
	}
	return pHead;
}

void addProperty(Node* pHead, Node* pProp){
	pushNode(&pHead, pProp);
}

void askOpinion(Node* pNode){
	if(pNode != NULL){
		float km = pNode->pRental->distance / 1000.00;
		printf("\n%s\n", "What do you think about this rental property?");
		printf("\tAddr: %d %s, # Rooms: %d, Rent/Room: $%d, Distance: %.2f km\n", pNode->pRental->addrNum, pNode->pRental->addrName, pNode->pRental->numRooms, pNode->pRental->rentCost, km);
	}else
		printf("\nNo more rental properties\n");
}
